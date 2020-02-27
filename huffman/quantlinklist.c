#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quantlinklist.h"




struct quantNode *mainquants = NULL;

struct quant tempquant;


//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct quantNode *quantCurrent = NULL;


//display the list
void quantprintList() {

   struct quantNode *link;
   //if(select==0){
	   link = mainquants;            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
   //}
   
}


void quantinsert(struct quant data) {
   //create a link
   struct quantNode *link = (struct quantNode*) malloc(sizeof(struct quantNode));
   struct quantNode *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first quantNode
   link->next = NULL;
   
   //if(select==0){
	   if(mainquants == NULL){
		mainquants = link;     //when linked list is empty
	    }
	    else{
		p  = mainquants;//assign head to p 
		while(p->next != NULL){
		    p = p->next;//traverse the list until p is the last quantNode.The last quantNode always points to NULL.
		}
		p->next = link;//Point the previous last quantNode to the new quantNode created.
	    }
    //}
    

   //point first to new first quantNode
   //head = link;
}


struct quant quantget(int index) {
   struct quant data;
   //create a link
   struct quantNode *p;
   
   //if(select==0){
	p  = mainquants;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last quantNode.The last quantNode always points to NULL.
	}
	data=p->data;
   //}
   

   return data;
   //point first to new first quantNode
   //head = link;
}

void quantmodclass(int index,int length, int qtprec, int qtnum) {
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
	p->data.qtprec=qtprec;
	p->data.qtnum=qtnum;
   //}
   
	

   return p;
   //point first to new first huffNode
   //head = link;
}


struct quantNode *quantNodeget(int index) {
   struct quant data;
   //create a link
   struct quantNode *p;
   
   //if(select==0){
	p  = mainquants;//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last quantNode.The last quantNode always points to NULL.
	}
	data=p->data;
   //}
   
	

   return p;
   //point first to new first quantNode
   //head = link;
}

void quantremoveFirstNode(int select){
  struct quantNode *current;
  //if(select==0){
	  if(mainquants!=NULL){
		    current=mainquants;
		    mainquants=mainquants->next;
		    free(current);
	  }
  //}
  
}
void quantremoveNode(int index){
   //create a link
   struct quantNode *current;
   struct quantNode *previous;
   //if(select==0){
	current = mainquants;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
   //}
   
  
}


int quantcount(){
   int size = 0;
   struct quantNode *link;
   //if(select==0){
	   if(mainquants==NULL) {
	      return size;
	     
	   }

	   link = mainquants;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
   //}
   
   return size;
  
}





void quantsubinsert(struct quantNode *tempquant,int data) {
   //create a link
   struct quantsubNode *link = (struct quantsubNode*) malloc(sizeof(struct quantsubNode));
   struct quantsubNode *p;
   
   //tempquant=quantget(quantind);
   //link->key = key;
   link->data = data;

   //point it to old first quantNode
   link->next = NULL;

   if(tempquant->data.quantsubHead == NULL){
        tempquant->data.quantsubHead = link;     //when linked list is empty
    }
    else{
        p  = tempquant->data.quantsubHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last quantNode.The last quantNode always points to NULL.
        }
        p->next = link;//Point the previous last quantNode to the new quantNode created.
    }

   //point first to new first quantNode
   //head = link;
}




struct quantsub *quantsubNodeGet(struct quantNode *tempquant,int quantsubind) {
   //tempquant=quantget(quantind);
   struct quantsub data;
   //create a link
   struct quantsubNode *p;

	p  = tempquant->data.quantsubHead;//assign head to p 
	int i;
        if(quantsubind==0){
	  //printf("i'm 0\n");
          data=p->data;
        }
	
	for(i=0;i<quantsubind;i++){
	  //printf("i'm > 0\n");
	    p = p->next;
	}
	

   return p;
   //point first to new first quantNode
   //head = link;
}


struct quantsub quantsubget(struct quantsubNode *tempquantsubNode) {
   //tempquant=quantget(quantind);
   struct quantsub data;
   //create a link
   struct quantsubNode *p;

	p  = tempquantsubNode;//assign head to p 
	

	
	data=p->data;
	

   return data;
   //point first to new first quantNode
   //head = link;
}


int quantsubcount(struct quantNode *tempquant){
   int size = 0;
   //struct quantsubNode *link;
   struct quantsubNode *link;
	 
	   //link=
  
	   if(tempquant->data.quantsubHead==NULL) {
	      return size;
	     
	   }

	   link = tempquant->data.quantsubHead;            
	   while(link != NULL) {
	      link = link->next;
	      size++;
	   }
  
   return size;
  
}


