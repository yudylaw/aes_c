/*
 * main.c
 *
 *  Created on: Jun 13, 2016
 *      Author: yudylaw
 */

#include <string.h>
#include "aes256.h"
#include "b64.h"

#define BLOCK_SIZE 128

// Test client
int main(int argc, char **argv)
{
    int PRINT = 0, i;
    // Sample input
    uchar in[BLOCK_SIZE] = "yudylaw-yudylaw-yudylaw-yudy-123456789";//max-32, trim
    uchar out[BLOCK_SIZE];

	Encrypt32(in, out, PRINT);

	printf("before b64, out=");

	for (i=0;i<strlen(out);i++) {
		printf("%x", out[i]);
	}

	printf("\n");

	//base64 begin
	char* ch = b64_encode(out, strlen(out));

//	for (i=0;i<strlen(ch);i++) {
//		printf("%x", ch[i]);
//	}
//
//	printf("\n");

	uchar* in2 = b64_decode(ch, strlen(ch));

	printf("after b64, in2=");

	for (i=0;i<strlen(in2);i++) {
		printf("%x", in2[i]);
	}

	printf("\n");

	//base64 end

	uchar out3[BLOCK_SIZE];

	Decrypt32(in2, out3, PRINT);

	for (i=0;i<strlen(out3);i++) {//strlen
		printf("%c", out3[i]);
	}

	printf("\n");


    return 0;
}


