#include <stdio.h>
#include <stdlib.h>
#include "coordlinklist.h"




struct node *head = NULL;
struct node *current = NULL;


//display the list
void printList() {

   struct node *link;

   link = head;            
   while(link != NULL) {
      printf("num:%d \n",link->data);
      link = link->next;
   }
}

void insert(struct coord data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   struct node *p;
   
   //link->key = key;
   link->data = data;

   //point it to old first node
   link->next = NULL;

   if(head == NULL){
        head = link;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = link;//Point the previous last node to the new node created.
    }

   //point first to new first node
   //head = link;
}

/*void insertHere(cell data,int index) {
   //create a link
   struct node *link;
// = (struct node*) malloc(sizeof(struct node));
   struct node *p;
   
   //link->key = key;
   link->data = data;

   if(index==0){
          p=link;
        }
    else{
        p  = head;
        int i;
        for(i=0;i<index;i++){
            p = p->next;
        }
        
        p=link;
        //p->next = link;
    }
    //link->next = p->next->next;
}*/


struct coord get(int index) {
   struct coord data;
   //create a link
   struct node *p;
   

	p  = head;//assign head to p 
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



void coordremoveFirstNode(){
  struct node *current;
  if(head!=NULL){
            current=head;
            head=head->next;
            free(current);
  }
}
void coordremoveNode(int index){
   //create a link
   struct node *current;
   struct node *previous;
	current = head;//assign head to p 
         
	for(int i=0;i<index;i++){
             previous=current;
             current=current->next;
	}
        previous->next=current->next;
        free(current);
}

void coordremoveAll(){
  while(count()!=0){
  	coordremoveFirstNode();
  }
}

int count(){
   int size = 0;
   struct node *link;

   if(head==NULL) {
      return size;
     
   }

   link = head;            
   while(link != NULL) {
      link = link->next;
      size++;
   }

   return size;
  
}

