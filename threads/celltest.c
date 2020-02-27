#include <stdio.h>
#include "celllinklist.h"

//gcc -o celltest celltest.c celllinklist.c

void main(){
    int tidIndex=0;
    
    struct cell cells[10];
    int size =sizeof(cells)/sizeof(struct cell);
     printf("%d\n",size);
    for(int i=0;i<size;i++){
	cellinsert(cells[i]);
    }
   // rand % cellcount();
    srand(time(0));
    printf("%d\n",rand() % cellcount());

}
