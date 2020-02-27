//gcc -o singftest singftest.c -g
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
//#include "coordlinklist.h"
#include "celllinklist2.h"

#define gridH 30
#define gridW 100
//int gridH=10;
//int gridW=10;

struct cellNode *maincells2 = NULL;
  


int main(int argc, char *argv[]){ 

    srand(time(0));
    struct cell cells[3][3];

    struct cell currCell=cells[0][0];
    for(int i=0;i<5;i++){
	currCell.rows=i;
    	cellinsert(&maincells2,currCell);
    }
    //cellinsert(&maincells2,currCell);
    //cellinsert(&maincells,currCell);
    //cellinsert(&maincells2,currCell);
    //cellinsert(&maincells2,currCell);
    //printf("%d\n",cellcount(&maincells2));
    //cellremoveFirstNode(&maincells2);
    cellremoveNode(&maincells2,0);
    printf("%d\n",cellget(&maincells2,0).rows);
    //printf("%d\n",cellget(&maincells2,1).rows);
    printf("%d\n",cellcount(&maincells2));
    
    return 0; 
} 
