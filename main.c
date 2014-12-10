#include <stdio.h>
#include <string.h>

#include "sconcat.h"
#include "hashfiles/sha.h"
#include "hashfiles/sha1.h"
#include "hashfiles/sha224.h"
#include "hashfiles/sha256.h"
#include "hashfiles/sha384.h"
#include "hashfiles/sha512.h"
#include "hashfiles/md4.h"
#include "hashfiles/md5.h"
#include "hashfiles/whirlpool.h"

int main(int argc, char **argv)
{

	if (argc == 1 || strcmp(argv[1], "--help") == 0) {
		printf("No arguments selected.\nUsage: ./program_name [word]");
	} else if (argc == 2) {

		//SHA
		printf("SHA: %s\n", sha_make((unsigned char*)argv[1]));
	
		//SHA1	
		printf("SHA1: %s\n", sha1_make((unsigned char*)argv[1]));
	
		//SHA224
		printf("SHA224: %s\n", sha224_make((unsigned char*)argv[1]));
		
		//SHA256
		printf("SHA256: %s\n", sha256_make((unsigned char*)argv[1]));
		
		//SHA384
		printf("SHA384: %s\n", sha384_make((unsigned char*)argv[1]));
	
		//SHA512
		printf("SHA512: %s\n", sha512_make((unsigned char*)argv[1]));
	
		//MD4
		printf("MD4: %s\n", md4_make((unsigned char*)argv[1]));
	
		//MD5
		printf("MD5: %s\n", md5_make((unsigned char*)argv[1]));
	
		//WHIRLPOOL
		printf("WHIRLPOOL: %s\n", whirlpool_make((unsigned char*)argv[1]));
	} else if (argc == 3) {
		//SHA
		printf("SHA: %s\n", sha_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//SHA1	
		printf("SHA1: %s\n", sha1_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//SHA224
		printf("SHA224: %s\n", sha224_make((unsigned char*)concat(argv[1], argv[2], NULL)));
		
		//SHA256
		printf("SHA256: %s\n", sha256_make((unsigned char*)concat(argv[1], argv[2], NULL)));
		
		//SHA384
		printf("SHA384: %s\n", sha384_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//SHA512
		printf("SHA512: %s\n", sha512_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//MD4
		printf("MD4: %s\n", md4_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//MD5
		printf("MD5: %s\n", md5_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
		//WHIRLPOOL
		printf("WHIRLPOOL: %s\n", whirlpool_make((unsigned char*)concat(argv[1], argv[2], NULL)));
	
	} else {printf("2manyarguments\n");}

	return 1;
}
