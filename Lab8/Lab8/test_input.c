#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer [sizeof(int)];
    int i, someNumber = 20, capNumber = 20;
    fp = fopen("testInput.txt", "w");
    for (i=0; i<someNumber; i++){
        sprintf(buffer, "%d\n", rand()%capNumber);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}