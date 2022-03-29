#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct {//to 
    int pageno;
    bool second_chance;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i, placeInArray = 0, count = 0;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].second_chance = false;
    }

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
                cache[i].second_chance = true;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){
            //printf("page fault on page: %d \n", cache[placeInArray].pageno);
            //printf("place in array: %d \n", placeInArray);
            //printf("has second chance: %d \n", cache[placeInArray].second_chance);
            while(cache[placeInArray].second_chance)
            {
               
                cache[placeInArray].second_chance = false;
                placeInArray = (placeInArray + 1) % CACHE_SIZE;
            }

                
            cache[placeInArray].pageno = page_num;
            placeInArray = (placeInArray + 1) % CACHE_SIZE;
            ++totalFaults;
            //printf("page fault : %d \n", totalFaults); 


        }
        /*
        for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
          printf("(%d,%d)\t",cache[i].pageno, cache[i].second_chance);

        printf("\n");
        
        }
        */
    }

    printf("Total Page Faults: %d\n", totalFaults);
    printf("Total Number Of Requests: %d \n", count);
    printf("Total Hit Rate: %.6f \n", ((double)count-totalFaults) / count);
    printf("Total Miss Rate: %.6f \n", 1-(((double)count-totalFaults) / count));
    return 0;



}