#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celllinklist.h"




struct cellNode *maincells = NULL;
struct cellNode *randomlist = NULL;
struct cell tempcell;


//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct cellNode *cellCurrent = NULL;


//display the list
void cellprintList(int select) {

   struct cellNode *link;
   if(select==0){
	   link = maincells;            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
   }
   else{
	   link = randomlist;            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
   }
}


void cellinsert(int select,struct cell data) {
   //create a link
   struct cellNode *link = (struct cellNode*) malloc(sizeof(struct cellNode));
   struct cellNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first cellNode
   link->next = NULL;
   
   if(select==0){
	   if(maincells == NULL){
		maincells = link;     //when linked list is empty
	    }
	    else{
		p  = maincells;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
		}
		p->next = link;//Point the previous last cellNode to the new cellNode created.
	    }
    }
    else{
	   if(randomlist == NULL){
		randomlist = link;     //when linked list is empty
	    }
	    else{
		p  = randomlist;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
		}
		p->next = link;//Point the previous last cellNode to the new cellNode created.
	    }
    }

   //point first to new first cellNode
   //head = link;
}


struct cell cellget(int select,int index) {
   struct cell data;
   //create a link
   struct cellNode *p;
   
   if(select==0){
	p  = maincells;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
   }
   else{
	p  = randomlist;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
   }

   return data;
   //point first to new first cellNode
   //head = link;
}

struct cellNode *cellNodeget(int select,int index) {
   struct cell data;
   //create a link
   struct cellNode *p;
   
   if(select==0){
	p  = maincells;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
   }
   else{
	p  = randomlist;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
	}
	data=p->data;
   }
	

   return p;
   //point first to new first cellNode
   //head = link;
}

void cellremoveFirstNode(int select){
  struct cellNode *current;
  if(select==0){
	  if(maincells!=NULL){
		    current=maincells;
		    maincells=maincells->next;
		    free(current);
	  }
  }
  else{
	  if(randomlist!=NULL){
		    current=randomlist;
		    randomlist=randomlist->next;
		    free(current);
	  }
  }
}
void cellremoveNode(int select,int index){
   //create a link
   struct cellNode *current;
   struct cellNode *previous;
   if(select==0){
	current = maincells;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
   }
   if(select==0){
	current = randomlist;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
   }
  
}


int cellcount(int select){
   int size = 0;
   struct cellNode *link;
   if(select==0){
	   if(maincells==NULL) {
	      return size;
	     
	   }

	   link = maincells;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
   }
   else{
	   if(randomlist==NULL) {
	      return size;
	     
	   }

	   link = randomlist;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
   }
   return size;
  
}




void codoninsert(struct cellNode *tempcell,struct codon data) {
   //create a link
   struct codonNode *link = (struct codonNode*) malloc(sizeof(struct codonNode));
   struct codonNode *p;
   
   //tempcell=cellget(cellind);
   //link->key = key;
   link->data = data;

   //point it to old first cellNode
   link->next = NULL;

   if(tempcell->data.codonHead == NULL){
        tempcell->data.codonHead = link;     //when linked list is empty
    }
    else{
        p  = tempcell->data.codonHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
        }
        p->next = link;//Point the previous last cellNode to the new cellNode created.
    }

   //point first to new first cellNode
   //head = link;
}

struct codon codonget(struct cellNode *tempcell,int codonind) {
   //tempcell=cellget(cellind);
   struct codon data;
   //create a link
   struct codonNode *p;

	p  = tempcell->data.codonHead;//assign head to p 
	int i;
        if(codonind==0){
	  printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<codonind;i++){
	  printf("i'm > 0\n");
	    p = p->next;
	}
	
	data=p->data;
	

   return data;
   //point first to new first cellNode
   //head = link;
}





