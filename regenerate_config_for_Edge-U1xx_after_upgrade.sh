#!/bin/sh

# FIXXME: The config entry MBEDTLS_DEBUG_DFL_MODE
# has not yet been changed from
# MBEDTLS_DEBUG_LOG_FULL
# to
# MBEDTLS_DEBUG_LOG_RAW

myname="$(basename "$0")"

cd "$(dirname "$0")"

makefile="$(mktemp /tmp/Makefile-"$myname".XXXXXX)"

cat > "$makefile" <<EOF
all: patch_config

.SILENT:

patch_config:
	grep -q "<pkgconf/system.h>" include/mbedtls/config.h \
		|| sed --in-place -re "s,(#define MBEDTLS_CONFIG_H),\1\n\n"\
"#include <pkgconf/system.h>\n"\
"#include <cyg/hal/system.h>\n"\
'#include "mbedtls/my_init_mbedtls.h"'\
"," include/mbedtls/config.h
	echo \
		MBEDTLS_NO_PLATFORM_ENTROPY 		\
		MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES	\
		MBEDTLS_ENTROPY_FORCE_SHA256		\
		MBEDTLS_SSL_SRV_SUPPORT_SSLV2_CLIENT_HELLO	\
		MBEDTLS_THREADING_C					\
		MBEDTLS_THREADING_ALT				\
		| xargs -n 1 scripts/config.pl \
			-f include/mbedtls/config.h \
			set
	echo \
		MBEDTLS_TIMING_C 					\
		MBEDTLS_REMOVE_ARC4_CIPHERSUITES 	\
		MBEDTLS_ECP_DP_SECP521R1_ENABLED 	\
		MBEDTLS_ECP_DP_BP256R1_ENABLED 		\
		MBEDTLS_ECP_DP_BP384R1_ENABLED		\
		MBEDTLS_ECP_DP_BP512R1_ENABLED		\
		MBEDTLS_KEY_EXCHANGE_PSK_ENABLED	\
		MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED	\
		MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED	\
		MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED	\
		MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED	\
		MBEDTLS_PK_RSA_ALT_SUPPORT				\
		MBEDTLS_SSL_RENEGOTIATION			\
		MBEDTLS_SSL_PROTO_DTLS				\
		MBEDTLS_SSL_DTLS_HELLO_VERIFY		\
		MBEDTLS_SSL_DTLS_ANTI_REPLAY		\
		MBEDTLS_SSL_DTLS_BADMAC_LIMIT		\
		MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE	\
		MBEDTLS_VERSION_FEATURES			\
		MBEDTLS_AESNI_C						\
		MBEDTLS_ARC4_C						\
		MBEDTLS_DES_C						\
		MBEDTLS_PADLOCK_C					\
		MBEDTLS_XTEA_C						\
		| xargs -n 1 scripts/config.pl \
			-f include/mbedtls/config.h \
			unset
EOF

make -f "$makefile"

rm -f "$makefile"
