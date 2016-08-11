#ifndef MY_INIT_MBEDTLS_H
#define MY_INIT_MBEDTLS_H

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
#define MBEDTLS_DEBUG_ENABLE 0
// "This option sets the debug level to use...
//  Use 2 for medium detail, 4 for lots of info."
#define NUM_MBEDTLS_DEBUG_LEVEL 0
#define NUM_MBEDTLS_DEBUG_LEVEL_0

// FIXXME: Missing:
// CYGPKG_MEMWATCH ? "-DMEMWATCH -include string.h -include memwatch.h"

#include <cyg/kernel/kapi.h>

__externC cyg_mutex_t mutex_mpi_mul;

void my_mbedtls_init(void);

#endif
