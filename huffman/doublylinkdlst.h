typedef struct Node{
	struct huffentry huff;
	struct Node* next;
	struct Node* prev; 
}Node_t; 

typedef struct huffentry {
   char literalcode[5];
   int size;
   //this initializer needs to be huge maybe 1000 not enough
   char bincode[1000];
};

void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, struct Node* del);
void deleteNodeAtGivenPos(struct Node** head_ref, int n);
void printList(struct Node* node);