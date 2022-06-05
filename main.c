#include <stdint.h>
#include <stdio.h>

union UnionDetectEndian {
    uint8_t u8;
    __attribute__((unused))
    uint16_t u16;
};

int main() {
    union UnionDetectEndian theUnion;
    theUnion.u16 = 0x1234;
    if (theUnion.u8 == 0x12) {
        printf("big endian\n");
    } else if (theUnion.u8 == 0x34) {
        printf("little endian\n");
    } else {
        printf("detect endian failed!\n");
    }
    return 0;
}
