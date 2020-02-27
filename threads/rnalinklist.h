//used so that if header is included twice in another file
//it won't trigger an error
#ifndef RNALINKLIST_H
#define RNALINKLIST_H

struct pair{
    char *base;
    char *complement;
};

struct codon {
    char *base[3];
    char *complement[3];
  };

struct node {
   pair data;
   struct node *next;
};

//display the list
void printList(int headnum);

//insert link at the first location
void insert(int headnum,int data);

int get(int headnum,int index);

void removeFirstNode(int headnum);

void removeNode(int headnum,int index);

int count(int headnum);

#endif
