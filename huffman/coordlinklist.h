//used so that if header is included twice in another file
//it won't trigger an error
#ifndef CELL_LINKLIST_H
#define CELL_LINKLIST_H




struct codon {
    int data;
};

struct codonNode{
   struct codon data;
   struct codonNode *next;
};

struct cell {
    int health;
    struct codonNode *codonHead;
  };

struct cellNode {
   struct cell data;
   struct cellNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void cellprintList(int select);

//insert link at the first location
void cellinsert(int select,struct cell data);

struct cell cellget(int select,int index);

struct cellNode *cellNodeget(int select,int index);

void cellremoveFirstNode(int select);

void cellremoveNode(int select,int index);

int cellcount(int select);

void codoninsert(struct cellNode *tempcell,struct codon data);

struct codon codonget(struct cellNode *tempcell,int codonind);





//pair[] cellDNA(int index);


#endif
