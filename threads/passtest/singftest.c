//gcc -o singftest singftest.c -g
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

struct cellNode *maincells2 = NULL;
  
void cellinsert(struct cellNode **maincells,struct cell data) {
   //create a link
   struct cellNode *link = (struct cellNode*) malloc(sizeof(struct cellNode));
   struct cellNode *p;
   
   link->data = data;
   //(*link)->data = data;

   //point it to old first cellNode
   link->next = NULL;
   //(*link)->next = NULL;
   
   if((*maincells) == NULL){
	(*maincells) = link;     //when linked list is empty
	printf("isnull\n");
    }
    else{
	printf("notnull\n");
	p  = (*maincells);//assign head to p 
	while(p->next != NULL){
	    printf("timesnotnull\n");
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
        p->next = link;
	//(*p)->next = (*link);//Point the previous last cellNode to the new cellNode created.
    }
    
   //point first to new first cellNode
   //head = link;
}
/*void cellinsert(struct cellNode **maincells,struct cell data) {
   //create a link
   struct cellNode *link = (struct cellNode*) malloc(sizeof(struct cellNode));
   struct cellNode **p;
   
   link->data = data;
   //(*link)->data = data;

   //point it to old first cellNode
   link->next = NULL;
   //(*link)->next = NULL;
   
   if((*maincells) == NULL){
	(*maincells) = link;     //when linked list is empty
	printf("isnull\n");
    }
    else{
	printf("notnull\n");
	p  = maincells;//assign head to p 
	while((*p)->next != NULL){
	    printf("timesnotnull\n");
	    (*p) = (*p)->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
        (*p)->next = link;
	//(*p)->next = (*link);//Point the previous last cellNode to the new cellNode created.
    }
    
   //point first to new first cellNode
   //head = link;
}*/

void cellremoveFirstNode(struct cellNode **maincells){
  struct cellNode *current;
	  if((*maincells)!=NULL){
		    current=(*maincells);
		    (*maincells)=(*maincells)->next;
		    free(current);
	  }
}

int cellcount(struct cellNode **maincells){
   int size = 0;
   struct cellNode **link;
   if((*maincells)==NULL) {
      return size;
   }

   link = maincells;            
   while((*link) != NULL) {
      (*link) = (*link)->next;
      size++;
   }
   return size;
  
}
struct cell cellget(struct cellNode **maincells,int index) {
   struct cell data;
   //create a link
   struct cellNode *p;
   
        
	p  = (*maincells);//assign head to p 
	int i;
	if(index==0){
	  data=p->data;
	}
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
   

   return data;
   //point first to new first cellNode
   //head = link;
}
void cellremoveNode(struct cellNode **maincells,int index){
   //create a link
   struct cellNode *current;
   if(index==0){
   	if((*maincells)!=NULL){
		    current=(*maincells);
		    (*maincells)=(*maincells)->next;
		    free(current);
	  }
   }
   else{
   //struct cellNode *current;
	struct cellNode *previous;
	current = (*maincells);//assign head to p 
	 
	for(int i=0;i<index;i++){
	     previous=current;
	     current=current->next;
	}
	previous->next=current->next;
	free(current);
   }
  
}

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
