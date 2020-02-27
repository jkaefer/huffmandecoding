//used so that if header is included twice in another file
//it won't trigger an error
#ifndef COORDLINKLIST_H
#define COORDLINKLIST_H

struct coord{
    int rows;
    int columns;
};

struct node {
   struct coord data;
   struct node *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void printList();

//insert link at the first location
void insert(struct coord data);

struct coord get(int index);
int count();

#endif
