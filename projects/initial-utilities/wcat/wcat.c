/*
 * File:        wcat.c
 * Author:      Efe Murat Uçarlı
 * Date:        2025-11-22
 * Description: Simple "cat" implementation that prints files in order.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

  if (argc == 1){
    return 0;
  }

  for(int i = 1; i < argc; i++){
    FILE* fp = fopen(argv[i], "r");
    
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    char buffer[100];
    while(fgets(buffer, 100, fp) != NULL){
      printf("%s", buffer);
    }
  } 

  return 0;
}
