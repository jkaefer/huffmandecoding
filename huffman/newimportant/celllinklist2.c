#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celllinklist2.h"




//struct cellNode *maincells = NULL;
//struct cellNode *randomlist = NULL;
struct cell tempcell;


char *codes[64][2]={
//isoleucine
	{"ATT","I"},{"ATC","I"},{"ATA","I"},
//leucine
	{"CTT","L"},{"CTC","L"},{"CTA","L"},{"CTG","L"},{"TTA","L"},{"TTG","L"},
//valine
	{"GTT","V"},{"GTC","V"},{"GTA","V"},{"GTG","V"},
//phenylalanine
	{"TTT","F"},{"TTC","F"},
//methionine
	{"ATG","M"},
//cysteine
	{"TGT","C"},{"TGC","C"},
//alanine
	{"GCT","A"},{"GCC","A"},{"GCA","A"},{"CCG","A"},
//glycine
	{"GGT","G"},{"GGC","G"},{"GGA","G"},{"GGG","G"},
//proline
	{"CCT","P"},{"CCC","P"},{"CCA","P"},{"CCG","P"},
//threonine
	{"ACT","T"},{"ACC","T"},{"ACA","T"},{"ACG","T"},
//serine
	{"TCT","S"},{"TCC","S"},{"TCA","S"},{"TCG","S"},{"AGT","S"},{"AGC","S"},
//tyrosine
	{"TAT","Y"},{"TAC","Y"},
//tryptophan
	{"TGG","W"},
//glutamine
	{"CAA","Q"},{"CAG","Q"},
//asparagine
	{"AAT","N"},{"AAC","N"},
//histidine
	{"CAT","H"},{"CAC","H"},
//glutamic acid
	{"GAA","E"},{"GAG","E"},
//aspartic acid
	{"GAT","D"},{"GAC","D"},
//lysine
	{"AAA","K"},{"AAG","K"},
//arginine
	{"CGT","R"},{"CGC","R"},{"CGA","R"},{"CGG","R"},{"AGA","R"},{"AGG","R"},
//stop
	{"TAA","STOP"},{"TAG","STOP"},{"TGA","STOP"}

};
//struct dnaNode *dnaHead=NULL;
//struct rnaNode *rnaHead=NULL;
//struct cellNode *cellCurrent = NULL;


//display the list
void cellprintList(struct cellNode **maincells) {

   struct cellNode *link;
	   link = (*maincells);            
	   while(link != NULL) {
	      printf("num:%d \n",link->data);
	      link = link->next;
	   }
}


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

struct cellNode *cellNodeget(struct cellNode **maincells,int index) {
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
	
   return p;
   //point first to new first cellNode
   //head = link;
}

void cellremoveFirstNode(struct cellNode **maincells){
  struct cellNode *current;
	  if((*maincells)!=NULL){
		    current=(*maincells);
		    (*maincells)=(*maincells)->next;
		    free(current);
	  }
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
 
void pairedit(struct cellNode *tempcellnp,struct pair data,int pairind) {
   //tempcell=cellget(cellind);
   //create a link
   struct dnaNode *p;

	p  = tempcellnp->data.dnaHead;//assign head to p 
	int i;
        if(pairind==0){
          p->data=data;
        }
	for(i=0;i<pairind;i++){
	    p = p->next;
	}
	p->data=data;
	
   //point first to new first cellNode
   //head = link;
}

void pairprintlist(struct cellNode *tempcellnp){
    struct dnaNode *p;

           p  = tempcellnp->data.dnaHead;          
	   while(p != NULL) {
	      printf("%c",p->data.base);
	      p = p->next;
	   }
	   printf("\n");
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

void codonify(struct cellNode *tempcell,int numcodons){
	//for(int i=0;i<numcodons*3;i+=3){
	      //for(int j=i;j<i+3;j++){
		//this may be tricky
		char tempstr[4];
		printf("%c\n",pairget(tempcell,0).base);
		tempstr[0]=pairget(tempcell,0).base;
		tempstr[1]=pairget(tempcell,1).base;
		tempstr[2]=pairget(tempcell,2).base;
		tempstr[3]='\0';
		
		struct codon tempcodon={tempstr};
		codoninsert(tempcell,tempcodon);
	      	//f("%c",p->data.base);
		//pairget(tempcell,j);
	      //}
	//}
}

void aminify(struct cellNode *tempcell,int numcodons){
	for(int i=0;i<numcodons;i++){
	      struct codon refcodon=codonget(tempcell,i);
	      char *codstring=refcodon.three;
	      for(int i=0;i<64;i++){
		if(strcmp(codstring,codes[i][0])==0){
			tempcell->data.aminochain=strcat(tempcell->data.aminochain,codes[i][1]);
			//aminoinsert(tempcell,codes[i][1]);
		}
	      }
	}
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

