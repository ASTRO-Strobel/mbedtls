#include "mbedtls/my_init_mbedtls.h"

cyg_mutex_t mutex_mpi_mul;

void my_mbedtls_init(void) {
	cyg_mutex_init(&mutex_mpi_mul);
}
