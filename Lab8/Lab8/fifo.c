#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    

    int i, placeInArray = 0, count = 0;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){
        bool foundInCache = false;
    	int page_num = atoi(pageCache); // Stores number read from file as an int
        count++;
    	/*
		Page Replacement Implementation Goes Here 
    	*/
        
        for (i=0; i<CACHE_SIZE; i++){
            if (cache[i].pageno == page_num){
                //printf("page found \n");
                foundInCache = true;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){
            //You may print the page that caused the page fault
            //printf("page fault on page: %d \n", cache[placeInArray].pageno);
            //printf("place in array: %d \n", placeInArray);
            cache[placeInArray].pageno = page_num;
            placeInArray = (placeInArray + 1) % CACHE_SIZE;
            ++totalFaults;
            //printf("page fault : %d \n", totalFaults);   
            
        }
        /*
        for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
          printf("%d\t",cache[i].pageno);
        }
        printf("\n");
        */
    }

    printf("Total Page Faults: %d\n", totalFaults);
    printf("Total Number Of Requests: %d \n", count);
    printf("Total Hit Rate: %.6f \n", ((double)count-totalFaults) / count);
    printf("Total Miss Rate: %.6f \n", 1-(((double)count-totalFaults) / count));

    return 0;



}
