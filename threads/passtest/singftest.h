//used so that if header is included twice in another file
//it won't trigger an error
#ifndef SING_H
#define SING_H


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

//insert link at the first location
void cellinsert(struct cellNode **maincells,struct cell data);
void cellremoveFirstNode(struct cellNode **maincells);
int cellcount(struct cellNode **maincells);
struct cell cellget(struct cellNode **maincells,int index);
void cellremoveNode(struct cellNode **maincells,int index)

#endif
