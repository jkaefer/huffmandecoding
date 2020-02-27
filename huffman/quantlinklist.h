
//it won't trigger an error
#ifndef quant_LINKLIST_H
#define quant_LINKLIST_H



/*struct quantcodesoflenlist{
	int data;
};*/


struct quantsub {
    int data;
};

struct quantsubNode{
   struct quantsub data;
   struct quantsubNode *next;
};

struct quant {
    //two bytes
    int length;
    //half byte
    int qtprec;
    //half byte
    int qtnum;
    //length = 64*(precision+1)
    struct quantsubNode *quantsubHead;
  };

struct quantNode {
   struct quant data;
   struct quantNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void quantprintList();


void quantinsert(struct quant data);

struct quant quantget(int index); 

void quantmodclass(int index,int length, int qtprec, int qtnum);

struct quantNode *quantNodeget(int index);

void quantremoveFirstNode();
void quantremoveNode(int index);


int quantcount();



void quantsubinsert(struct quantNode *tempquant,int data); 

struct quantsub *quantsubNodeGet(struct quantNode *tempquant,int quantsubind);

struct quantsub quantsubget(struct quantsubNode *tempquantsubNode);

int quantsubcount(struct quantNode *tempquant);
#endif
