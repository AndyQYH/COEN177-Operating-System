#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 4)
    {
        printf("wrong input format");
        return -1;
    }
    
    char buffer[atoi(argv[2])]; 
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen(argv[1], "rb"); 
    fp2 = fopen(argv[3], "wb"); 
    while (fread(buffer, sizeof(buffer), 1, fp1)){
        fwrite(buffer, sizeof(buffer), 1, fp2);
    }
    
    fclose(fp1);
    fclose(fp2);


    return 0;
}