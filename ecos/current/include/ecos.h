#ifndef POLARSSL_ECOS_H
#define POLARSSL_ECOS_H

#include <cyg/kernel/kapi.h>

__externC cyg_mutex_t mutex_mpi_mul;

void cyg_polarssl_init(void);

#endif
