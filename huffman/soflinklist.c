#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "soflinklist.h"




struct sofNode *mainsofs = NULL;

struct sof tempsof;



//display the list
void sofprintList() {

   struct sofNode *link;
   //if(select==0){
	   link = mainsofs;            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
   //}
   
}


void sofinsert(struct sof data) {
   //create a link
   struct sofNode *link = (struct sofNode*) malloc(sizeof(struct sofNode));
   struct sofNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first sofNode
   link->next = NULL;
   
   //if(select==0){
	   if(mainsofs == NULL){
		mainsofs = link;     //when linked list is empty
	    }
	    else{
		p  = mainsofs;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last sofNode.The last sofNode always points to NULL.
		}
		p->next = link;//Point the previous last sofNode to the new sofNode created.
	    }
    //}
    

   //point first to new first sofNode
   //head = link;
}


struct sof sofget(int index) {
   struct sof data;
   //create a link
   struct sofNode *p;
   
   //if(select==0){
	p  = mainsofs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last sofNode.The last sofNode always points to NULL.
	}
	data=p->data;
   //}
   

   return data;
   //point first to new first sofNode
   //head = link;
}

void sofmodclass(int index,int length, int prec, int height,int width,int numcomps) {
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
	p->data.prec=prec;
	p->data.height=height;
	p->data.width=width;
	p->data.numcomps=numcomps;
   //}
   
	

   return p;
   //point first to new first huffNode
   //head = link;
}


struct sofNode *sofNodeget(int index) {
   struct sof data;
   //create a link
   struct sofNode *p;
   
   //if(select==0){
	p  = mainsofs;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last sofNode.The last sofNode always points to NULL.
	}
	data=p->data;
   //}
   
	

   return p;
   //point first to new first sofNode
   //head = link;
}

void sofremoveFirstNode(int select){
  struct sofNode *current;
  //if(select==0){
	  if(mainsofs!=NULL){
		    current=mainsofs;
		    mainsofs=mainsofs->next;
		    free(current);
	  }
  //}
  
}
void sofremoveNode(int index){
   //create a link
   struct sofNode *current;
   struct sofNode *previous;
   //if(select==0){
	current = mainsofs;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
   //}
   
  
}


int sofcount(){
   int size = 0;
   struct sofNode *link;
   //if(select==0){
	   if(mainsofs==NULL) {
	      return size;
	     
	   }

	   link = mainsofs;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
   //}
   
   return size;
  
}





void sofsubinsert(struct sofNode *tempsof,int data) {
   //create a link
   struct sofsubNode *link = (struct sofsubNode*) malloc(sizeof(struct sofsubNode));
   struct sofsubNode *p;
   
   //tempsof=sofget(sofind);
   //link->key = key;
   link->data = data;

   //point it to old first sofNode
   link->next = NULL;

   if(tempsof->data.sofsubHead == NULL){
        tempsof->data.sofsubHead = link;     //when linked list is empty
    }
    else{
        p  = tempsof->data.sofsubHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last sofNode.The last sofNode always points to NULL.
        }
        p->next = link;//Point the previous last sofNode to the new sofNode created.
    }

   //point first to new first sofNode
   //head = link;
}



struct sofsub *sofsubNodeGet(struct sofNode *tempsof,int sofsubind) {
   //tempsof=sofget(sofind);
   struct sofsub data;
   //create a link
   struct sofsubNode *p;

	p  = tempsof->data.sofsubHead;//assign head to p 
	int i;
        if(sofsubind==0){
	  //printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<sofsubind;i++){
	  //printf("i'm > 0\n");
	    p = p->next;
	}
	

   return p;
   //point first to new first sofNode
   //head = link;
}


struct sofsub sofsubget(struct sofsubNode *tempsofsubNode) {
   //tempsof=sofget(sofind);
   struct sofsub data;
   //create a link
   struct sofsubNode *p;

	p  = tempsofsubNode;//assign head to p 
	

	
	data=p->data;
	

   return data;
   //point first to new first sofNode
   //head = link;
}


int sofsubcount(struct sofNode *tempsof){
   int size = 0;
   //struct sofsubNode *link;
   struct sofsubNode *link;
	 
	   //link=
  
	   if(tempsof->data.sofsubHead==NULL) {
	      return size;
	     
	   }

	   link = tempsof->data.sofsubHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}


