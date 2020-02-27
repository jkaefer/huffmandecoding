#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include "coordlinklist.h"
#include "celllinklist.h"

#define gridH 50
#define gridW 50
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




//attack a random surrounding space if there are living cell surrounding it
int currAttacks[gridH][gridW];


int deadCount=0;


// The function to be executed by all threads 
void *threadFun(void *arguments){ 

          pthread_mutex_lock(&m);
          
          struct arg_struct *args = arguments;
          int rows=args->rows;
          int columns=args->columns;
          printf("rows: %d columns: %d\n",rows,columns);
   
          if(currAttacks[rows][columns]==1){
			       cells[rows][columns].health=0;
			    }
          //healthy cell
          if(cells[rows][columns].health==100){
                 printf("liveCell\n");
			    //update cell status
			    cells[rows][columns];


                            
                            int canAttack=0;

			    struct coord N={rows+1,columns};
			    struct coord S={.rows=rows-1,.columns=columns};
			    struct coord E={.rows=rows,.columns=columns+1};
			    struct coord W={.rows=rows,.columns=columns-1};
			    struct coord NE={.rows=rows+1,.columns=columns+1};
			    struct coord NW={.rows=rows+1,.columns=columns-1};
			    struct coord SE={.rows=rows-1,.columns=columns+1};
			    struct coord SW={.rows=rows-1,.columns=columns-1};
                            
			    if(currAttacks[N.rows][N.columns]!=1)
                                insert(N);
                            if(currAttacks[S.rows][S.columns]!=1)
                                insert(S);
			    if(currAttacks[E.rows][E.columns]!=1)
                                insert(E);
                            if(currAttacks[W.rows][W.columns]!=1)
                                insert(W);
                            if(currAttacks[NE.rows][NE.columns]!=1)
                                insert(NE);
                            if(currAttacks[NW.rows][NW.columns]!=1)
                                insert(NW);
			    if(currAttacks[SE.rows][SE.columns]!=1)
                                insert(SE);
                            if(currAttacks[SW.rows][SW.columns]!=1)
                                insert(SW);
				
   	
                            canAttack=count();	
		
			    //accounts for unattackable cells
			    struct coord random=get(rand() % (canAttack+1));
                            int cellAttack[2]={random.rows,random.columns};
			    //cellAttack={random.rows,random.columns};//rand between 0 and the number that are available

			    
			    int prevInd=0;
			    int missCount=0;
           
		 	    //setting up cell attack
			    currAttacks[cellAttack[0]][cellAttack[1]]=1;
			    
		

             }//end parens for nondead cells
             //dead cell, can't attack
             if((cells[rows][columns].health==0)&&(cells[rows][columns].counted==0)){
                //printf("%d\n",rows);
                //printf("%d\n",cells[rows][columns].health);
                printf("deadCell\n");
                deadCount++;
                cells[rows][columns].counted=1;
             }



        //drawing of grid
        int prevRow=0;
        for (int rows=0;rows<gridH;rows++){
    	    for(int columns=0;columns<gridW;columns++){
               if(prevRow!=rows){printf("\n"); prevRow++;}
               if(cells[rows][columns].health==0)
                  printf(" ");
               else
                  printf("*");
    	    }
        } 


     pthread_mutex_unlock(&m);
     
} 
  
int main(int argc, char *argv[]){ 
    //int rows=0;
    //int columns=0;
   
    pthread_t tid[gridH*gridW];

    //argument struct passed to threadfunc
    struct arg_struct args;

    //initialize cell health to 100, and fill linkedlist
    //pthread_mutex_lock(&m);
    for(int rows=0;rows<gridH;rows++){
	    for(int columns=0;columns<gridW;columns++){
               cells[rows][columns].health=100;
               cellinsert(cells[rows][columns]);
            }
    }
    //printf("%d\n",cells[1][1].health);
    //pthread_mutex_unlock(&m);
    
    //running till up to 50% of the cells are dead
    int tidIndex=0;
    //int cellcount=cellcount();
    int randomCellect=rand % cellcount();
    while(deadCount<((gridH*gridW)/2)){
    	//for(int rows=0;rows<gridH;rows++){
	  //  for(int columns=0;columns<gridW;columns++){
                //printf("hello\n");
                //args.curr= tidIndex;
                //args.rows = rows;
                //args.columns = columns;
                //struct cell=getcell(randomCellect);
                args.rows = getcell(randomCellect).rows;
                args.columns = getcell(randomCellect).columns;
                pthread_create(&tid[tidIndex],NULL,threadFun, (void *)&args);
		//pthread_join(&tid[tidIndex],NULL);
                //printf("%d\n",columns);
                tidIndex++;
                cellremoveNode(randomCellect);
                //cellcount=cellcount();
                randomCellect=rand % cellcount();
                //without sleep skips some
                usleep(50000);
                //sleep(1);
          //  }
        //}
        tidIndex=0;
        //for (int rows=0;rows<gridH;rows++){
    	  //  for(int columns=0;columns<gridW;columns++){
                args.rows = rows;
                args.columns = columns;
        	pthread_join(tid[tidIndex],NULL);
    	    //}
        //} 
        
    }
    
    printf("\ndead count = %d\n",deadCount);
    //pthread_join(&tid,NULL);
    //list dead cells
    for (int rows=0;rows<gridH;rows++){
    	    for(int columns=0;columns<gridW;columns++){
               if(cells[rows][columns].health==0)
                  printf("dead at: rows: %d columns: %d\n",rows,columns);
    	    }
        } 
       

    //pthread_exit(NULL); 
    return 0; 
} 
