#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
#include "coordlinklist.h"
#include "celllinklist.h"
//#include "dnalinklist.h"
struct cellNode *cellHead = NULL;
#define gridH 30
#define gridW 100
//int gridH=10;
//int gridW=10;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

//important for passing multiple args to thread fnction
struct arg_struct {
    int rows;
    int columns;
    int curr;
};


/*
struct cell {
    int health;
    int counted;
    int surrounded;
    int posx;
    int posy;
  };
*/

struct cell cells[gridH][gridW];
char *fordraw[gridH][gridW];


//attack a random surrounding space if there are living cell surrounding it
int currAttacks[gridH][gridW];


int deadCount=0;
int randomCellect;
int first=0;
// The function to be executed by all threads 


void *threadFun(void *arguments){ 
          
          pthread_mutex_lock(&m);
          
  
          struct arg_struct *args = arguments;
          int rows=args->rows;
          int columns=args->columns;
     
          if(first==0){cells[rows][columns].cancerous=1;}
          if(first==1){cells[rows][columns].benign=1;first++;}
          
          printf("\n rows: %d columns: %d\n",rows,columns);
          
     first++;
     //usleep(2500);
     
     pthread_mutex_unlock(&m);
     //clear();
     
} 
  
int main(int argc, char *argv[]){ 

    //pthread_t tid[gridH*gridW];

    //struct arg_struct args;


               struct cellNode *cellHead=NULL;
               struct cell currCell=cells[0][0];
               currCell.rows=1;
               currCell.columns=1;
               cellinsert(cellHead,currCell);
	       cellinsert(cellHead,currCell);
	       printf("cells: %d\n",cellcount(cellHead));

/*
    int tidIndex=0;


                if(tidIndex==gridH*gridW){tidIndex=0;}
                args.rows = cellget(randomCellect).rows;
                args.columns = cellget(randomCellect).columns;
                
                
                pthread_create(&tid[tidIndex],NULL,threadFun, (void *)&args);
		
                pthread_join(tid[tidIndex],NULL);
                
                randomCellect=rand() % cellcount(cellHead);
               
                tidIndex++;*/
               
    return 0; 
} 
