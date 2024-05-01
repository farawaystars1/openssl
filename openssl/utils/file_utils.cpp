#include "file_utils.h"

X509* readCert(const char* path)
{
	X509* cert = NULL;
	BIO* in = NULL;

	in = BIO_new_file(path,"rb");
	cert = PEM_read_bio_X509(in, NULL, NULL, NULL);
	//test
	return cert;
}

EVP_PKEY* readPrivateKey(const char* path)
{
	BIO* in = NULL;
	EVP_PKEY* key = NULL;
	in = BIO_new_file(path, "rb");
	key = PEM_read_bio_PrivateKey(in, NULL, NULL, NULL);
	return key;
}
