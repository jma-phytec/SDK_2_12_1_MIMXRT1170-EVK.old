/*
 * Copyright 2018-2022 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

/*!
 * @file    eap.c
 * @brief  This file contains the implementation for the Eap integration
 */

#include <string.h>

#include "eap.h"
#include "pipeline.h"
#include "streamer_element_properties.h"

/*!
 * @param pad: pad handle
 * @param active: boolean activate/disactivate pad
 *
 * @brief This function activates the pad and allocates
 * memory for the Eap element.
 *
 * @returns true/false
 * @retval   true success
 * @retval   false failed
 */
static uint8_t eap_sink_pad_activation_handler(StreamPad *pad, uint8_t active)
{
    uint8_t ret = true;
    ElementEap *eap_element;
    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == pad, false);

    /* get the parent element from the pad */
    eap_element = (ElementEap *)PAD_PARENT(pad);

    STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]Activate pad: %d\n", active);

    if (true == ret)
    {
        /* Activate/Deactivate peer source pads in PUSH mode */
        eap_element->current_index = 0;
        ret                        = pad_activate_push(pad->peer, active);
    }

    if (ret != true)
    {
        STREAMER_LOG_DEBUG(DBG_EAP, "[Eap SINK]Activetion pad returns: %d\n", ret);
    }
    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @param pad: pad handle
 * @param buf: input buffer
 *
 * @brief This pad function takes data from the source element and
 * pushes it onto the EAP library.
 *
 * @returns FlowReturn
 * @retval FLOW_OK success
 * @retval FLOW_UNEXPECTED bad paramesters
 * @retval FLOW_ERROR write failed
 */

static FlowReturn eap_sink_pad_chain_handler(StreamPad *pad, StreamBuffer *buf)
{
    ElementEap *eap_element = NULL;
    FlowReturn ret          = FLOW_OK;
    uint32_t pkt_hdr_size   = 0, raw_data_size;
    int8_t *data_ptr;
    // char dummy_arg;
    int eap_ret;
    AudioPacketHeader *data_packet = NULL;
    uint32_t sample_rate;
    uint32_t channels;
    uint32_t chunk_size;
    ext_proc_args *args;
    StreamPad *src_pad = NULL;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS((NULL == pad) || (NULL == buf), FLOW_UNEXPECTED);

    /* get the parent element from the pad */
    eap_element = (ElementEap *)PAD_PARENT(pad);
    src_pad     = ELEMENT_SRC_PAD(eap_element, 0);

    CHK_ARGS((((RawPacketHeader *)(buf->buffer))->id != AUDIO_DATA), FLOW_NOT_SUPPORTED);

    /* check what data packet header the buffer has and typecast accordingly to
     * store the appropriate data
     */
    pkt_hdr_size = sizeof(AudioPacketHeader);
    data_packet  = (AudioPacketHeader *)BUFFER_PTR(buf);
    chunk_size   = AUDIO_CHUNK_SIZE(data_packet);
    sample_rate  = AUDIO_SAMPLE_RATE(data_packet);
    channels     = AUDIO_NUM_CHANNELS(data_packet);

    /* buf->size is the total buffer size including the packet header
     * Get the raw data size considering the offset as offset into raw data
     * from which data has to be written.
     */
    raw_data_size = buf->size - pkt_hdr_size;

    STREAMER_LOG_DEBUG(DBG_EAP, "\traw_data_size = %d\n", raw_data_size);
    STREAMER_LOG_DEBUG(DBG_EAP, "\tbuf->offset = %d\n", buf->offset);
    STREAMER_LOG_DEBUG(DBG_EAP, "\tpkt_hdr_size = %d\n", pkt_hdr_size);

    data_ptr = (buf->buffer + pkt_hdr_size);
    STREAMER_LOG_DEBUG(DBG_EAP, "\tdata_ptr = %X\n", (uint32_t)data_ptr);
    STREAMER_LOG_DEBUG(DBG_EAP, "\tcurrent_index = %d\n", eap_element->current_index);

    /* Need to call init here too
     * because of function pointers, cant call it in element init part
     */

    if (eap_element->initialized == false)
    {
        // check we have non NULL init function pointer
        if (eap_element->init_func == NULL)
        {
            STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]init function pointer not initialized!");
            return FLOW_BAD_PARAMETER;
        }
        // check this is correctly writen
        args = eap_element->arg_ptr;
        if (args != NULL)
        {
            if (sample_rate)
            {
                args->sample_rate = sample_rate;
            }
            if (channels)
            {
                args->num_channels = channels;
            }
        }

        eap_ret = eap_element->init_func(args);
        if (eap_ret != 0)
        {
            STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]EAP init error: %d\n", eap_ret);
            return FLOW_BAD_PARAMETER;
        }
        else
        {
            eap_element->initialized = true;
        }
    }

    /* Call the process function pointer */
    if (eap_element->proc_func == NULL)
    {
        STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]Process function pointer not initialized!");
        return FLOW_ERROR;
    }
    eap_ret = eap_element->proc_func(&channels, (long *)data_ptr, chunk_size);
    if (eap_ret != 0)
    {
        STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]EAP Execute: %d\n", eap_ret);
        ret = FLOW_ERROR;
        goto ERR;
    }
    else
    { /* Set the chunk size and num channels to align with crossover */
        args = eap_element->arg_ptr;
        if (args != NULL)
        {
            if (args->xo_enabled == true)
            {
                if (args->num_channels == 1)
                {
                    AUDIO_CHUNK_SIZE(data_packet)   = 2 * chunk_size;
                    AUDIO_NUM_CHANNELS(data_packet) = 2;
                    buf->size                       = AUDIO_CHUNK_SIZE(data_packet) + pkt_hdr_size;
                }
            }
        }
    }
    // try to push it to next pad
    // put buffer in proper packet type
    ret = pad_push(src_pad, buf);
    if (FLOW_OK != ret)
    {
        STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]EAP pad push: %d\n", ret);
        goto ERR;
    }

ERR:
    if (FLOW_OK != ret)
    {
        /* Post EOS message to the pipeline message queue here */
        send_msg_element(PAD_PARENT_ELEMENT(pad), MSG_EOS, 0);
        STREAMER_LOG_DEBUG(DBG_EAP, "[Eap]EAP sink pad flow: %d\n", ret);
    }
    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @param pad: pad handle
 * @param event: event enumeration
 *
 * @brief This function processes the pad events
 *
 * @returns true/false
 * @retval true success
 * @retval false failed
 */

static uint8_t eap_sink_pad_event_handler(StreamPad *pad, StreamEvent *event)
{
    uint8_t ret         = true;
    ElementEap *element = NULL;
    StreamPad *peer     = NULL;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == pad, false);

    /* get the parent element from the pad */
    element = PAD_PARENT(pad);
    CHK_ARGS(NULL == element, false);

    peer = ELEMENT_SRC_PAD(element, 0);
    CHK_ARGS(NULL == peer, false);

    peer = PAD_PEER(peer);
    CHK_ARGS(NULL == peer, false);

    /* Device driver type */

    STREAMER_LOG_DEBUG(DBG_EAP, "Event [EAP]: %d\n", EVENT_TYPE(event) >> 4);

    if (true == ret)
    {
        /* handle the event */
        switch (EVENT_TYPE(event))
        {
            case EVENT_EOS:
                /* Post EOS message to the pipeline message queue here */
                send_msg_element(PAD_PARENT_ELEMENT(pad), MSG_EOS, 0);
                break;

            case EVENT_FLUSH_START:
                /* In case the current state is paused then unblock the pad
                 * signal. Chain function should also check the flushing
                 * flag once it comes out from a wait on the signal to
                 * handle this scenario.
                 */
                break;
            case EVENT_FLUSH_STOP:
                break;
            case EVENT_NEWSEGMENT:
                ret = pad_send_event(peer, event);
                break;
            default:
                ret = pad_send_event(pad, event);
                break;
        }
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @param element_ptr: element
 * @param new_state: eap state to be changed
 *
 * @brief This function changes the EAP state and calls
 * the appropriate apis for that state and takes the actions and then returns.
 * PipelineState Transition:
 *      NULL to READY: Nothing to do
 *      READY to PAUSE: Activate sink pads and their peer pads
 *      PAUSE to PLAY: Start Writing
 *      PAUSE to READY: Deactivate sink pads and their peer pads
 *      READY to NULL: Nothing to do
 *
 * @returns StreamReturnType
 * @retval STREAM_OK success
 * @retval STREAM_ERR_INVALID_ARGS invalid arguments
 *
 */
static int32_t eap_change_state(StreamElement *element_ptr, PipelineState new_state)
{
    PipelineStateChange state_change;
    ElementEap *eap_ptr = (ElementEap *)element_ptr;
    int32_t ret         = STREAM_OK;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == eap_ptr, STREAM_ERR_INVALID_ARGS);

    /* get the transition status with the new passed state and the existing
     * state of the element
     */
    state_change = (PipelineStateChange)STATE_TRANSITION(eap_ptr->state, new_state);

    eap_ptr->state = new_state;
    switch (state_change)
    {
        case STATE_CHANGE_NULL_TO_READY:
            STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]STATE_CHANGE_NULL_TO_READY\n");
            /* Nothing to do here for a EAP */
            break;

        case STATE_CHANGE_PAUSED_TO_PLAYING:
            STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]STATE_CHANGE_PAUSED_TO_PLAYING\n");
            break;

        case STATE_CHANGE_READY_TO_NULL:
            STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]STATE_CHANGE_READY_TO_NULL\n");
            /* Nothing to do here for a EAP */
            break;

            /* When going to pause state then set the pad to blocked state so
             * that data flow is blocked.
             */
        case STATE_CHANGE_READY_TO_PAUSED:
        case STATE_CHANGE_PLAYING_TO_PAUSED:
            STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]STATE_CHANGE_XXX_TO_PAUSE\n");
            break;

            /* deactivate pads */
        case STATE_CHANGE_PAUSED_TO_READY:
            STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]STATE_CHANGE_PAUSED_TO_READY\n");
            break;

        default:
            break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @param pad: pad handle
 * @param query: input buffer
 *
 * @brief This pad function handles query from the pipeline. If
 * not able to handle the query then it pushes the query to its peer.
 *
 * @returns: true/false
 */
static uint8_t eap_sink_pad_query_handler(StreamPad *pad, StreamQuery *query)
{
    ElementEap *element;
    StreamPad *peer;
    uint8_t ret = false;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == pad || NULL == query || NULL == QUERY_DATA(query), false);

    peer = PAD_PEER(pad);
    CHK_ARGS(NULL == peer, false);

    /* get the parent element from the pad */
    element = (ElementEap *)PAD_PARENT(pad);
    CHK_ARGS(NULL == element, false);

    STREAMER_LOG_DEBUG(DBG_EAP, "eap_sink_pad_query_handler: query[%d]\n", QUERY_TYPE(query));

    switch (QUERY_TYPE(query))
    {
        default:
            /* Relay all query downstream.
             */
            ret = pad_query(peer, query);
            break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @brief        eap_src_pad_query_handler
 *
 * @details      This pad function handles query from the pipeline. If
 *               not able to handle the query then it pushes the query to its peer.
 *
 * @param pad:   pad handle
 * @param query: input buffer
 *
 * @returns:     true/false
 */
static uint8_t eap_src_pad_query_handler(StreamPad *pad, StreamQuery *query)
{
    uint8_t ret = false;
    ElementEap *element;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == pad || NULL == query || NULL == QUERY_DATA(query), false);

    /* get the parent element from the pad */
    element = (ElementEap *)PAD_PARENT(pad);
    CHK_ARGS(NULL == element, false);

    STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]eap_src_pad_query_handler: query[%d]\n", QUERY_TYPE(query));

    switch (QUERY_TYPE(query))
    {
        default:
        {
            /* Relay all query downstream. */
            StreamPad *sink = ELEMENT_SINK_PAD(element, 0);
            StreamPad *peer = PAD_PEER(sink);

            if (peer)
                ret = pad_query(peer, query);
        }
        break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 * @brief        eap_src_pad_event_handler
 *
 * @details      This pad function handles events from the pipeline. If
 *               not able to handle the event then it pushes the event to its peer.
 *
 * @param pad:   pad handle
 * @param event: input buffer
 *
 * @returns:     true/false
 */
static uint8_t eap_src_pad_event_handler(StreamPad *pad, StreamEvent *event)
{
    uint8_t ret = false;
    ElementEap *element;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(NULL == pad || NULL == event, false);

    /* get the parent element from the pad */
    element = PAD_PARENT(pad);
    CHK_ARGS(NULL == element, false);

    STREAMER_LOG_DEBUG(DBG_EAP, "[EAP]eap_src_pad_event_handler: event[%d]\n", EVENT_TYPE(event));

    /* handle the event */
    switch (EVENT_TYPE(event))
    {
        case EVENT_SEEK:
            /* Push the event out from the source pad */
            ret = pad_push_event(ELEMENT_SINK_PAD(element, 0), event);
            break;
        default:
            break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/**
 * @brief Empty EAP src pull handler function
 *
 * @param pad    Pad pointer
 * @param buffer Buffer pointer
 * @param size   Size
 * @param offset Offset
 * @return PadReturn
 */
static PadReturn eap_src_pull_handler(StreamPad *pad, StreamBuffer *buffer, uint32_t size, uint32_t offset)
{
    STREAMER_LOG_DEBUG(DBG_EAP, "[EAP] eap_src_pull_handler request\n");
    return PAD_OK;
}

/*!
 * @param element_ptr: EAP element instance
 * @param prop:        eap element property
 * @param val:         value pointer
 *
 * @brief This function sets EAP element's properties
 *
 * @returns StreamReturnType
 *
 * @retval STREAM_OK success
 * @retval STREAM_ERR_INFO_ABSENT unknown property
 * @retval STREAM_GENERAL  bad status to set the property
 *
 */
static int32_t eap_set_property(StreamElement *element_ptr, uint16_t prop, uint32_t val)
{
    int32_t ret = STREAM_OK;

    // SET_BUFFER_DESC_T *buffer_desc_ptr = NULL;

    STREAMER_FUNC_ENTER(DBG_EAP);

    switch (prop)
    {
        case PROP_EAP_FPOINT:
        {
            EXT_PROCESS_DESC_T *desc_ptr = (EXT_PROCESS_DESC_T *)val;
            ret = eap_register_ext_processing((ElementHandle)element_ptr, desc_ptr->init_func, desc_ptr->proc_func,
                                              desc_ptr->deinit_func, desc_ptr->arg_ptr);
        }
        break;

        default:
            ret = STREAM_ERR_INFO_ABSENT;
            break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

/*!
 *
 * @param element_ptr: EAP element instance
 * @param prop:        eap element property
 * @param val_ptr:     value pointer
 *
 * @brief This function gets EAP element's properties
 *
 * @returns AudioSinkStreamErrorType
 *
 * @retval STREAM_OK success
 * @retval STREAM_ERR_INVALID_ARGS bad arguments
 * @retval STREAM_ERR_INFO_ABSENT unknown property
 *
 */
static int32_t eap_get_property(StreamElement *element_ptr, uint16_t prop, uint32_t *val_ptr)
{
    int32_t ret = STREAM_OK;

    STREAMER_FUNC_ENTER(DBG_EAP);

    if (NULL == val_ptr)
    {
        STREAMER_FUNC_EXIT(DBG_EAP);
        return STREAM_ERR_INVALID_ARGS;
    }

    switch (prop)
    {
        default:
            ret = STREAM_ERR_INFO_ABSENT;
            break;
    }

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

int32_t eap_init_element(StreamElement *element_ptr)
{
    int32_t ret         = STREAM_OK;
    uint32_t i          = 0;
    ElementEap *eap_ptr = (ElementEap *)element_ptr;

    STREAMER_FUNC_ENTER(DBG_EAP);

    if (NULL == eap_ptr)
    {
        ret = STREAM_ERR_ELEMENT_NOT_FOUND;
        goto ERR;
    }

    /* set element change state function */
    eap_ptr->change_state = eap_change_state;
    eap_ptr->set_property = eap_set_property;
    eap_ptr->get_property = eap_get_property;

    /* initialize element fields */
    eap_ptr->location      = NULL;
    eap_ptr->size          = 0;
    eap_ptr->current_index = 0;
    eap_ptr->initialized   = false;

    /* initialize sink pads handlers */
    for (i = 0; i < NUM_SINKS(TYPE_ELEMENT_EAP); i++)
    {
        PadSink *pad            = (PadSink *)ELEMENT_SINK_PAD(eap_ptr, i);
        pad->event_handler      = eap_sink_pad_event_handler;
        pad->activation_handler = eap_sink_pad_activation_handler;
        pad->chain_handler      = eap_sink_pad_chain_handler;
        pad->query_handler      = eap_sink_pad_query_handler;
        pad->process_precheck   = NULL;
        pad->process_handler    = NULL;
    }

    /* initialize src pads handlers */
    for (i = 0; i < NUM_SRCS(TYPE_ELEMENT_EAP); i++)
    {
        PadSrc *pad;
        pad = (PadSrc *)ELEMENT_SRC_PAD(eap_ptr, i);

        pad->query_handler      = eap_src_pad_query_handler;
        pad->event_handler      = eap_src_pad_event_handler;
        pad->activate_push      = NULL;
        pad->activation_handler = NULL;
        pad->pull_handler       = eap_src_pull_handler;
        pad->process_handler    = NULL;
        pad->process_precheck   = NULL;
    }

    // set function pointers to NULL
    eap_ptr->init_func   = NULL;
    eap_ptr->proc_func   = NULL;
    eap_ptr->deinit_func = NULL;

ERR:
    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

int32_t eap_set_buffer(ElementHandle element_hdl, char *location_ptr, uint32_t size)
{
    ElementEap *eap_ptr  = (ElementEap *)element_hdl;
    StreamReturnType ret = STREAM_OK;

    STREAMER_FUNC_ENTER(DBG_EAP);

    CHK_ARGS(eap_ptr == NULL || location_ptr == NULL || size == 0, STREAM_ERR_INVALID_ARGS);

    if (eap_ptr->state >= STATE_PAUSED)
    {
        STREAMER_FUNC_EXIT(DBG_EAP);
        return STREAM_ERR_GENERAL;
    }

    eap_ptr->location = location_ptr;
    eap_ptr->size     = size;

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}

int32_t eap_register_ext_processing(ElementHandle element,
                                    EapInitFunc init_func_ptr,
                                    EapPostProcFunc proc_func_ptr,
                                    EapDeinitFunc deinit_func_ptr,
                                    void *arg_ptr)
{
    int32_t ret = STREAM_OK;

    ElementEap *eap_ptr = (ElementEap *)element;

    STREAMER_FUNC_ENTER(DBG_EAP);

    if ((NULL == eap_ptr) || (NULL == init_func_ptr) || (NULL == proc_func_ptr) || (NULL == deinit_func_ptr))
    {
        STREAMER_FUNC_EXIT(DBG_EAP);
        return STREAM_ERR_INVALID_ARGS;
    }

    eap_ptr->init_func   = init_func_ptr;
    eap_ptr->proc_func   = proc_func_ptr;
    eap_ptr->deinit_func = deinit_func_ptr;
    eap_ptr->arg_ptr     = arg_ptr;

    STREAMER_FUNC_EXIT(DBG_EAP);
    return ret;
}
