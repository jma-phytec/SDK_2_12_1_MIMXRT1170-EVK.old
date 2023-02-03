/*
 * Copyright 2021-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_25 (coord M15), LPUART1_RXD/J32[2] */
/* Routed pin properties */
#define BOARD_INITPINS_LPUART1_RXD_PERIPHERAL                            LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_LPUART1_RXD_SIGNAL                                    RXD   /*!< Signal name */

/* GPIO_AD_24 (coord L13), LPUART1_TXD/J31[2] */
/* Routed pin properties */
#define BOARD_INITPINS_LPUART1_TXD_PERIPHERAL                            LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_LPUART1_TXD_SIGNAL                                    TXD   /*!< Signal name */

/* GPIO_SD_B2_08 (coord F15), FlexSPI_A_D0/U23[5]/U21[D3] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_D0_PERIPHERAL                          FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_D0_SIGNAL                       FLEXSPI_A_DATA0   /*!< Signal name */

/* GPIO_SD_B2_09 (coord H15), FlexSPI_A_D1/U23[2]/U21[D2] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_D1_PERIPHERAL                          FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_D1_SIGNAL                       FLEXSPI_A_DATA1   /*!< Signal name */

/* GPIO_SD_B2_10 (coord H14), FlexSPI_A_D2/U23[3]/U21[C4] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_D2_PERIPHERAL                          FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_D2_SIGNAL                       FLEXSPI_A_DATA2   /*!< Signal name */

/* GPIO_SD_B2_11 (coord F16), FlexSPI_A_D3/U23[7]/U21[D4] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_D3_PERIPHERAL                          FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_D3_SIGNAL                       FLEXSPI_A_DATA3   /*!< Signal name */

/* GPIO_SD_B2_05 (coord E14), FlexSPI_A_DQS/U21[C3] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_DQS_PERIPHERAL                         FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_DQS_SIGNAL                        FLEXSPI_A_DQS   /*!< Signal name */

/* GPIO_SD_B2_07 (coord G14), FlexSPI_A_CLK/U23[6]/U21[B2] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_CLK_PERIPHERAL                         FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_CLK_SIGNAL                       FLEXSPI_A_SCLK   /*!< Signal name */

/* GPIO_SD_B2_06 (coord F17), FlexSPI_A_SS0/U23[1]/U21[C2] */
/* Routed pin properties */
#define BOARD_INITPINS_FlexSPI_A_SS0_PERIPHERAL                         FLEXSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_FlexSPI_A_SS0_SIGNAL                      FLEXSPI_A_SS0_B   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);                    /* Function assigned for the Cortex-M7F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
