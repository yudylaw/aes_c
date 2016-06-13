#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include "aes256.h"

// Fill in actual key here
static const uchar ckey[] = "VsuKiZvQpe2R+TSiWNRdBlNS";

void print(const char *str, uchar *in, uchar *out)
{
    // Print in hex because encrypted data is not always ASCII-friendly ;-)

    int i;

    printf("%s\n", str);
    printf("Input:\t");
    for (i = 0; i < AES_BLOCK_SIZE; i++)
        printf("%x", in[i]);
    printf("\n");
    printf("Output:\t");
    for (i = 0; i < AES_BLOCK_SIZE; i++)
        printf("%x", out[i]);
    printf("\n\n");
}

void Encrypt(uchar *in, uchar *out, int debug)
{
    static int firstRun = 1;
    static AES_KEY encryptKey;

    if (firstRun == 1)
    {
        AES_set_encrypt_key(ckey, 256, &encryptKey);
        firstRun = 0;
    }

    AES_ecb_encrypt(in, out, &encryptKey, AES_ENCRYPT);

    if (debug)
        print("Encryption:", in, out);
}

void Decrypt(uchar *in, uchar *out, int debug)
{
    static int firstRun = 1;
    static AES_KEY decryptKey;

    if (firstRun == 1)
    {
        AES_set_decrypt_key(ckey, 256, &decryptKey);
        firstRun = 0;
    }

    AES_ecb_encrypt(in, out, &decryptKey, AES_DECRYPT);

    if (debug)
        print("Decryption:", in, out);
}

void Encrypt32(uchar *in, uchar *out, int debug)
{
    static int firstRun = 1;
    static AES_KEY encryptKey;

    if (firstRun == 1)
    {
        AES_set_encrypt_key(ckey, 256, &encryptKey);
        firstRun = 0;
    }   

    AES_ecb_encrypt(in, out, &encryptKey, AES_ENCRYPT);
    AES_ecb_encrypt(&in[AES_BLOCK_SIZE], &out[AES_BLOCK_SIZE], &encryptKey, AES_ENCRYPT);

    if (debug)
        print("Encryption:", in, out);
}

void Decrypt32(uchar *in, uchar *out, int debug)
{
    static int firstRun = 1;
    static AES_KEY decryptKey;

    if (firstRun == 1)
    {
        AES_set_decrypt_key(ckey, 256, &decryptKey);
        firstRun = 0;
    }   

    AES_ecb_encrypt(in, out, &decryptKey, AES_DECRYPT);
    AES_ecb_encrypt(&in[AES_BLOCK_SIZE], &out[AES_BLOCK_SIZE], &decryptKey, AES_DECRYPT);

    if (debug)
        print("Decryption:", in, out);
}

