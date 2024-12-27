#include <stdint.h>
#include <stdio.h>

void bubbleSort(int arr[26][2], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j][1] < arr[j+1][1]) {
                int temp0 = arr[j][0];
                int temp1 = arr[j][1];
                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j+1][0] = temp0;
                arr[j+1][1] = temp1;
            }
        }
    }
}

uint8_t binaryStringToByte(char *binaryStr) {
    uint8_t byte = 0;
    for (int i = 0; i < 8 && *binaryStr; i++) {
        byte <<= 1;
        if (*binaryStr == '1') {
            byte |= 1;
        }
        binaryStr++;
    }
    return byte;
}
