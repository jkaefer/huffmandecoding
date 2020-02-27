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
	} htmember; 
	int total;
	int col[16];
}


struct gohtember gohtmembers[4];





//int argc, char *argv[]
void main(){
	FILE *ptr;
	FILE *wptr;
	ptr=fopen("houtput.txt","r");

	while ( fgets ( line, 5, ptr ) != NULL ){
			    lines+=1;
				if((strstr(line,"FFDA"))!=NULL){
					
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
					gohtmembers[i].col[nolc]=sti(line);
					total[i]+=(sti(line));
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
					gohtmembers[i].col[nolc]=sti(line);
					total[i]+=(sti(line));
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
			fseek(ptr,colind[i]-7,SEEK_SET);
				while((fgets(line, 7,ptr)!=NULL)&&(sv==0)){
					printf("%s\n",line);
					sv=1;
				}
			sv=0;
			fseek(ptr,0,SEEK_SET);
			}
			fclose(ptr);
	    break;
	}
}