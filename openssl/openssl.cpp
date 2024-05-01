// openssl.cpp: 定义应用程序的入口点。
//

#include<iostream>
#include<memory>

#include"openssl.h"
#include"utils/file_utils.h"
using namespace std;

int main()
{
	X509* cert = NULL;
	EVP_PKEY* privateKey = NULL;
	BIO* memBio = NULL;
	PKCS7* p7 = NULL;
	int result = 0;
	BIO* output = NULL;
	char buf[5] = { 0 };
	size_t readByts = 0;
	std::string ret;

	std::string content = "hello,worldssssssssssssssssssss999999999999999"; 
	cert = readCert("/home/xingxing/opensslKeyAndCeritificate/ecdsa_cert.pem");
	if (cert == NULL)return -1;
	privateKey = readPrivateKey("/home/xingxing/opensslKeyAndCeritificate/private.key"); if (privateKey == NULL)return -1;
	memBio = BIO_new_mem_buf(content.data(), content.size()); if (memBio == NULL)return -1;
	p7 = PKCS7_sign(cert, privateKey, NULL, memBio, 0); if (p7 == NULL)return -1;
	result=PKCS7_verify(p7, NULL, NULL, NULL, NULL, PKCS7_NOVERIFY);
	if (result == 1)
	{
		std::cout << "verified success!" << std::endl;
	}
	else {
		std::cout<<("verified failed") << std::endl;
	}
	output=PKCS7_dataDecode(p7, NULL, NULL, NULL);

	while ((result = BIO_read_ex(output, buf, sizeof(buf), &readByts))==1)
	{
		ret.append(buf,readByts);
	}
	std::cout << "ret size:" << ret.size() << std::endl;
	std::cout <<"content:"<< ret << std::endl;

	/*size_t written = 0;
	int ret=BIO_write(memBio,content.c_str(), content.length());
	std::cout << ret << std::endl;
	std::cout << written << std::endl;
	std::cout << buf << std::endl;*/
	return 0;
}
