#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
#include "coordlinklist.h"
#include "celllinklist.h"


#define gridH 30
#define gridW 100
//int gridH=10;
//int gridW=10;



struct cell cells[gridH][gridW];
 
int currind=0;

  
int main(int argc, char *argv[]){ 
    char randchars[3]={'a','b','c'};
    srand(time(0));
    struct pair data;
    for(int rows=0;rows<gridH;rows++){
	    for(int columns=0;columns<gridW;columns++){
               struct cell currCell=cells[rows][columns];
               //printf("%c\n",randchars[0]);
               cellinsert(currCell);
               data.base= randchars[rand()%3];
               pairinsert(cellNodeget(currind),data);
               currind++;//to keep track of index in celllinkedlist
            }
    }
    
    //struct cell currCell=cells[0][0];
    //cellinsert(currCell);
    //struct pair data;
    //data.base="b";
    //pairinsert(0,data);
    for(int i=0;i<gridH*gridW;i++){
     printf("%c\n",pairget(cellNodeget(i),0).base);
    }

  
    return 0; 
} 
