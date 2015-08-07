/*
 *  Self-test demonstration program
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#if !defined(POLARSSL_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include "mbedtls/entropy.h"
#include "mbedtls/hmac_drbg.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/gcm.h"
#include "mbedtls/ccm.h"
#include "mbedtls/md2.h"
#include "mbedtls/md4.h"
#include "mbedtls/md5.h"
#include "mbedtls/ripemd160.h"
#include "mbedtls/sha1.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"
#include "mbedtls/arc4.h"
#include "mbedtls/des.h"
#include "mbedtls/aes.h"
#include "mbedtls/camellia.h"
#include "mbedtls/base64.h"
#include "mbedtls/bignum.h"
#include "mbedtls/rsa.h"
#include "mbedtls/x509.h"
#include "mbedtls/xtea.h"
#include "mbedtls/pkcs5.h"
#include "mbedtls/ecp.h"

#include <stdio.h>
#include <string.h>

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf     printf
#endif

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif

int selftest( int argc, char *argv[] )
{
    int ret = 0, v;
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
    unsigned char buf[1000000];
#endif

    if( argc == 2 && strcmp( argv[1], "-quiet" ) == 0 )
        v = 0;
    else
    {
        v = 1;
        mbedtls_printf( "\n" );
    }

#if defined(MBEDTLS_SELF_TEST)

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
    mbedtls_memory_buffer_alloc_init( buf, sizeof(buf) );
#endif

#if defined(MBEDTLS_MD2_C)
    if( ( ret = mbedtls_md2_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_MD4_C)
    if( ( ret = mbedtls_md4_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_MD5_C)
    if( ( ret = mbedtls_md5_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_RIPEMD160_C)
    if( ( ret = mbedtls_ripemd160_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_SHA1_C)
    if( ( ret = mbedtls_sha1_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_SHA256_C)
    if( ( ret = mbedtls_sha256_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_SHA512_C)
    if( ( ret = mbedtls_sha512_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_ARC4_C)
    if( ( ret = mbedtls_arc4_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_DES_C)
    if( ( ret = mbedtls_des_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_AES_C)
    if( ( ret = mbedtls_aes_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_GCM_C) && defined(MBEDTLS_AES_C)
    if( ( ret = mbedtls_gcm_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_CCM_C) && defined(MBEDTLS_AES_C)
    if( ( ret = mbedtls_ccm_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_BASE64_C)
    if( ( ret = mbedtls_base64_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_BIGNUM_C)
    if( ( ret = mbedtls_mpi_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_RSA_C)
    if( ( ret = mbedtls_rsa_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_X509_USE_C)
    if( ( ret = mbedtls_x509_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_XTEA_C)
    if( ( ret = mbedtls_xtea_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_CAMELLIA_C)
    if( ( ret = mbedtls_camellia_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_CTR_DRBG_C)
    if( ( ret = mbedtls_ctr_drbg_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_HMAC_DRBG_C)
    if( ( ret = mbedtls_hmac_drbg_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_ECP_C)
    if( ( ret = mbedtls_ecp_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_DHM_C)
    if( ( ret = mbedtls_dhm_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_ENTROPY_C)
    if( ( ret = mbedtls_entropy_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_PKCS5_C)
    if( ( ret = mbedtls_pkcs5_self_test( v ) ) != 0 )
        return( ret );
#endif

#if defined(MBEDTLS_TIMING_C)
    if( ( ret = mbedtls_timing_self_test( v ) ) != 0 )
        return( ret );
#endif

#else
    mbedtls_printf( " POLARSSL_SELF_TEST not defined.\n" );
#endif

    if( v != 0 )
    {
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && defined(MBEDTLS_MEMORY_DEBUG)
        mbedtls_memory_buffer_alloc_status();
#endif
    }

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
    mbedtls_memory_buffer_alloc_free();

    if( ( ret = mbedtls_memory_buffer_alloc_self_test( v ) ) != 0 )
        return( ret );
#endif

    if( v != 0 )
    {
        mbedtls_printf( "  [ All tests passed ]\n\n" );
#if defined(_WIN32)
        mbedtls_printf( "  Press Enter to exit this program.\n" );
        fflush( stdout ); getchar();
#endif
    }

    return( ret );
}

#if defined(TARGET_LIKE_MBED)

#include "mbed/test_env.h"

int main() {
    /* Use 115200 bps for consistency with other examples */
    Serial pc(USBTX, USBRX);
    pc.baud(115200);

    MBED_HOSTTEST_TIMEOUT(40);
    MBED_HOSTTEST_SELECT(default);
    MBED_HOSTTEST_DESCRIPTION(mbed TLS selftest program);
    MBED_HOSTTEST_START("MBEDTLS_SELFTEST");
    MBED_HOSTTEST_RESULT(selftest(0, NULL) == 0);
}

#else

int main() {
    return selftest(0, NULL);
}

#endif
