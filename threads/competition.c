#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
#include "coordlinklist.h"
#include "celllinklist.h"
//#include "dnalinklist.h"

#define gridH 30
#define gridW 100
#define mutrate 2 //this is the frequency of mutations
#define timestomut 2 //max mutations allowed per sequence
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
struct cellNode *location[gridH][gridW];
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
          //if(currAttacks[rows][columns]==1){
		//	       cells[rows][columns].health=0;
		//	    }
          //healthy cell
          int prevInd=0;
          if(location[rows][columns]->data.cancerous==1){
          

			    struct coord N={rows-1,columns};
			    struct coord S={rows+1,columns};
			    struct coord E={rows,columns+1};
			    struct coord W={rows,columns-1};
			    struct coord NE={rows-1,columns+1};
			    struct coord NW={rows-1,columns-1};
			    struct coord SE={rows+1,columns+1};
			    struct coord SW={rows+1,columns-1};
                            
			    if((cells[N.rows][N.columns].cancerous!=1)&&(rows!=0))
                                insert(N);
                            if((cells[S.rows][S.columns].cancerous!=1)&&(rows!=gridH))
                                insert(S);
			    if((cells[E.rows][E.columns].cancerous!=1)&&(columns!=gridW))
                                insert(E);
                            if((cells[W.rows][W.columns].cancerous!=1)&&(columns!=0))
                                insert(W);
                            if((cells[NE.rows][NE.columns].cancerous!=1)&&(rows!=0)&&(columns!=gridW))
                                insert(NE);
                            if((cells[NW.rows][NW.columns].cancerous!=1)&&(rows!=0)&&(columns!=0))
                                insert(NW);
			    if((cells[SE.rows][SE.columns].cancerous!=1)&&(rows!=gridH)&&(columns!=gridW))
                                insert(SE);
                            if((cells[SW.rows][SW.columns].cancerous!=1)&&(rows!=gridH)&&(columns!=0))
                                insert(SW);
                            
                            //usleep(400);
		            //printf("\n count(): %d\n",count());
                           
			    //accounts for unattackable cells
                        if(count()!=0){
			    int random=rand() % count();
                            

                            //int cellAttack[2]={get(random).rows,get(random).columns};
			    //cellAttack={random.rows,random.columns};//rand between 0 and the number that are available

			    
			    
			    
           
		 	    //attacked cells are immediately dead
  			    cells[get(random).rows][get(random).columns].benign=0;
			    cells[get(random).rows][get(random).columns].cancerous=1;
                            fordraw[get(random).rows][get(random).columns]="c";
                            //cancerCount++;
                            //remove all coords from structure
                            coordremoveAll();
                         }
			    
		

             }//end parens for nondead cells
             //dead cell, can't attack
             if(cells[rows][columns].benign==1){
          
			    //update cell status
			    //cells[rows][columns];


                            
                            int canAttack=0;

			    struct coord N={rows-1,columns};
			    struct coord S={.rows=rows+1,.columns=columns};
			    struct coord E={.rows=rows,.columns=columns+1};
			    struct coord W={.rows=rows,.columns=columns-1};
			    struct coord NE={.rows=rows-1,.columns=columns+1};
			    struct coord NW={.rows=rows-1,.columns=columns-1};
			    struct coord SE={.rows=rows+1,.columns=columns+1};
			    struct coord SW={.rows=rows+1,.columns=columns-1};
                            
			    if((cells[N.rows][N.columns].benign!=1)&&(rows!=0))
                                insert(N);
                            if((cells[S.rows][S.columns].benign!=1)&&(rows!=gridH))
                                insert(S);
			    if((cells[E.rows][E.columns].benign!=1)&&(columns!=gridW))
                                insert(E);
                            if((cells[W.rows][W.columns].benign!=1)&&(columns!=0))
                                insert(W);
                            if((cells[NE.rows][NE.columns].benign!=1)&&(rows!=0)&&(columns!=gridW))
                                insert(NE);
                            if((cells[NW.rows][NW.columns].benign!=1)&&(rows!=0)&&(columns!=0))
                                insert(NW);
			    if((cells[SE.rows][SE.columns].benign!=1)&&(rows!=gridH)&&(columns!=gridW))
                                insert(SE);
                            if((cells[SW.rows][SW.columns].benign!=1)&&(rows!=gridH)&&(columns!=0))
                                insert(SW);
                            
                            //usleep(400);
		            //printf("\n count(): %d\n",count());
                           
			    //accounts for unattackable cells
                        if(count()!=0){
			    int random=rand() % count();
                            

                            //int cellAttack[2]={get(random).rows,get(random).columns};
			    //cellAttack={random.rows,random.columns};//rand between 0 and the number that are available

           
		 	    //attacked cells are immediately dead
                            cells[get(random).rows][get(random).columns].cancerous=0;
			    cells[get(random).rows][get(random).columns].benign=1;
                            fordraw[get(random).rows][get(random).columns]="b";
                            //cancerCount++;
                            //remove all coords from structure
                            coordremoveAll();
                         }
			    
             }

        //drawing of grid
     


        int prevRow=0;
        //printf("\n");
        //erase();
     
        




        //usleep(5000);
        //clear();
        //usleep(500);
        //wgetch();
        for (int rows=0;rows<gridH;rows++){
    	    for(int columns=0;columns<gridW;columns++){
                //refresh();
                //if(prevRow!=rows){printw("\n"); prevRow++;}
		mvprintw(rows,columns,"%s",fordraw[rows][columns]);
                //refresh();
                //sleep (1);
               /*if(prevRow!=rows){printf("\n"); prevRow++;}
               //if(cells[rows][columns].health==0)
               printf(fordraw[rows][columns]);*/
    	    }
            //refresh();
        } 
        //refresh();
        //usleep(20000);
        
        //refresh ();
       //printf("\n count(): %d \n cellcount(): %d\n deadCount: %d\n randomCellect: %d\n",count(),cellcount(),deadCount,randomCellect);
     first++;
     //usleep(2500);
     
     pthread_mutex_unlock(&m);
     //clear();
     
} 
  
int main(int argc, char *argv[]){ 
    //initscr ();
    //curs_set(0);
        
        
        
    srand(time(0));
    //int rand2=rand()%0;
    //int rows=0;
    //int columns=0;
   
    pthread_t tid[gridH*gridW];


    //argument struct passed to threadfunc
    struct arg_struct args;

    //initialize cell health to 100, and fill linkedlist
    //pthread_mutex_lock(&m);
    int currind=0;
    struct cell currCell;
    for(int rows=0;rows<gridH;rows++){
	    for(int columns=0;columns<gridW;columns++){
               fordraw[rows][columns]=" ";
               currCell=cells[rows][columns];
               currCell.rows=rows;
               currCell.columns=columns;
               cellinsert(0,currCell);
               cellinsert(1,currCell);
               location[rows][columns]=cellgetNode(currind);
               currind++;
            }
    }
    //printf("%d\n",cells[1][1].health);
    //pthread_mutex_unlock(&m);
    
    //running till up to 50% of the cells are dead
    int tidIndex=0;
    //randomCellect=rand() % cellcount();


    //select cell to be cancerous at random

    //if(randomCellect==0){
      //printf("is zero\n");
    //}
    //initscr ();
        
        //curs_set (0);
    while(deadCount<((gridH*gridW)/2)){
                if(tidIndex==gridH*gridW){tidIndex=0;}
                if(cellcount(1)==0){
                	randomCellect=0;
                }
                else{
 			rand() % cellcount(1);
                }
                args.rows = cellget(1,randomCellect).rows;
                args.columns = cellget(1,randomCellect).columns;

                

                pthread_create(&tid[tidIndex],NULL,threadFun, (void *)&args);
		//tidIndex++;
                //}

                pthread_join(tid[tidIndex],NULL);
                
                
                if((cellcount(1)==0)&&randomCellect==0){
			cellremoveFirstNode(1);
                        if(cellcount(1)==0){
			  break;
			}
		}
		else{
			cellremoveNode(randomCellect);
		}


                tidIndex++;
               
                
        
    }
    //printf("\n randomCellect: %d \n count(): %d \n",randomCellect, cellcount());
    /*
    printf("\ndead count = %d\n",deadCount);
    for (int rows=0;rows<gridH;rows++){
    	    for(int columns=0;columns<gridW;columns++){
               if(cells[rows][columns].health==0)
                  printf("dead at: rows: %d columns: %d\n",rows,columns);
    	    }
        } 
       */
    /* End ncurses mode */
       // endwin();
    //pthread_exit(NULL); 
    return 0; 
} 
