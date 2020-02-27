
#include <stdio.h>
#include <stdlib.h>

 
 
void main(int argc, char * argv[])
{
    int c;                   
    FILE *ptr;
    FILE *wptr;	
    char line[81];        
    ptr = fopen(argv[1],"rb");
	wptr=fopen("houtput.txt","a+");
	c=fgetc(ptr);
    while (c != EOF )
    {
       //printf("%02X", (unsigned char) c);
	   fprintf(wptr,"%02X",(unsigned char) c);
	   c=fgetc(ptr);
    }
    fclose(ptr);
	fclose(wptr);
	

}

 
 
