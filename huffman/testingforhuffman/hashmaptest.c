#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node{
    int key;
    int val;
    struct node *next;
};
struct table{
    int size;
    struct node **list;
};
struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}
void insert(struct table *t,int key,int val){
	int pos = hashCode(t,key);
	struct node *list = t->list[pos];
	struct node *temp = list;

	/* Check if key passed, already exists in the list. If yes, update the 
	* key value pair with the new val passed. */
	while(temp){
		if(temp->key==key){
		temp->val = val;
		return;
	}
	temp = temp->next;
}

/* Key does not exist in the list, hence create new node for key, value 
* pair */
struct node *newNode = (struct node*)malloc(sizeof(struct node));

newNode->key = key;
newNode->val = val;
newNode->next = list;
t->list[pos] = newNode;
}
int lookup(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}
int main(){
    clock_t time = clock();
    struct table *t = createTable(10000000);
    for(int i=0;i<10000000;i++){
    	insert(t,i,i+1);
    	//insert(t,5,4);
    }
    for(int i=0;i<10000000;i++){
    	printf("%d\n",lookup(t,i));
    }
    time=clock()-time;
    double time_taken = ((double)time)/CLOCKS_PER_SEC; // in seconds 
    printf("array took %f seconds to execute \n", time_taken);
    return 0;
}
