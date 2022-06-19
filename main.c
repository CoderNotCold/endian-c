#include <stdint.h>
#include <stdio.h>

union UnionDetectEndian {
    uint8_t u8;
    __attribute__((unused))
    uint16_t u16;
};

void byUnion() {
    union UnionDetectEndian theUnion;
    theUnion.u16 = 0x1234;
    if (theUnion.u8 == 0x12) {
        printf("byUnion:big endian\n");
    } else if (theUnion.u8 == 0x34) {
        printf("byUnion:little endian\n");
    } else {
        printf("byUnion:detect endian failed!\n");
    }
}

void byCast() {
    uint16_t a = 0x1234;
    uint8_t firstByte = *((uint8_t *) &a);
    if (firstByte == 0x12) {
        printf("byCast:big endian\n");
    } else if (firstByte == 0x34) {
        printf("byCast:little endian\n");
    } else {
        printf("byCast:detect endian failed!\n");
    }
}

int main() {
    byUnion();
    byCast();
    return 0;
}

