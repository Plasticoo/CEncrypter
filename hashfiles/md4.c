#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md4.h>
#include "md4.h"

unsigned char *md4_hash(unsigned char user_input[]) 
{

	static unsigned char output_buf[16];

	MD4(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;

}

char* md4_make(unsigned char* hash_buffer) {

	unsigned char* md4_res = md4_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<16;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", md4_res[i]);
	}

	return Buffer;
}


