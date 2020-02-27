
//it won't trigger an error
#ifndef HUFF_LINKLIST_H
#define HUFF_LINKLIST_H



/*struct huffcodesoflenlist{
	int data;
};*/

struct huffcodesoflenlistNode{
	int data;
	struct huffcodesoflenlistNode *next;
};


struct huffsub {
    int data;
    struct huffcodesoflenlistNode *huffcodesoflenlistHead;
};

struct huffsubNode{
   struct huffsub data;
   struct huffsubNode *next;
};

struct huff {
    int length;
    int acdc;
    int htnum;
    //don't need more because 16 bits and then data
    
    struct huffsubNode *huffsubHead;
  };

struct huffNode {
   struct huff data;
   struct huffNode *next;
};

//struct node *head = NULL;
//struct node *current = NULL;


//display the list
void huffprintList();


void huffinsert(struct huff data);

struct huff huffget(int index); 

void huffmodclass(int index,int length,int acdc,int htnum);

struct huffNode *huffNodeget(int index);

void huffremoveFirstNode();
void huffremoveNode(int index);


int huffcount();





void huffsubinsert(struct huffNode *temphuff,struct huffsub data); 

void huffspeccodeinsert(struct huffsubNode *temphuffsubNode,int data);

struct huffsub *huffsubNodeGet(struct huffNode *temphuff,int huffsubind);

struct huffsub huffsubget(struct huffsubNode *temphuffsubNode);

int huffspeccodeget(struct huffsubNode *temphuffsubNode,int speccode);

int huffcodecount(struct huffsubNode *temphuffsubNode);

int huffsubcount(struct huffNode *temphuff);
#endif
