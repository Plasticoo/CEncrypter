#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>
#include <stdlib.h>
#include "md5.h"

unsigned char *md5_hash(unsigned char user_input[]) 
{

	static unsigned char output_buf[20];

	MD5(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;

}

char* md5_make(unsigned char* hash_buffer) {

	unsigned char* md5_res = md5_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<16;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", md5_res[i]);	
	}

	return Buffer;
}


