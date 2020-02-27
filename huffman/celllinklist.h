
//it won't trigger an error
#ifndef HUFF_LINKLIST_H
#define HUFF_LINKLIST_H



/*struct codesoflenlist{
	int data;
};*/

struct codesoflenlistNode{
	int data;
	struct codesoflenlistNode *next;
};


struct codon {
    int data;
    struct codesoflenlistNode *codeslenlistHead;
};

struct codonNode{
   struct codon data;
   struct codonNode *next;
};

struct huff {
    char huffclass;
    struct codonNode *codonHead;
  };

struct huffNode {
   struct huff data;
   struct huffNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void huffprintList(int select);


void huffinsert(int select,struct huff data);

struct huff huffget(int select,int index); 

struct huffNode *huffNodeget(int select,int index);

void huffremoveFirstNode(int select);
void huffremoveNode(int select,int index);


int huffcount(int select);





void codoninsert(struct huffNode *temphuff,struct codon data); 

void speccodeinsert(struct codonNode *tempcodonNode,int data);

struct codon *codonNodeGet(struct huffNode *temphuff,int codonind);

struct codon codonget(struct codonNode *tempcodonNode);

int speccodeget(struct codonNode *tempcodonNode,int speccode);

int codecount(struct codonNode *tempcodonNode);

int codoncount(struct huffNode *temphuff);
#endif
