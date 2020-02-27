//used so that if header is included twice in another file
//it won't trigger an error
#ifndef CELL_LINKLIST_H
#define CELL_LINKLIST_H


struct amino {
    char *letter;
};
struct codon {
    char one;
    char two;
    char three;
};

struct codonNode{
   struct codon data;
   struct codonNode *next;
};
struct gene {
    struct codonNode *codonHead;
};

struct geneNode{
   struct gene data;
   struct geneNode *next;
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
    int benign;
    char *genome;
    struct dnaNode *dnaHead;
    struct rnaNode *rnaHead;
    struct codonNode *codonHead;
    struct geneNode *geneHead;
  };

struct cellNode {
   struct cell data;
   struct cellNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void cellprintList(struct cellNode *tempcellnp);

//insert link at the first location
void cellinsert(struct cellNode *tempcellnp,struct cell data);

struct cell cellget(struct cellNode *tempcellnp,int index);

struct cellNode *cellNodeget(struct cellNode *tempcellnp,int index);

void cellremoveFirstNode(struct cellNode *tempcellnp);

void cellremoveNode(struct cellNode *tempcellnp,int index);

int cellcount(struct cellNode *tempcellnp);

void pairinsert(struct cellNode *tempcell,struct pair data);

int paircount(struct cellNode *tempcell);

struct pair pairget(struct cellNode *tempcellnp,int pairind);

//pair[] cellDNA(int index);


#endif
