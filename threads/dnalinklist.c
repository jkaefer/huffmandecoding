#include <stdio.h>
#include <stdlib.h>
#include "dnalinklist.h"


//struct node *head = NULL;
//struct node *current = NULL;
struct node *dnahead[5][] ={NULL,NULL,NULL,NULL,NULL};

//display the list
void printList(int headnum) {

   struct node *link;

   link = dnahead[headnum];            
   while(link != NULL) {
      printf("num:%d \n",link->data);
      link = link->next;
   }
}


void insert(int headnum,int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   struct node *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first node
   link->next = NULL;

   if(dnahead[headnum] == NULL){
        dnahead[headnum] = link;     //when linked list is empty
    }
    else{
        p  = dnahead[headnum];//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = link;//Point the previous last node to the new node created.
    }

   //point first to new first node
   //head = link;
}


int get(int headnum,int index) {
   int data;
   //create a link
   struct node *p;
   

	p  = dnahead[headnum];//assign head to p 
	int i;
        if(index==0){
          data=p->data;
        }
	for(i=0;i<index;i++){
	    p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
	}
	data=p->data;
	

   return data;
   //point first to new first node
   //head = link;
}

void removeFirstNode(int headnum){
	//if(index==0){
       if(dnahead[headnum]!=NULL){
            dnahead[headnum]=dnahead[headnum]->next;
            //free(current);
       }
        
	
}

void removeNode(int headnum, int index){
   //create a link
   struct node *current;
   struct node *previous;
	current = dnahead[headnum];//assign head to p 
	
        /*if(index==0){
          if(head!=NULL){
            head=head->next;
            //free(current);
	   }
        }*/
         
	for(int i=0;i<index;i++){
            //if(i==index-1){
              // p->next=p->next->next;
            //}
             previous=current;
             current=current->next;
	     //p = p->next;
	}
        previous->next=current->next;
        //free(p);
}


int count(int headnum){
   int size = 0;
   struct node *link;

   if(dnahead[headnum]==NULL) {
      return size;
     
   }

   link = dnahead[headnum];            
   while(link != NULL) {
      link = link->next;
      size++;
   }

   return size;
  
}

