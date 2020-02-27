
//it won't trigger an error
#ifndef sof_LINKLIST_H
#define sof_LINKLIST_H



/*struct sofcodesoflenlist{
	int data;
};*/


struct sofsub {
   int compid;
   int sampfacth;
   int sampfactv;
   int quanttnum;
};

struct sofsubNode{
   struct sofsub data;
   struct sofsubNode *next;
};

struct sof {
    //two bytes
    int length;
    //one byte
    int prec;
    //two bytes each
    int height;
    int width;
    //one byte
    int numcomps;
    //length = 8 + components*3 
    struct sofsubNode *sofsubHead;
  };

struct sofNode {
   struct sof data;
   struct sofNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void sofprintList();


void sofinsert(struct sof data);

struct sof sofget(int index); 

void sofmodclass(int index,int length, int prec, int height,int width,int numcomps);

struct sofNode *sofNodeget(int index);

void sofremoveFirstNode();
void sofremoveNode(int index);


int sofcount();



void sofsubinsert(struct sofNode *tempsof,int data); 

struct sofsub *sofsubNodeGet(struct sofNode *tempsof,int sofsubind);

struct sofsub sofsubget(struct sofsubNode *tempsofsubNode);

int sofsubcount(struct sofNode *tempsof);
#endif
