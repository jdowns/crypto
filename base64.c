#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

static const unsigned char enctab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/x=";

void verify(int testcase) {
    if (testcase) {
        puts("  Pass.");
    } else {
        puts("  Fail!");
    }
}

void encode_bytes(uint8_t* bytes, char* result_buffer) {
    //buffer size must be 4! 
    for (int i = 0; i < 4, i++) {
        int idx = bytes[i];
        result_buffer[i] = enctab[idx];
    }
}

uint8_t get_byte(uint32_t string, int place) {
    assert(place < 4);
    uint8_t result = (uint8_t)(string >> 18 - 6 * place);
}

/* Convert 1,2 or 3 characters to a single 24 bit integer */
uint32_t charstoint(unsigned char* in, int len) {
    assert(len < 4);
    uint32_t n = 0;
    for (int i = 0; i < len; i++) {
        int shift = 16 - 8 * i;
        n += ((uint32_t) in[i]) << shift;
    } 
    return n;
}

void test_charstoint() {
    printf("Test convert characters to integer");
    unsigned char in[3] = "Man";
    uint32_t expected = 0x4d616e;
    uint32_t actual = charstoint(in, 3);
    verify(expected == actual); 
}
 
void encode(char* vals, char* buf) {
    //TODO: loop over all the vals
    //TODO: Add = padding to the end
}

void test() {
    test_charstoint();
}

int main() {
    test();
}
