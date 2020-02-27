#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
#include "coordlinklist.h"
#include "celllinklist2.h"

#define gridH 30
#define gridW 100
//int gridH=10;
//int gridW=10;

struct cellNode *maincells = NULL;
  
int main(int argc, char *argv[]){ 

    srand(time(0));
    struct cell cells[3][3];

    struct cell currCell=cells[0][0];
    currCell.rows=0;
    currCell.columns=0;
    cellinsert(&maincells,currCell);
    cellinsert(&maincells,currCell);
    //cellinsert(&maincells,currCell);
    //cellinsert(&maincells,currCell);
    //cellinsert(&maincells,currCell);
    //cellremoveFirstNode(&maincells);
    //int rows = cellget(maincells,1).rows;
    printf("%d\n",cellget(maincells,1).rows);
    //cellget(&maincells,randomCellect)
    //printf("%d\n",cellcount(&maincells));
    
    return 0; 
} 
