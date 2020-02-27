#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hufflinklist.h"




struct huffNode *mainhuffs = NULL;
struct huffNode *randomlist = NULL;
struct huff temphuff;


//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct huffNode *huffCurrent = NULL;


//display the list
void huffprintList(int select) {

   struct huffNode *link;
   if(select==0){
	   link = mainhuffs;            
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


void huffinsert(int select,struct huff data) {
   //create a link
   struct huffNode *link = (struct huffNode*) malloc(sizeof(struct huffNode));
   struct huffNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first huffNode
   link->next = NULL;
   
   if(select==0){
	   if(mainhuffs == NULL){
		mainhuffs = link;     //when linked list is empty
	    }
	    else{
		p  = mainhuffs;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
		}
		p->next = link;//Point the previous last huffNode to the new huffNode created.
	    }
    }
    else{
	   if(randomlist == NULL){
		randomlist = link;     //when linked list is empty
	    }
	    else{
		p  = randomlist;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
		}
		p->next = link;//Point the previous last huffNode to the new huffNode created.
	    }
    }

   //point first to new first huffNode
   //head = link;
}


struct huff huffget(int select,int index) {
   struct huff data;
   //create a link
   struct huffNode *p;
   
   if(select==0){
	p  = mainhuffs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
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
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
	}
	data=p->data;
   }

   return data;
   //point first to new first huffNode
   //head = link;
}

struct huffNode *huffNodeget(int select,int index) {
   struct huff data;
   //create a link
   struct huffNode *p;
   
   if(select==0){
	p  = mainhuffs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
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
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
	}
	data=p->data;
   }
	

   return p;
   //point first to new first huffNode
   //head = link;
}

void huffremoveFirstNode(int select){
  struct huffNode *current;
  if(select==0){
	  if(mainhuffs!=NULL){
		    current=mainhuffs;
		    mainhuffs=mainhuffs->next;
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
void huffremoveNode(int select,int index){
   //create a link
   struct huffNode *current;
   struct huffNode *previous;
   if(select==0){
	current = mainhuffs;//assign head to p 
         
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


int huffcount(int select){
   int size = 0;
   struct huffNode *link;
   if(select==0){
	   if(mainhuffs==NULL) {
	      return size;
	     
	   }

	   link = mainhuffs;            
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





void codoninsert(struct huffNode *temphuff,struct codon data) {
   //create a link
   struct codonNode *link = (struct codonNode*) malloc(sizeof(struct codonNode));
   struct codonNode *p;
   
   //temphuff=huffget(huffind);
   //link->key = key;
   link->data = data;

   //point it to old first huffNode
   link->next = NULL;

   if(temphuff->data.codonHead == NULL){
        temphuff->data.codonHead = link;     //when linked list is empty
    }
    else{
        p  = temphuff->data.codonHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
        }
        p->next = link;//Point the previous last huffNode to the new huffNode created.
    }

   //point first to new first huffNode
   //head = link;
}


void speccodeinsert(struct codonNode *tempcodonNode,int data) {
   
   struct codesoflenlistNode *link = (struct codesoflenlistNode*) malloc(sizeof(struct codesoflenlistNode));
   struct codesoflenlistNode *p;
   
   //temphuff=huffget(huffind);
   //link->key = key;
   link->data = data;
  
   //point it to old first huffNode
   link->next = NULL;

   if(tempcodonNode->data.codeslenlistHead == NULL){
       tempcodonNode->data.codeslenlistHead = link;     //when linked list is empty
    }
    else{
        p  = tempcodonNode->data.codeslenlistHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
        }
        p->next = link;//Point the previous last huffNode to the new huffNode created.
    }

   //point first to new first huffNode
   //head = link;
}

struct codon *codonNodeGet(struct huffNode *temphuff,int codonind) {
   //temphuff=huffget(huffind);
   struct codon data;
   //create a link
   struct codonNode *p;

	p  = temphuff->data.codonHead;//assign head to p 
	int i;
        if(codonind==0){
	  //printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<codonind;i++){
	  //printf("i'm > 0\n");
	    p = p->next;
	}
	

   return p;
   //point first to new first huffNode
   //head = link;
}


struct codon codonget(struct codonNode *tempcodonNode) {
   //temphuff=huffget(huffind);
   struct codon data;
   //create a link
   struct codonNode *p;

	p  = tempcodonNode;//assign head to p 
	

	
	data=p->data;
	

   return data;
   //point first to new first huffNode
   //head = link;
}

int speccodeget(struct codonNode *tempcodonNode,int speccode) {
   //temphuff=huffget(huffind);
   int data;
   //create a link
   struct codesoflenlistNode *p;

	p  = tempcodonNode->data.codeslenlistHead;//assign head to p 
	int i;
        if(speccode==0){
	  //printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<speccode;i++){
	  //printf("i'm > 0\n");
	    p = p->next;
	}

	
	data=p->data;
	

   return data;
   //point first to new first huffNode
   //head = link;
}
int codoncount(struct huffNode *temphuff){
   int size = 0;
   //struct codonNode *link;
   struct codonNode *link;
	 
	   //link=
  
	   if(temphuff->data.codonHead==NULL) {
	      return size;
	     
	   }

	   link = temphuff->data.codonHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}

int codecount(struct codonNode *tempcodonNode){
   int size = 0;
   //struct huffNode *link = (struct huffNode*) malloc(sizeof(struct huffNode));
   //struct huffNode *p;
   struct codesoflenlistNode *link;
   
	   if(tempcodonNode->data.codeslenlistHead==NULL) {
	      return size;
	     
	   }

	   link = tempcodonNode->data.codeslenlistHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}
