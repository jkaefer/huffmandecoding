//used so that if header is included twice in another file
//it won't trigger an error
#ifndef DNALINKLIST_H
#define DNALINKLIST_H


struct pair {
    char *base;
    char *complement;
  };

struct node {
   pair data;
   struct node *next;
};


//display the list
void printList(int headnum);

//insert link at the first location
void insert(int headnum,int data);

pair get(int headnum,int index);

void removeFirstNode(int headnum);

void removeNode(int headnum,int index);

int count(int headnum);

#endif
