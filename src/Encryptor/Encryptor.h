/* Encryptor object */



#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include "Environment.h"

typedef struct
{
	FILE *pProg;
	char *(*EncryptBuffer)(char *pBuf_Arg);
	char *(*DecryptBuffer)(char *pBuf_Arg);
}EncEncryptor_Type;

#include "Encryptor/EncOpen.c"
#include "Encryptor/EncClose.c"
#include "Encryptor/EncEncryptFunc.c"
#include "Encryptor/EncDecryptFunc.c"



#endif
