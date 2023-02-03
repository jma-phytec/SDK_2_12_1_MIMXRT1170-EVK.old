/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
/* Copyright 2021 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

/* clang-format off */

#ifndef __MBEDTLS_USER_CONFIG_H__
#define __MBEDTLS_USER_CONFIG_H__

#if defined(SSS_USE_FTR_FILE)
#include "fsl_sss_ftr.h"
#else
#include "fsl_sss_ftr_default.h"
#endif

#ifndef MBEDTLS_ECP_DP_SECP192R1_ENABLED
    #define MBEDTLS_ECP_DP_SECP192R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP192R1_ENABLED
#ifndef MBEDTLS_ECP_DP_SECP224R1_ENABLED
    #define MBEDTLS_ECP_DP_SECP224R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP224R1_ENABLED
#ifndef MBEDTLS_ECP_DP_SECP384R1_ENABLED
    #define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP384R1_ENABLED
#ifndef MBEDTLS_FREESCALE_LTC_PKHA
#ifndef MBEDTLS_ECP_DP_SECP521R1_ENABLED
    #define MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif // MBEDTLS_FREESCALE_LTC_PKHA

#if defined(LPC_55x)
#if defined(MBEDTLS_MCUX_CASPER_ECC)
    #undef MBEDTLS_MCUX_CASPER_ECC
#endif // MBEDTLS_MCUX_CASPER_ECC
#if defined(MBEDTLS_ECP_MUL_COMB_ALT)
    #undef MBEDTLS_ECP_MUL_COMB_ALT
#endif // MBEDTLS_ECP_MUL_COMB_ALT
#if defined(MBEDTLS_ECP_MULADD_ALT)
    #undef MBEDTLS_ECP_MULADD_ALT
#endif // MBEDTLS_ECP_MULADD_ALT
#endif // LPC_55x

#if defined(MBEDTLS_AES_ALT)
    #undef MBEDTLS_AES_ALT
#endif // MBEDTLS_AES_ALT
#if defined(MBEDTLS_AES_SETKEY_ENC_ALT)
    #undef MBEDTLS_AES_SETKEY_ENC_ALT
#endif // MBEDTLS_AES_SETKEY_ENC_ALT
#if defined(MBEDTLS_AES_SETKEY_DEC_ALT)
    #undef MBEDTLS_AES_SETKEY_DEC_ALT
#endif // MBEDTLS_AES_SETKEY_DEC_ALT
#if defined(MBEDTLS_AES_ENCRYPT_ALT)
    #undef MBEDTLS_AES_ENCRYPT_ALT
#endif // MBEDTLS_AES_ENCRYPT_ALT
#if defined(MBEDTLS_AES_DECRYPT_ALT)
    #undef MBEDTLS_AES_DECRYPT_ALT
#endif // MBEDTLS_AES_DECRYPT_ALT


#if defined(MBEDTLS_ECP_ALT)
    #undef MBEDTLS_ECP_ALT
#endif // MBEDTLS_ECP_ALT
#if defined(MBEDTLS_ECDH_ALT)
    #undef MBEDTLS_ECDH_ALT
#endif // MBEDTLS_ECDH_ALT
#if defined(MBEDTLS_ECDH_GEN_PUBLIC_ALT)
    #undef MBEDTLS_ECDH_GEN_PUBLIC_ALT
#endif // MBEDTLS_ECDH_GEN_PUBLIC_ALT
#if defined(MBEDTLS_ECDH_COMPUTE_SHARED_ALT)
    #undef MBEDTLS_ECDH_COMPUTE_SHARED_ALT
#endif // MBEDTLS_ECDH_COMPUTE_SHARED_ALT

#if (SSS_HAVE_RSA)
#if defined(MBEDTLS_RSA_ALT)
    #undef MBEDTLS_RSA_ALT
#endif // MBEDTLS_RSA_ALT
#if defined(MBEDTLS_RSA_PUBLIC_ALT)
    #undef MBEDTLS_RSA_PUBLIC_ALT
#endif // MBEDTLS_RSA_PUBLIC_ALT
#endif // SSS_HAVE_RSA

#if SSS_HAVE_MBEDTLS_ALT

#if defined(IMX_RT)
#if defined(MBEDTLS_AES_ALT_NO_192)
    #undef MBEDTLS_AES_ALT_NO_192
#endif // MBEDTLS_AES_ALT_NO_192
#if defined(MBEDTLS_AES_CRYPT_CBC_ALT)
    #undef MBEDTLS_AES_CRYPT_CBC_ALT
#endif // MBEDTLS_AES_CRYPT_CBC_ALT
#if defined(MBEDTLS_FREESCALE_DCP_AES)
    #undef MBEDTLS_FREESCALE_DCP_AES
#endif // MBEDTLS_FREESCALE_DCP_AES
#endif // IMX_RT

#if defined(IMX_RT)
/* If We use ALT from the EVKB, anything that is related to
 * AES256 would get skipped and because of this TLS Handshake
 * would not pass
 *
 * Disabling this altogether. May be there's a way to use AES256
 * on EVKB with mbedTLS but need to Check.
 */
#if defined(MBEDTLS_AES_ALT)
    #undef MBEDTLS_AES_ALT
#endif // MBEDTLS_AES_ALT
#if defined(MBEDTLS_AES_ALT_NO_256)
    #undef MBEDTLS_AES_ALT_NO_256
#endif // MBEDTLS_AES_ALT_NO_256
#endif // IMX_RT

#if defined(CPU_MIMXRT1176DVMAA_cm7)
#if defined(MBEDTLS_FREESCALE_LTC_AES)
    #undef MBEDTLS_FREESCALE_LTC_AES
#endif // MBEDTLS_FREESCALE_LTC_AES
#if defined(MBEDTLS_FREESCALE_MMCAU_AES)
    #undef MBEDTLS_FREESCALE_MMCAU_AES
#endif // MBEDTLS_FREESCALE_MMCAU_AES
#if defined(MBEDTLS_FREESCALE_LPC_AES)
    #undef MBEDTLS_FREESCALE_LPC_AES
#endif // MBEDTLS_FREESCALE_LPC_AES
#if defined(MBEDTLS_FREESCALE_CAU3_AES)
    #undef MBEDTLS_FREESCALE_CAU3_AES
#endif // MBEDTLS_FREESCALE_CAU3_AES
#if defined(MBEDTLS_FREESCALE_CAAM_AES)
    #undef MBEDTLS_FREESCALE_CAAM_AES
#endif // MBEDTLS_FREESCALE_CAAM_AES
#if defined(MBEDTLS_FREESCALE_DCP_AES)
    #undef MBEDTLS_FREESCALE_DCP_AES
#endif // MBEDTLS_FREESCALE_DCP_AES
#if defined(MBEDTLS_CCM_CRYPT_ALT)
    #undef MBEDTLS_CCM_CRYPT_ALT
#endif // MBEDTLS_CCM_CRYPT_ALT
#if defined(MBEDTLS_GCM_CRYPT_ALT)
    #undef MBEDTLS_GCM_CRYPT_ALT
#endif // MBEDTLS_GCM_CRYPT_ALT
#endif // CPU_MIMXRT1176DVMAA_cm7

#if SSS_HAVE_MBEDTLS_ALT_A71CH
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP192R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP192R1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP224R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP224R1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP384R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP384R1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP521R1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP192K1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP192K1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP224K1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP224K1_ENABLED
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED)
    #undef MBEDTLS_ECP_DP_SECP256K1_ENABLED
#endif // MBEDTLS_ECP_DP_SECP256K1_ENABLED
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED)
    #undef MBEDTLS_ECP_DP_BP256R1_ENABLED
#endif // MBEDTLS_ECP_DP_BP256R1_ENABLED
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED)
    #undef MBEDTLS_ECP_DP_BP384R1_ENABLED
#endif // MBEDTLS_ECP_DP_BP384R1_ENABLED
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED)
    #undef MBEDTLS_ECP_DP_BP512R1_ENABLED
#endif // MBEDTLS_ECP_DP_BP512R1_ENABLED
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
    #undef MBEDTLS_ECP_DP_CURVE25519_ENABLED
#endif // MBEDTLS_ECP_DP_CURVE25519_ENABLED
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
    #undef MBEDTLS_ECP_DP_CURVE448_ENABLED
#endif // MBEDTLS_ECP_DP_CURVE448_ENABLED
#if defined(MBEDTLS_SHA512_C)
    #undef MBEDTLS_SHA512_C
#endif // MBEDTLS_SHA512_C

#elif SSS_HAVE_MBEDTLS_ALT_SSS

//

#endif // SSS_HAVE_MBEDTLS_ALT_A71CH
#endif // SSS_HAVE_MBEDTLS_ALT

#if defined(IMX_RT) || defined(LPC_55x)
/* We need this for mbedTLS sw crypto counterpart */
#ifndef MBEDTLS_CTR_DRBG_C
    #define MBEDTLS_CTR_DRBG_C
#endif // MBEDTLS_CTR_DRBG_C
#endif // IMX_RT || LPC_55x

#if defined(MBEDTLS_HKDF_C)
    #undef MBEDTLS_HKDF_C
#endif

#if defined(MBEDTLS_SELF_TEST)
    #undef MBEDTLS_SELF_TEST
#endif // MBEDTLS_SELF_TEST

#ifndef MBEDTLS_CMAC_C
    #define MBEDTLS_CMAC_C
#endif // MBEDTLS_CMAC_C

#ifndef MBEDTLS_FS_IO
    #define MBEDTLS_FS_IO
#endif // MBEDTLS_FS_IO
#ifndef MBEDTLS_PSA_CRYPTO_C
    #define MBEDTLS_PSA_CRYPTO_C
#endif // MBEDTLS_PSA_CRYPTO_C
#ifndef MBEDTLS_PSA_CRYPTO_STORAGE_C
    #define MBEDTLS_PSA_CRYPTO_STORAGE_C
#endif // MBEDTLS_PSA_CRYPTO_STORAGE_C
#ifndef MBEDTLS_PSA_ITS_FILE_C
    #define MBEDTLS_PSA_ITS_FILE_C
#endif // MBEDTLS_PSA_ITS_FILE_C
#ifndef MBEDTLS_PSA_CRYPTO_SE_C
    #define MBEDTLS_PSA_CRYPTO_SE_C
#endif // MBEDTLS_PSA_CRYPTO_SE_C

#include <fsl_sss_types.h>

#ifndef MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_MEMORY
#endif

#if defined(MBEDTLS_PLATFORM_STD_CALLOC)
#undef MBEDTLS_PLATFORM_STD_CALLOC
#endif // MBEDTLS_PLATFORM_STD_CALLOC

#if defined(MBEDTLS_PLATFORM_STD_FREE)
#undef MBEDTLS_PLATFORM_STD_FREE
#endif // MBEDTLS_PLATFORM_STD_FREE

#if defined(MBEDTLS_PLATFORM_CALLOC_MACRO)
#undef MBEDTLS_PLATFORM_CALLOC_MACRO
#endif // MBEDTLS_PLATFORM_CALLOC_MACRO

#if defined(MBEDTLS_PLATFORM_FREE_MACRO)
#undef MBEDTLS_PLATFORM_FREE_MACRO
#endif // MBEDTLS_PLATFORM_FREE_MACRO

#define MBEDTLS_PLATFORM_CALLOC_MACRO SSS_CALLOC
#define MBEDTLS_PLATFORM_FREE_MACRO SSS_FREE

#endif /* __MBEDTLS_USER_CONFIG_H__ */
