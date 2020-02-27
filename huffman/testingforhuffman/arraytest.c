#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ArrayList.h"

int main(void)
{
    
    ArrayList list;
    initWithSizeAndIncRate(&list, 100000, 100000);
    //init(&list,100,);
    add(&list, (Element){10});
    add(&list, (Element){30});
    add(&list, (Element){40});
    add(&list, (Element){50});
    add(&list, (Element){60});
    add(&list, (Element){30});
    add(&list, (Element){80});
    print(&list);
    
    insert(&list, (Element){20}, 1);
    insert(&list, (Element){15}, 1);
    insert(&list, (Element){3}, 0);
    print(&list);
    
    printf("Removeing element at index 5\n");
    removeAt(&list, 5);
    print(&list);
    
    Element *e = get(&list, 5);
    printf("element at 5th index:\n %i\n", (e!=NULL? e->data:-1));
    
    int i  = indexOf(&list, (Element){30});
    printf("Index of 30:\n %i\n", i);
    
    i  = lastIndexOf(&list, (Element){30});
    printf("Last index of 30:\n %i\n", i);
    
    printf("Clear...\n");
    clear(&list);
    print(&list);
    
    for (i=0; i<180; i++)
    {
    add(&list, (Element){i});
    }
    
    print(&list);
    clean(&list);
    
    return 0;
}
