#include <stdio.h>
#include "speck.h"

static speck64_t speck_ctx;
static uint8_t key96[12] = {0,1,2,3,4,5,6,7,8,9,1,2}; // 密钥

static uint8_t ori[8] = {1,2,3,4,5,6,7,8}; // 原始明文，一个 block 8 字节，正好 64 位
static uint8_t enc[8] = {0}; // 存放加密得到的密文
static uint8_t back[8]= {0}; // 存放再次解密得到的明文

int main(void)
{
    crypto_speck64_setkey(&speck_ctx, key96, SPECK64_96_KEY_SIZE); // 第 3 个参数 8 位机版本已删掉，进一步减少开销
    crypto_speck64_encrypt(&speck_ctx, enc, ori);
    crypto_speck64_decrypt(&speck_ctx, back, enc);

    printf("enc: %d %d %d %d %d %d %d %d\n", enc[0], enc[1], enc[2], enc[3], enc[4], enc[5], enc[6], enc[7]);
    printf("back: %d %d %d %d %d %d %d %d\n", back[0], back[1], back[2], back[3], back[4], back[5], back[6], back[7]);

    return 0;
}


