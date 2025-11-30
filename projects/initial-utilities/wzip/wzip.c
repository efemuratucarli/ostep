/*
 * File:        wzip.c
 * Author:      Efe Murat Uçarlı
 * Date:        2025-12-01
 * Description: A simple file compression program that performs run-length
 *              encoding (RLE). It reads the given files in order, counts
 *              consecutive repeating characters, and writes each run as a
 *              4-byte integer (count) followed by the character. The output
 *              is written to stdout in a compact binary format.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[]){
  if(argc == 1){
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

  if(argc >= 2){
    int c = -1;
    int flag = 0;
    int prev = -1;
    uint32_t counter = 0;
    
    for(int i = 1; i < argc; i++){
      FILE* fp = fopen(argv[i], "r");
      
      while ((c = fgetc(fp)) != -1){
        if(!flag){
          flag = 1;
          prev = c;
          counter = 1;
        }
        
        else{
            if(prev == c){
              counter++;
            }
            
            else{
              unsigned char prevChar = (unsigned char) prev; //int to byte conversion
              fwrite(&counter,4,1,stdout);
              fwrite(&prevChar,1,1,stdout);
              counter=1;
              prev=c;
            }
        }
      }
        if((i+1) == argc){
          unsigned char prevChar = (unsigned char) prev;
          fwrite(&counter,4,1,stdout);
          fwrite(&prevChar,1,1,stdout);
        }
        fclose(fp);
    }
  }
}
