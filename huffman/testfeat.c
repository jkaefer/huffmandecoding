
#include<stdio.h>
#include<stdlib.h>
//#include<windows.h>
//#include<winuser.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include <time.h>
//#include "doublylinkdlst.h"
#include "celllinklist.h"




//need something to convert hex to int
int totalnumcodes;
char buff1[100];
char buff2[100]; 

//for define huffman codes
struct cellNode *tablelocation[4];
struct cell hufftables[4];

struct cellNode *quantslocation[4];
struct cell quanttables[4];


/*struct hufftab{
	//also somehow need to determine this initializer
	struct huffentry huffentries[1000];
}*/

//struct hufftab hufftables[4];

int huffind;

int numcodes;

	



int breakchar=0;
char arrayOfChars[50]; // a single array of characters
char *arrayOfArraysOfChars[10]; // array to hold multiple single arrays of characters

FILE *ptr;
FILE *wptr;

int c;
int tablecounter=1;

//should be an int array so fillval can use it later
int codesofsize[16];
//used to stop finding quantity-codes
int codesofsizeind;

void readtoffc4(){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1, 2, ptr);
			if(strstr(buff1,"C4")!=0){
				breakchar=1;
			}
		}
	}
	breakchar=0;
	fread(buff2,1,6,ptr);
	printf("codes: %s\n",buff2);
}

void pastffc4(void){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")==0){
			if(strstr(buff1,"C4")!=0){
				fread(buff1,1,32,ptr);
				breakchar=1;
			}
		}
	}
	breakchar=0;
	
}

int huffind;



void inithuffcells(){

    int currind=0;
    struct cell currCell;
    for(int rows=0;rows<4;rows++){
	    
               currCell=hufftables[rows];
               cellinsert(0,currCell);
               //cellinsert(&tablelocation[rows],currCell);
               tablelocation[rows]=cellNodeget(0,currind);
               //tablelocation[rows]=cellNodeget(&hufftables[rows],currind);
               currind++;
               
	       //codoninsert(struct cellNode *tempcell,struct codon data);
 	       
				
    }
    printf("numcells: %d",cellcount(&tablelocation[currind]));

}

void inithuffstats(){
	ptr=fopen("houtput.txt","r");
	//readtoffc4();
	for(int i=0;i<4;i++){
		codesofsizeind=0;
		//ptr=fopen("houtput.txt","r");
		
		readtoffc4();
		//wptr=fopen("cofl.txt","a+")codoninsert(location[0],tempcodon);;
	
		//0 to 15 is 16
		while(codesofsizeind!=16){
			//printf("stored %d\n",codonget(location[0],0).data);
			fread(buff1,1, 2, ptr);
  			printf("%s\n",buff1);
                        struct codon tempcodon;
                        
			tempcodon.data=strtol(buff1, NULL, 16);
   			codoninsert(tablelocation[i],tempcodon);
			//codoninsert(&tablelocation[i],tempcodon);
			
			
			//adding to total number of codes in single tree
			//converting hex to decimal
			totalnumcodes+=strtol(buff1, NULL, 16);
			//putting # of codes according to their bit size
			//codesofsize[codesofsizeind]=strtol(buff1, NULL, 16);
			codesofsizeind++;
		}
		huffind=i;
	}
	fclose(ptr);
	
	
	codesofsizeind=0;
        wptr=fopen("cofl.txt","a+");
	for(int i=0;i<4;i++){
		fprintf(wptr,"\nTable %d:\n",tablecounter);
		tablecounter++;
		codesofsizeind=0;
		while(codesofsizeind!=16){
 			//codesofsizeind++;
			//struct codon tempcodon;
			//tempcodon.data=strtol(buff1, NULL, 16);
			fprintf(wptr,"# of codes of %d bits:%d\n",codesofsizeind+1,codonget(tablelocation[i],codesofsizeind).data);
			codesofsizeind++;
		}
	}
	fclose(wptr);
}

void inithuffdata(){
	struct codesoflenlist listentry;
	listentry.data=50;
	//for(int i=0;i<3;i++){
		speccodeinsert(codonNodeGet(tablelocation[0],6),listentry);
	//}
	
}
/*void inithuffdata(){
	
	//speccodeinsert(struct codonNode *tempcodonNode,struct codesoflenlist data)
}*/
void main(){
	inithuffcells();
	inithuffstats();
	inithuffdata();
	//printf("speccode: %d \n",speccodeget(codonNodeGet(tablelocation[0],0),1));
}
		
//also need function to reset reading

//void readto something else
//fclose or no fclose?????



