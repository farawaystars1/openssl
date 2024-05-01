#pragma once
#include"../openssl.h"

X509* readCert(const char* path);
EVP_PKEY* readPrivateKey(const char* path);