#include "src/ux_device_class_audio10_control_process.c"
#include "src/ux_device_class_audio20_control_process.c"
#include "src/ux_device_class_audio_activate.c"
#include "src/ux_device_class_audio_change.c"
#include "src/ux_device_class_audio_control_request.c"
#include "src/ux_device_class_audio_deactivate.c"
#include "src/ux_device_class_audio_entry.c"
#include "src/ux_device_class_audio_feedback_get.c"
#include "src/ux_device_class_audio_feedback_set.c"
#include "src/ux_device_class_audio_feedback_thread_entry.c"
#include "src/ux_device_class_audio_frame_write.c"
#include "src/ux_device_class_audio_initialize.c"
#include "src/ux_device_class_audio_ioctl.c"
#include "src/ux_device_class_audio_read_frame_free.c"
#include "src/ux_device_class_audio_read_frame_get.c"
#include "src/ux_device_class_audio_read_thread_entry.c"
#include "src/ux_device_class_audio_reception_start.c"
#include "src/ux_device_class_audio_sample_read16.c"
#include "src/ux_device_class_audio_sample_read24.c"
#include "src/ux_device_class_audio_sample_read32.c"
#include "src/ux_device_class_audio_sample_read8.c"
#include "src/ux_device_class_audio_speed_get.c"
#include "src/ux_device_class_audio_stream_get.c"
#include "src/ux_device_class_audio_transmission_start.c"
#include "src/ux_device_class_audio_unitialize.c"
#include "src/ux_device_class_audio_write_frame_commit.c"
#include "src/ux_device_class_audio_write_frame_get.c"
#include "src/ux_device_class_audio_write_thread_entry.c"
#include "src/ux_device_class_cdc_acm_activate.c"
#include "src/ux_device_class_cdc_acm_bulkin_thread.c"
#include "src/ux_device_class_cdc_acm_bulkout_thread.c"
#include "src/ux_device_class_cdc_acm_control_request.c"
#include "src/ux_device_class_cdc_acm_deactivate.c"
#include "src/ux_device_class_cdc_acm_entry.c"
#include "src/ux_device_class_cdc_acm_initialize.c"
#include "src/ux_device_class_cdc_acm_ioctl.c"
#include "src/ux_device_class_cdc_acm_read.c"
#include "src/ux_device_class_cdc_acm_read_run.c"
#include "src/ux_device_class_cdc_acm_tasks_run.c"
#include "src/ux_device_class_cdc_acm_unitialize.c"
#include "src/ux_device_class_cdc_acm_write.c"
#include "src/ux_device_class_cdc_acm_write_run.c"
#include "src/ux_device_class_cdc_acm_write_with_callback.c"
#include "src/ux_device_class_cdc_ecm_activate.c"
#include "src/ux_device_class_cdc_ecm_bulkin_thread.c"
#include "src/ux_device_class_cdc_ecm_bulkout_thread.c"
#include "src/ux_device_class_cdc_ecm_change.c"
#include "src/ux_device_class_cdc_ecm_control_request.c"
#include "src/ux_device_class_cdc_ecm_deactivate.c"
#include "src/ux_device_class_cdc_ecm_entry.c"
#include "src/ux_device_class_cdc_ecm_initialize.c"
#include "src/ux_device_class_cdc_ecm_interrupt_thread.c"
#include "src/ux_device_class_cdc_ecm_uninitialize.c"
#include "src/ux_device_class_cdc_ecm_write.c"
#include "src/ux_device_class_dfu_activate.c"
#include "src/ux_device_class_dfu_control_request.c"
#include "src/ux_device_class_dfu_deactivate.c"
#include "src/ux_device_class_dfu_entry.c"
#include "src/ux_device_class_dfu_initialize.c"
#include "src/ux_device_class_dfu_state_get.c"
#include "src/ux_device_class_dfu_state_sync.c"
#include "src/ux_device_class_dfu_tasks_run.c"
#include "src/ux_device_class_dfu_thread.c"
#include "src/ux_device_class_hid_activate.c"
#include "src/ux_device_class_hid_control_request.c"
#include "src/ux_device_class_hid_deactivate.c"
#include "src/ux_device_class_hid_descriptor_send.c"
#include "src/ux_device_class_hid_entry.c"
#include "src/ux_device_class_hid_event_get.c"
#include "src/ux_device_class_hid_event_set.c"
#include "src/ux_device_class_hid_initialize.c"
#include "src/ux_device_class_hid_interrupt_thread.c"
#include "src/ux_device_class_hid_read.c"
#include "src/ux_device_class_hid_receiver_event_free.c"
#include "src/ux_device_class_hid_receiver_event_get.c"
#include "src/ux_device_class_hid_receiver_initialize.c"
#include "src/ux_device_class_hid_receiver_thread.c"
#include "src/ux_device_class_hid_receiver_uninitialize.c"
#include "src/ux_device_class_hid_report_get.c"
#include "src/ux_device_class_hid_report_set.c"
#include "src/ux_device_class_hid_tasks_run.c"
#include "src/ux_device_class_hid_uninitialize.c"
#include "src/ux_device_class_pima_activate.c"
#include "src/ux_device_class_pima_control_request.c"
#include "src/ux_device_class_pima_data.c"
#include "src/ux_device_class_pima_deactivate.c"
#include "src/ux_device_class_pima_device_info_send.c"
#include "src/ux_device_class_pima_device_prop_desc_get.c"
#include "src/ux_device_class_pima_device_prop_value_get.c"
#include "src/ux_device_class_pima_device_prop_value_set.c"
#include "src/ux_device_class_pima_device_reset.c"
#include "src/ux_device_class_pima_entry.c"
#include "src/ux_device_class_pima_event_get.c"
#include "src/ux_device_class_pima_event_set.c"
#include "src/ux_device_class_pima_initialize.c"
#include "src/ux_device_class_pima_interrupt_thread.c"
#include "src/ux_device_class_pima_object_add.c"
#include "src/ux_device_class_pima_object_data_get.c"
#include "src/ux_device_class_pima_object_data_send.c"
#include "src/ux_device_class_pima_object_delete.c"
#include "src/ux_device_class_pima_object_handles_send.c"
#include "src/ux_device_class_pima_object_info_get.c"
#include "src/ux_device_class_pima_object_info_send.c"
#include "src/ux_device_class_pima_object_prop_desc_get.c"
#include "src/ux_device_class_pima_object_props_supported_get.c"
#include "src/ux_device_class_pima_object_prop_value_get.c"
#include "src/ux_device_class_pima_object_prop_value_set.c"
#include "src/ux_device_class_pima_object_references_get.c"
#include "src/ux_device_class_pima_object_references_set.c"
#include "src/ux_device_class_pima_objects_number_send.c"
#include "src/ux_device_class_pima_partial_object_data_get.c"
#include "src/ux_device_class_pima_response_send.c"
#include "src/ux_device_class_pima_storage_format.c"
#include "src/ux_device_class_pima_storage_id_send.c"
#include "src/ux_device_class_pima_storage_info_get.c"
#include "src/ux_device_class_pima_thread.c"
#include "src/ux_device_class_printer_activate.c"
#include "src/ux_device_class_printer_control_request.c"
#include "src/ux_device_class_printer_deactivate.c"
#include "src/ux_device_class_printer_entry.c"
#include "src/ux_device_class_printer_initialize.c"
#include "src/ux_device_class_printer_ioctl.c"
#include "src/ux_device_class_printer_read.c"
#include "src/ux_device_class_printer_soft_reset.c"
#include "src/ux_device_class_printer_uninitialize.c"
#include "src/ux_device_class_printer_write.c"
#include "src/ux_device_class_rndis_activate.c"
#include "src/ux_device_class_rndis_bulkin_thread.c"
#include "src/ux_device_class_rndis_bulkout_thread.c"
#include "src/ux_device_class_rndis_control_request.c"
#include "src/ux_device_class_rndis_deactivate.c"
#include "src/ux_device_class_rndis_entry.c"
#include "src/ux_device_class_rndis_initialize.c"
#include "src/ux_device_class_rndis_interrupt_thread.c"
#include "src/ux_device_class_rndis_msg_initialize.c"
#include "src/ux_device_class_rndis_msg_keep_alive.c"
#include "src/ux_device_class_rndis_msg_query.c"
#include "src/ux_device_class_rndis_msg_reset.c"
#include "src/ux_device_class_rndis_msg_set.c"
#include "src/ux_device_class_rndis_write.c"
#include "src/ux_device_class_storage_activate.c"
#include "src/ux_device_class_storage_control_request.c"
#include "src/ux_device_class_storage_csw_send.c"
#include "src/ux_device_class_storage_deactivate.c"
#include "src/ux_device_class_storage_entry.c"
#include "src/ux_device_class_storage_format.c"
#include "src/ux_device_class_storage_get_configuration.c"
#include "src/ux_device_class_storage_get_performance.c"
#include "src/ux_device_class_storage_get_status_notification.c"
#include "src/ux_device_class_storage_initialize.c"
#include "src/ux_device_class_storage_inquiry.c"
#include "src/ux_device_class_storage_mode_select.c"
#include "src/ux_device_class_storage_mode_sense.c"
#include "src/ux_device_class_storage_prevent_allow_media_removal.c"
#include "src/ux_device_class_storage_read.c"
#include "src/ux_device_class_storage_read_capacity.c"
#include "src/ux_device_class_storage_read_disk_information.c"
#include "src/ux_device_class_storage_read_dvd_structure.c"
#include "src/ux_device_class_storage_read_format_capacity.c"
#include "src/ux_device_class_storage_read_toc.c"
#include "src/ux_device_class_storage_report_key.c"
#include "src/ux_device_class_storage_request_sense.c"
#include "src/ux_device_class_storage_start_stop.c"
#include "src/ux_device_class_storage_synchronize_cache.c"
#include "src/ux_device_class_storage_tasks_run.c"
#include "src/ux_device_class_storage_test_ready.c"
#include "src/ux_device_class_storage_thread.c"
#include "src/ux_device_class_storage_uninitialize.c"
#include "src/ux_device_class_storage_verify.c"
#include "src/ux_device_class_storage_write.c"