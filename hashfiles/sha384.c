#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha384.h"

unsigned char *sha384_hash(unsigned char user_input[]) 
{
	static unsigned char output_buf[48];

	SHA384(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;
}

char* sha384_make(unsigned char* hash_buffer) {

	unsigned char* sha384_res = sha384_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<48;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", sha384_res[i]);	
	}

	return Buffer;
}



