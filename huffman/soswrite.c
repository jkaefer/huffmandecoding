#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<winuser.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include <time.h>
char line[10];
int lines;
int sosind;
void main(){
	FILE *ptr;
	FILE *wptr;
	ptr=fopen("houtput.txt","r");

	while ( fgets ( line, 7, ptr ) != NULL ){
				if((strstr(line,"FF DA "))==NULL){
					sosind=lines;
				}
				lines+=1;
    }
    lines=0;
	fclose(ptr);
	ptr=fopen("houtput.txt","r");
	wptr=fopen("sosoutput.txt","a+");

	fseek(ptr,sosind,SEEK_SET);
	
	while(fgets(line,10,ptr)!=NULL){
		fprintf(wptr,"%s",line);
	}
}
	
	