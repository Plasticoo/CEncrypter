#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha224.h"

unsigned char *sha224_hash(unsigned char user_input[]) 
{
	static unsigned char output_buf[28];

	SHA224(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;
}

char* sha224_make(unsigned char* hash_buffer) {

	unsigned char* sha224_res = sha224_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<28;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", sha224_res[i]);	
	}

	return Buffer;
}



