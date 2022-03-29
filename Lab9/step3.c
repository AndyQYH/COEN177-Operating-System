#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 3)
    {
        printf("wrong input format");
        return -1;
    }
    char buffer[atoi(argv[2])]; 
    FILE *fp;
    fp = fopen(argv[1], "rb"); 
    while (fread(buffer, sizeof(buffer), 1, fp)){
    }
    
    fclose(fp);


    return 0;
}