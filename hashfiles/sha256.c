#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha256.h"

unsigned char *sha256_hash(unsigned char user_input[]) 
{
	static unsigned char output_buf[32];

	SHA256(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;
}

char* sha256_make(unsigned char* hash_buffer) {

	unsigned char* sha256_res = sha256_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<32;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", sha256_res[i]);	
	}

	return Buffer;
}



