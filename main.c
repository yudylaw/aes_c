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

int main(int argc, char **argv)
{

	//AES: cipherLen = (textLen/16 + 1) * 16

    int i;
    // Sample input
    uchar in[BLOCK_SIZE] = "yudylaw-yudylaw-yudylaw-yudy-123456789-yudylaw-yudylaw-yudylaw-123456";
    uchar out[BLOCK_SIZE];

	Encrypt(in, out);//ecb encode

	//base64 begin
	char* ch = b64_encode(out, strlen(out));

	uchar* in2 = b64_decode(ch, strlen(ch));

	//base64 end

	uchar out2[BLOCK_SIZE];

	Decrypt(in2, out2);

	for (i=0;i<strlen(out2);i++) {
		printf("%c", out2[i]);
	}

	printf("\n");

//	//aes
//
//	uchar in2[BLOCK_SIZE];
//	Decrypt(out, in2);
//
//	for (i=0;i<strlen(in2);i++) {//strlen
//		printf("%c", in2[i]);
//	}
//
//	printf("\n");


    return 0;
}


