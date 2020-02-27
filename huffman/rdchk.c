#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<winuser.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include <time.h>
int count=0;
int coltr;
int htlc;
int sv,sv2,htmcount;
char line[1];
int htind[4];
int colind[4];
int lines=1;
int i;



//huffman tree member
struct gohtmember{
	struct htmember {
			int length;
			char* huffcode;
	} htmember; 
	int total;
	int col[16];
}

struct gohtember gohtmembers[4];

//preference to 0 side for first code and if multiple codes of given length
void huffsort(char *gohtmembers[i].members[x]){
	/*
	switch(){
		case:
		break;
		*/
	if(gohtmembers[i].members[x].length==1){
		gohtmembers[i].members[x].huffcode="0";
	}
	if(gohtmembers[i].members[x].length==2){
		gohtmembers[i].members[x].huffcode="00";
	}
	//rest of sixteen lengths
	for(j=2;j<16;j++){
		//zero preferenced,need a ledger
		if(gohtmembers[i].col[j]>1){
			gohtmembers[i].members[x].huffcode="
			
			
	
}

//int argc, char *argv[]
void main(){
	FILE *ptr;
	FILE *wptr;
	ptr=fopen("houtput.txt","r");

	while ( fgets ( line, 5, ptr ) != NULL ){
			    lines+=1;
				if((strstr(line,"FFC4"))!=NULL){
					
					htind[i]=lines;
					coltr=htind[i];
					colind[i]=coltr+6;
					i++;
				}
        }
		lines=0;
		i=0;
		fclose(ptr);
		
    ptr=fopen("houtput.txt","r");
	//count huffman table marker count
	for(i=0;i<4;i++){
		if(htind[i]!=0){
			htmcount++;
		}
	}
	switch(htmcount){ 
		case 0:
		
	    break;
		case 1:
				//total # members for each table
				fseek(ptr,colind[i],SEEK_SET);
				while(fgets(line, 3, ptr)&& (nolc<16)){
					//nolc++;
					gohtmembers[i].col[nolc]=atoi(line);
					total[i]+=atoi(line);
					nolc++
					//codes of length index
					
				}
				gohtmembers[i].total=total[i];
				//i++;
				nolc=0;
		        fclose(ptr);
				
				for(i=1;i<5;i++){
					while(fgets(line, 3, ptr)&& (nolc<16)){
					//nolc++;
					gohtmembers[i].col[nolc]=atoi(line);
					total[i]+=atoi(line);
					nolc++;
					//codes of length index
					
				}
				gohtmembers[i].total=total[i];
				//i++;
				nolc=0;
		        fclose(ptr);
				
				//members of certain length
				for (i=0;i<4;i++){
				 for (j=0;j<16;j++){
				   for(x=0;x<gohtmembers[i].total;x++){
					if(gohtmembers[i].col[j]!=0){
						gohtmembers[i].members[x]=gohtmembers[i].col[j];
						gohtmembers[i].members[x].length=j+1;
					}
				   }
				 }
				}
		break;
		case 2:
		break;
	
		case 3:
	
	    break;
		
		case 4:
			for(i=0;i<htmcount;i++){
			fseek(ptr,colind[i],SEEK_SET);
				while(fgets(line, 3, ptr)&& (nolc<16)){
					gohtmembers[i].col[nolc]=atoi(line);
					total[i]+=atoi(line);
					nolc++;
				}
            nolc=0;
			fseek(ptr,0,SEEK_SET);
			}
			fclose(ptr);
			//members of certain length
				for (i=0;i<4;i++){
				 for (j=0;j<16;j++){
				   for(x=0;x<gohtmembers[i].total;x++){
					if(gohtmembers[i].col[j]!=0){
						gohtmembers[i].members[x]=gohtmembers[i].col[j];
						gohtmembers[i].members[x].length=j+1;
					}
				   }
				 }
				}
	    break;
	}
}