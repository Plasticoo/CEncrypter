#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha512.h"

unsigned char *sha512_hash(unsigned char user_input[]) 
{
	static unsigned char output_buf[64];

	SHA512(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;
}

char* sha512_make(unsigned char* hash_buffer) {

	unsigned char* sha512_res = sha512_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<64;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", sha512_res[i]);	
	}

	return Buffer;
}



