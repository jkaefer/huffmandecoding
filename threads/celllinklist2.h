//used so that if header is included twice in another file
//it won't trigger an error
#ifndef CELL_LINKLIST_H
#define CELL_LINKLIST_H


struct codon {
    char *three;
};

struct codonNode{
   struct codon data;
   struct codonNode *next;
};

struct pair {
    char base;
    char complement;
  };

struct dnaNode{
   struct pair data;
   struct dnaNode *next;
};

struct rnaNode{
   struct pair data;
   struct rnaNode *next;
};

struct cell {
    int health;
    int counted;
    int surrounded;
    int rows;
    int columns;
    int cancerous;
    int mutations;
    int benign;
    char *genome;
    char *aminochain;
    struct dnaNode *dnaHead;
    struct rnaNode *rnaHead;
    struct codonNode *codonHead;
    struct aminoNode *aminoHead;
  };

struct cellNode {
   struct cell data;
   struct cellNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void cellprintList();

//insert link at the first location
void cellinsert(struct cell data);

struct cell cellget(int index);

struct cellNode *cellNodeget(int index);

void cellremoveFirstNode();

void cellremoveNode(int index);

int cellcount();

void pairinsert(struct cellNode *tempcell,struct pair data);

int paircount(struct cellNode *tempcell);

struct pair pairget(struct cellNode *tempcellnp,int pairind);

void pairedit(struct cellNode *tempcell,struct pair data,int pairind);

void pairprintlist(struct cellNode *tempcell);

void codoninsert(struct cellNode *tempcell,struct codon data);

struct codon codonget(struct cellNode *tempcell,int codonind);

void codonify(struct cellNode *tempcell,int numcodons);

void aminify(struct cellNode *tempcell,int numcodons);


//pair[] cellDNA(int index);


#endif
