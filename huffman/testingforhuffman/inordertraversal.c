// C program for different tree traversals 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */

struct datalist{
	int data;
	int numbits;
}


struct datalist data[7]={{.data=2;,.numbits=1;},{.data=3;,.numbits=1;},{.data=4;,.numbits=2;},{.data=5;,.numbits=2;},{.data=6;,.numbits=3;},{.data=7;,.numbits=3;},{.data=8;,.numbits=3;}};
struct node 
{ 
	char* data; 
	int numbits;
	struct node* left; 
	struct node* right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(char* data, int numbits) 
{ 
	struct node* node = (struct node*) 
								malloc(sizeof(struct node)); 
	node->data = data; 
	node->numbits=numbits;
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 
void printPostorderLeft(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorderLeft(node->left); 

	// then recur on right subtree 
	printPostorderLeft(node->right); 

	// now deal with the node 
	printf("%d ", node->data); 
} 
/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorderRight(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorderRight(node->right); 

	// then recur on right subtree 
	printPostorderRight(node->left); 

	// now deal with the node 
	printf("%s ", node->data); 
} 
	
void ifEmptyNew(struct node* node,int round) 
{ 
	if (strcmp(node->data == "empty")==0){
		node->left= newNode("new",round);
		//return node; 
	}

	// first recur on left subtree 
	printPostorder(node->right); 

	// then recur on right subtree 
	printPostorder(node->left); 

	// now deal with the node 
	printf("%s ", node->data); 
} 

//based on printpostorderleft
void enterData(struct node* node,int round,char* data, struct datarraylist* datarray) 
{ 
	if (strcmp(node->data == "new")==0&& node->numbits==round){
		node->data= itoa(getdatarraylistdata(datarray,round));
		//return node; 
	}

	// first recur on left subtree 
	printPostorderLeft(node->left); 

	// then recur on right subtree 
	printPostorderLeft(node->right); 

	// now deal with the node 
	printf("%d ", node->data); 
} 
	 
void newroundofnodes(struct node *root,int round){
	int roundcount=0;
	int potnew=pow(2,round);
	while(roundcount!=round){
		if(roundcount==node->numbits){
		}
		root->left = newNode("2",roundcount); 
		root->right = newNode("3",roundcount); 
		root->left->left = newNode("4",roundcount); 
		root->left->right = newNode("5",roundcount); 
		root->right->left=newNode("6");
		root->right->right=newNode("7");
		root->right->right->left=newNode("10");
		root->right->right->right=newNode("11");
		root->right->left->left=newNode("8");
		root->right->left->right=newNode("9");
		
	}
}

/* Driver program to test above functions*/
int main() 
{ 
	struct node *root = newNode("root",0); 
	root->left= newNode("new",1); 
	root->right= newNode("new",1);
	newroundofnodes();
	 
	root->left->left	 = newNode("4"); 
	root->left->right = newNode("5"); 
	root->right->left=newNode("6");
	root->right->right=newNode("7");
	root->right->right->left=newNode("10");
	root->right->right->right=newNode("11");
        root->right->left->left=newNode("8");
	root->right->left->right=newNode("9");

	
	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorderRight(root); 

	getchar(); 
	return 0; 
} 

