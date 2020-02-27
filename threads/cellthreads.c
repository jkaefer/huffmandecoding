#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <time.h> 
#include <pthread.h> 
#include <ncurses.h>
#include "coordlinklist.h"
#include "celllinklist.h"

//#include "aminoacids.h"
//#include "dnalinklist.h"

#define gridH 2
#define gridW 2
#define numinternalcodons 2
#define mutrate 2 //this is the frequency of mutations
#define timestomut 2 //max mutations allowed per sequence
//int gridH=10;
//int gridW=10;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

//important for passing multiple args to thread fnction
struct arg_struct {
    int rows;
    int columns;
    int det;
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
int numcancer=0;
int randomCellect;
int first=0;
int mutnow=0;
// The function to be executed by all threads 


void *threadFun(void *arguments){ 
          
          pthread_mutex_lock(&m);
          
  
          struct arg_struct *args = arguments;
          int rows=args->rows;
          int columns=args->columns;
          int det =args->det;
           

          struct pair tempair={'T','A'};

          char tempchar='A';

          int randpairind=0;
          

          if(strlen(location[rows][columns]->data.genome)==0){
             randpairind=0;
          }
          else{
	     randpairind=rand()%strlen(location[rows][columns]->data.genome);
          }
          if((mutnow==mutrate)&&(location[rows][columns]->data.mutations<1)){
	     location[rows][columns]->data.genome[randpairind];
             //pairedit(location[rows][columns],tempair,randpairind);
             location[rows][columns]->data.mutations++;
             

		   if(location[rows][columns]->data.genome[0]!='A'||location[rows][columns]->data.genome[1]!='T'||location[rows][columns]->data.genome[2]!='G'){
		      location[rows][columns]->data.cancerous=1;
                      numcancer++;
		   }



             mutnow=0;
		
	  }
          //numcancer++;
          mutnow++;
		  
	  printf("%d\n",strlen(location[rows][columns]->data.genome));
	  printf("%c\n",location[rows][columns]->data.genome[1]);
          //pairprintlist(location[rows][columns]);
          printf("%d\n",mutnow);
          numcancer++;


          //healthy cell
          int prevInd=0;
          
     first++;
//*********************next issue************************************************************
	  //simulate translation
	  //codonify(location[rows][columns],numinternalcodons+2);
	  //aminify(location[rows][columns],numinternalcodons+2);
	  //printf("%s\n",location[rows][columns]->data.aminochain);
	  //location[rows][columns]->data

	
     //usleep(2500);
     
     pthread_mutex_unlock(&m);
     //clear();
     
} 
  
int main(int argc, char *argv[]){ 
    //initscr ();
    //curs_set(0);
        
        
	FILE *fp=fopen("sequence.txt","r");
	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);  /* same as rewind(f); */

	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, fp);
	fclose(fp);
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
               location[rows][columns]=cellNodeget(0,currind);
               currind++;
		//at this time putting entire genome into genome
  		location[rows][columns]->data.genome=string;
		//printf("%s\n",location[rows][columns]->data.genome);
               /*
               char *sequence[numinternalcodons]={"CAT","GAT"};
	       char *sequence2[numinternalcodons]={"CAT","GAT"};
               
               //insert start codon
 	       struct pair tempair={'A','T'};
	       pairinsert(location[rows][columns],tempair);
	       struct pair tempair2={'T','A'};
	       pairinsert(location[rows][columns],tempair2);
	       struct pair tempair3={'G','C'};
	       pairinsert(location[rows][columns],tempair3);
				


               //insert internal codons

	       for(int i=0;i<numinternalcodons;i++){
		  for(int j=0;j<3;j++){
                     struct pair tempair={sequence[i][j],sequence2[i][j]};
                     pairinsert(location[rows][columns],tempair);
		  }
	       }

               //insert stop codon
               struct pair tempair4={'T','A'};
	       pairinsert(location[rows][columns],tempair4);
	       struct pair tempair5={'A','T'};
	       pairinsert(location[rows][columns],tempair5);
	       struct pair tempair6={'A','T'};
	       pairinsert(location[rows][columns],tempair6);
		*/

            }
    }
    
    int tidIndex=0;
    //randomCellect=rand() % cellcount();


    //select cell to be cancerous at random

    //if(randomCellect==0){
      //printf("is zero\n");
    //}
    //initscr ();
        
        //curs_set (0);
    while(numcancer<4){
                if(tidIndex==gridH*gridW){tidIndex=0;}
                if(cellcount(1)==0){
                	randomCellect=0;
                }
                else{
 			rand() % cellcount(1);
                }
                args.rows = cellget(1,randomCellect).rows;
                args.columns = cellget(1,randomCellect).columns;
                //if(

                

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
			cellremoveNode(1,randomCellect);
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
