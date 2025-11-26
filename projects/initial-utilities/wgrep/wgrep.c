/*
 * File:        wgrep.c
 * Author:      Efe Murat Uçarlı
 * Date:        2025-11-26
 * Description: A simple grep-like program that searches for a pattern and 
                prints matching lines from the given files in order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char* dynamicBuffer = NULL;
    size_t size = 0;
    ssize_t nread;

    if(argc == 2){
        while((nread = getline(&dynamicBuffer, &size, stdin)) != -1){
            if(strstr(dynamicBuffer,argv[1])){
                printf("%s", dynamicBuffer);
            }
        }
        free(dynamicBuffer);
        return 0;
    }
    
    if(argc >= 3){
        for(int i = 2; i < argc; i++){
            FILE* fp = fopen(argv[i], "r");
            if(fp == NULL){
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            
            while((nread = getline(&dynamicBuffer, &size, fp)) != -1){
                if(strstr(dynamicBuffer,argv[1])){
                    printf("%s", dynamicBuffer);
                }
            }
            
            free(dynamicBuffer);
            fclose(fp);
            return 0;
        } 
    }
}