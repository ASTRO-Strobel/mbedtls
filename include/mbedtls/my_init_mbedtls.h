#ifndef MY_INIT_MBEDTLS_H
#define MY_INIT_MBEDTLS_H

// Uncomment this to disable SSL (via mbed TLS)
#define USE_MBEDTLS 1

/* following 3 defines were defined in
 * lib_os/ecos/ecos-current/packages/net/polarssl/current/cdl/polarssl.cdl
 * to be used in
 * lib_os/ecos/ecos-current/packages/net/httpd/current/src/ssl.c
 * lib_common/utils/http_client.c
 *
 * "This option enables debugging code...
	This really hurts performance and it also introduces a side-channel
	attack and should thus not be left enabled in production code."
 */
#define MBEDTLS_DEBUG_ENABLE 1
// "This option sets the debug level to use...
//  Use 2 for medium detail, 4 for lots of info."
#define NUM_MBEDTLS_DEBUG_LEVEL 2
#define NUM_MBEDTLS_DEBUG_LEVEL_2

// FIXXME: Missing:
// CYGPKG_MEMWATCH ? "-DMEMWATCH -include string.h -include memwatch.h"

#include <cyg/kernel/kapi.h>

// required to define mbedtls_time_t
#include "mbedtls/platform.h"

// some compatibilty - code: now IPv6 is non-optional, cause MBEDTLS_NET_C requires it
/* BUT: This runs into errors:
 * ip6stat in lib_os/.../bsd_tcpip/.../sys/param.h is #define'd to be 'cyg_ip6stat'
 * nowhere to be defined!
#ifdef MBEDTLS_NET_C
#define CYGPKG_NET_INET6
#endif
 */
// but config.h cannot hurt anyway!
#include "mbedtls/config.h"

__externC cyg_mutex_t mutex_mpi_mul;

void my_mbedtls_init(void);

#endif
