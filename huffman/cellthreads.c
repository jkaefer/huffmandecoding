#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 

//#include "coordlinklist.h"
#include "celllinklist.h"

#define gridH 2
#define gridW 2

struct cellNode *location[16];
struct cell cells[16];
//char *fordraw[gridH][gridW];



  
int main(int argc, char *argv[]){ 
    

    int currind=0;
    struct cell currCell;
    for(int rows=0;rows<16;rows++){
	    
               currCell=cells[rows];
            
               cellinsert(0,currCell);
               
               location[rows]=cellNodeget(0,currind);
               currind++;
               
	       //codoninsert(struct cellNode *tempcell,struct codon data);
 	       
				
    }

    struct codon tempcodon;
    tempcodon.data=1;
    codoninsert(location[0],tempcodon);
    printf("stored %d\n",codonget(location[0],0).data);
    
 
     
    return 0; 
} 
