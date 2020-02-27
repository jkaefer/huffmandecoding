#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hufflinklist.h"




struct huffNode *mainhuffs = NULL;

struct huff temphuff;


//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct huffNode *huffCurrent = NULL;


//display the list
void huffprintList() {

   struct huffNode *link;
   //if(select==0){
	   link = mainhuffs;            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
   //}
   
}


void huffinsert(struct huff data) {
   //create a link
   struct huffNode *link = (struct huffNode*) malloc(sizeof(struct huffNode));
   struct huffNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first huffNode
   link->next = NULL;
   
   //if(select==0){
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
    //}
    
   //point first to new first huffNode
   //head = link;
}


struct huff huffget(int index) {
   struct huff data;
   //create a link
   struct huffNode *p;
   
   //if(select==0){
	p  = mainhuffs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
	}
	data=p->data;
   //}
   

   return data;
   //point first to new first huffNode
   //head = link;
}

void huffmodclass(int index,int length,int acdc,int htnum) {
   //struct huff data;
   //create a link
   struct huffNode *p;
   
   //if(select==0){
	p  = mainhuffs;//assign head to p 
	int i;
        /*if(index==0){
          p->data.huffclass=num;
        }*/
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
	}
	p->data.length=length;
	p->data.acdc=acdc;
	p->data.htnum=htnum;
   //}
   
	

   return p;
   //point first to new first huffNode
   //head = link;
}


struct huffNode *huffNodeget(int index) {
   struct huff data;
   //create a link
   struct huffNode *p;
   
   //if(select==0){
	p  = mainhuffs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
	}
	data=p->data;
   //}
   
	

   return p;
   //point first to new first huffNode
   //head = link;
}

void huffremoveFirstNode(){
  struct huffNode *current;
  //if(select==0){
	  if(mainhuffs!=NULL){
		    current=mainhuffs;
		    mainhuffs=mainhuffs->next;
		    free(current);
	  }
  //}
 
}
void huffremoveNode(int index){
   //create a link
   struct huffNode *current;
   struct huffNode *previous;
   //if(select==0){
	current = mainhuffs;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
   //}
   
  
}


int huffcount(){
   int size = 0;
   struct huffNode *link;
   //if(select==0){
	   if(mainhuffs==NULL) {
	      return size;
	     
	   }

	   link = mainhuffs;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
   //}
   
  
}





void huffsubinsert(struct huffNode *temphuff,struct huffsub data) {
   //create a link
   struct huffsubNode *link = (struct huffsubNode*) malloc(sizeof(struct huffsubNode));
   struct huffsubNode *p;
   
   //temphuff=huffget(huffind);
   //link->key = key;
   link->data = data;

   //point it to old first huffNode
   link->next = NULL;

   if(temphuff->data.huffsubHead == NULL){
        temphuff->data.huffsubHead = link;     //when linked list is empty
    }
    else{
        p  = temphuff->data.huffsubHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
        }
        p->next = link;//Point the previous last huffNode to the new huffNode created.
    }

   //point first to new first huffNode
   //head = link;
}


void huffspeccodeinsert(struct huffsubNode *temphuffsubNode,int data) {
   
   struct huffcodesoflenlistNode *link = (struct huffcodesoflenlistNode*) malloc(sizeof(struct huffcodesoflenlistNode));
   struct huffcodesoflenlistNode *p;
   
   //temphuff=huffget(huffind);
   //link->key = key;
   link->data = data;
  
   //point it to old first huffNode
   link->next = NULL;

   if(temphuffsubNode->data.huffcodesoflenlistHead == NULL){
       temphuffsubNode->data.huffcodesoflenlistHead = link;     //when linked list is empty
    }
    else{
        p  = temphuffsubNode->data.huffcodesoflenlistHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last huffNode.The last huffNode always points to NULL.
        }
        p->next = link;//Point the previous last huffNode to the new huffNode created.
    }

   //point first to new first huffNode
   //head = link;
}

struct huffsub *huffsubNodeGet(struct huffNode *temphuff,int huffsubind) {
   //temphuff=huffget(huffind);
   struct huffsub data;
   //create a link
   struct huffsubNode *p;

	p  = temphuff->data.huffsubHead;//assign head to p 
	int i;
        if(huffsubind==0){
	  //printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<huffsubind;i++){
	  //printf("i'm > 0\n");
	    p = p->next;
	}
	

   return p;
   //point first to new first huffNode
   //head = link;
}


struct huffsub huffsubget(struct huffsubNode *temphuffsubNode) {
   //temphuff=huffget(huffind);
   struct huffsub data;
   //create a link
   struct huffsubNode *p;

	p  = temphuffsubNode;//assign head to p 
	

	
	data=p->data;
	

   return data;
   //point first to new first huffNode
   //head = link;
}

int huffspeccodeget(struct huffsubNode *temphuffsubNode,int speccode) {
   //temphuff=huffget(huffind);
   int data;
   //create a link
   struct huffcodesoflenlistNode *p;

	p  = temphuffsubNode->data.huffcodesoflenlistHead;//assign head to p 
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
int huffsubcount(struct huffNode *temphuff){
   int size = 0;
   //struct huffsubNode *link;
   struct huffsubNode *link;
	 
	   //link=
  
	   if(temphuff->data.huffsubHead==NULL) {
	      return size;
	     
	   }

	   link = temphuff->data.huffsubHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}

int huffcodecount(struct huffsubNode *temphuffsubNode){
   int size = 0;
   //struct huffNode *link = (struct huffNode*) malloc(sizeof(struct huffNode));
   //struct huffNode *p;
   struct huffcodesoflenlistNode *link;
   
	   if(temphuffsubNode->data.huffcodesoflenlistHead==NULL) {
	      return size;
	     
	   }

	   link = temphuffsubNode->data.huffcodesoflenlistHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}
