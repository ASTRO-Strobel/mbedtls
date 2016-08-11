#ifndef MY_INIT_MBEDTLS_H
#define MY_INIT_MBEDTLS_H

/* following 2 defines were
 * copied from generated lib/edge_pal_install/include/pkgconf/polarssl.h
 * by definition in lib_os/ecos/ecos-current/packages/net/polarssl/current/cdl/polarssl.cdl
 * to be used in
 * lib_os/ecos/ecos-current/packages/net/httpd/current/src/ssl.c
 * lib_common/utils/http_client.c
 */
#define NUM_MBEDTLS_DEBUG_LEVEL 0
#define NUM_MBEDTLS_DEBUG_LEVEL_0

#include <cyg/kernel/kapi.h>

__externC cyg_mutex_t mutex_mpi_mul;

void my_mbedtls_init(void);

#endif
