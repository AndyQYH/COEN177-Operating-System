#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to 
    int pageno;
    int index;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i, j,placeInArray, lru = 0, count = 0;;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].index = CACHE_SIZE - i - 1;
    }
    //every cycle, each page ages; adds one to the lru index
    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an int
        count++;
    	/*
		Page Replacement Implementation Goes Here 
    	*/
        bool foundInCache = false;
        for (i=0; i<CACHE_SIZE; i++){
            if (cache[i].pageno == page_num){
                foundInCache = true;
                cache[i].index = 0;
                break; //break out loop because found page_num in cache, set lru index to zero becasue we just visited the page
            }
        }
        //adds lru index if not recently visited
        for (j=0; j<CACHE_SIZE; j++){
            if(i != j)
                cache[j].index++;
        }   
        if (foundInCache == false){
            
            //printf("page fault on page: %d \n", cache[placeInArray].pageno);
            //printf("place in array: %d \n", placeInArray);
            
            lru = 0;
            for(i = 0; i < CACHE_SIZE; i++)
            {
                if(cache[i].index > lru)
                {
                    lru = cache[i].index;
                    placeInArray = i;
                }
            }

                
            cache[placeInArray].pageno = page_num;
            cache[placeInArray].index = 0;
            ++totalFaults;
            
            //printf("lru: %d\n", lru);
            //printf("page fault : %d \n", totalFaults); 

        }
        /*
        for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
          printf("(%d,%d)\t",cache[i].pageno, cache[i].index);
        }
        printf("\n");
        */
    }
    //logging page faults, total page request,hit rate, miss rate
    printf("Total Page Faults: %d\n", totalFaults);
    printf("Total Number Of Requests: %d \n", count);
    printf("Total Hit Rate: %.6f \n", ((double)count-totalFaults) / count);
    printf("Total Miss Rate: %.6f \n", 1-(((double)count-totalFaults) / count));
    return 0;



}