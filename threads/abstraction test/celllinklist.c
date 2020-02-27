#include <stdio.h>
#include <stdlib.h>
#include "celllinklist.h"



//struct cellNode *tempcellnp = NULL;
struct cell tempcell;
//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct cellNode *cellCurrent = NULL;


//display the list
void cellprintList(struct cellNode *tempcellnp) {

   struct cellNode *link;

   link = tempcellnp;            
   while(link != NULL) {
      printf("num:%d \n",link->data);
      link = link->next;
   }
}


void cellinsert(struct cellNode *tempcellnp,struct cell data) {
   //create a link
   struct cellNode *link = (struct cellNode*) malloc(sizeof(struct cellNode));
   struct cellNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first cellNode
   link->next = NULL;

   if(tempcellnp == NULL){
        tempcellnp = link;     //when linked list is empty
    }
    else{
        p  = tempcellnp;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
        }
        p->next = link;//Point the previous last cellNode to the new cellNode created.
    }

   //point first to new first cellNode
   //head = link;
}


struct cell cellget(struct cellNode *tempcellnp,int index) {
   struct cell data;
   //create a link
   struct cellNode *p;
   

	p  = tempcellnp;//assign head to p 
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

struct cellNode *cellNodeget(struct cellNode *tempcellnp,int index) {
   struct cell data;
   //create a link
   struct cellNode *p;
   

	p  = tempcellnp;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
	

   return p;
   //point first to new first cellNode
   //head = link;
}

void cellremoveFirstNode(struct cellNode *tempcellnp){
  struct cellNode *current;
  if(tempcellnp!=NULL){
            current=tempcellnp;
            tempcellnp=tempcellnp->next;
            free(current);
  }
}
void cellremoveNode(struct cellNode *tempcellnp,int index){
   //create a link
   struct cellNode *current;
   struct cellNode *previous;
	current = tempcellnp;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
}


int cellcount(struct cellNode *tempcellnp){
   int size = 0;
   struct cellNode *link;

   if(tempcellnp==NULL) {
      return size;
     
   }

   link = tempcellnp;            
   while(link != NULL) {
      link = link->next;
      size++;
   }

   return size;
  
}


void pairinsert(struct cellNode *tempcellnp,struct pair data) {
   //create a link
   struct dnaNode *link = (struct dnaNode*) malloc(sizeof(struct dnaNode));
   struct dnaNode *p;
   
   //tempcell=cellget(cellind);
   //link->key = key;
   link->data = data;

   //point it to old first cellNode
   link->next = NULL;

   if(tempcellnp->data.dnaHead == NULL){
        tempcellnp->data.dnaHead = link;     //when linked list is empty
    }
    else{
        p  = tempcellnp->data.dnaHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
        }
        p->next = link;//Point the previous last cellNode to the new cellNode created.
    }

   //point first to new first cellNode
   //head = link;
}

int paircount(struct cellNode *tempcell){
   int size = 0;
   struct dnaNode *link;
   
   if(tempcell->data.dnaHead==NULL) {
      return size;
   }

   link = tempcell->data.dnaHead;            
   while(link != NULL) {
      link = link->next;
      size++;
   }

   return size;
  
}
//here the index is the cell dna pair
struct pair pairget(struct cellNode *tempcellnp,int pairind) {
   //tempcell=cellget(cellind);
   struct pair data;
   //create a link
   struct dnaNode *p;

	p  = tempcellnp->data.dnaHead;//assign head to p 
	int i;
        if(pairind==0){
          data=p->data;
        }
	for(i=0;i<pairind;i++){
	    p = p->next;
	}
	data=p->data;
	

   return data;
   //point first to new first cellNode
   //head = link;
}




//here the index is the desired cell
/*
struct pair cellDNA(int index){
     struct pair retpairs[];
     tempcell=cellget(index);
     int numpairs= paircount();
     for(int i=0;i<numpairs;i++){
        retpairs[i]=pairget(i);
     }
     return pairs;
 
}
*/

