#include "polarssl/ecos.h"

cyg_mutex_t mutex_mpi_mul;

void cyg_polarssl_init(void) {
	cyg_mutex_init(&mutex_mpi_mul);
}
