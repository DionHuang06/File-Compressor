#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {

   char filename[100];
   FILE *fptr;

   printf("Enter the file name: \n");
   scanf("%99s", filename);
   fptr = fopen(filename, "r");
   
   int numbers[26];
   char myString[100];
   while (fgets(myString, sizeof(myString), fptr)) {
   }
   
   int strlength = strlen(myString);
   int counter1 = 0;
   for(int i = 97; i <= 122; i++) {
      int temp=0;
      for(int q = 0; q < strlength ; q++){
         if(myString[q]==i){
            temp = temp+1;
         }
      }
      numbers[counter1++] = temp;
   }
   fclose(fptr);
   
   int arr[26][2] = {};
   int counter2 = 0;
   int counter3 = 0;
   int counter4 = 0;
   for(int k = 97; k <= 122; k++) {
      arr[counter2++][0] = k;
      arr[counter3++][1] = numbers[counter4++];
   }
   const char *huffmanCodes[] = {
      "00", "01", "100", "101", "110", "1110", "11110", "11111",
      "0000", "0001", "0010", "00110", "00111", "01000", "01001",
      "01010", "01011", "01100", "01101", "01110", "01111", "10000",
      "10001", "10010", "10011", "10100"
   };
   bubbleSort(arr,26);

   char binaryStr[1000] = "";
   for(int v = 0; v < strlength; v++) {
      for(int y = 0; y < 26; y++) {
         if(myString[v]==arr[y][0]){
            strcat(binaryStr,huffmanCodes[y]);
         }
      }
   }
   FILE *bfile = fopen("output.bin", "wb");


   char *temp = binaryStr;
   int remainder = strlen(binaryStr)%8;
   for (int q = 0; q < (strlen(binaryStr) / 8) + 1; q++) {
      uint8_t result = binaryStringToByte(temp);
      size_t bytesWritten = fwrite(&result, sizeof(uint8_t), 1, bfile);
      temp += 8;
   }
   fclose(bfile);
   printf("Character to Binary Mapping:\n");
   for (int v = 0; v < strlength; v++) {
      for (int y = 0; y < 26; y++) {
         if (myString[v] == arr[y][0]) {
            printf("%c: %s\n", myString[v], huffmanCodes[y]); 
            strcat(binaryStr, huffmanCodes[y]);
         }
      }
   }
}
