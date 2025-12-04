#include <stdio.h>
#include <stdint.h>
#include <stddef.h> //contains the definition of the size_t (official one for the portability)
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc == 1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    for(int z = 1; z < argc; z++){
        FILE* fp = fopen(argv[z], "r");
        if(fp == NULL){
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        
        uint32_t count;
        unsigned char currentElem;

        while(1){
            size_t result1 = fread(&count, 4 , 1, fp);
            if(result1 != 1){
                fclose(fp);
                break;
            }

            size_t result2 = fread(&currentElem, 1, 1, fp);
            if(result2 != 1){
                fclose(fp);
                break;
            }
            
            for(int i = 0; i < count; i++){
                printf("%c", currentElem);
            }
        }
    }
    return 0;
}