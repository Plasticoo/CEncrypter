#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/whrlpool.h>
#include "whirlpool.h"

unsigned char *whirlpool_hash(unsigned char user_input[]) 
{

	static unsigned char output_buf[64];

	WHIRLPOOL(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;

}

char* whirlpool_make(unsigned char* hash_buffer) {

	unsigned char* whirlpool_res = whirlpool_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<64;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", whirlpool_res[i]);	
	}

	return Buffer;
}


