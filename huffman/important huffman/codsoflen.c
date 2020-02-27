
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<winuser.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include <sys/stat.h>
#include <time.h>




/*
struct intermedcode{
	int size;
	char literalcode[50];
};
*/

//need something to convert hex to int
int totalnumcodes;
char buff1[100];
char buff2[100];

/*
struct codefromtree {
   char hexcode[5];
   char bincode[50];
}
*/
/*
int intermedcodeind;
int numcodes;
void intermedfill(void){
	struct intermedcode intermedcodes[totalnumcodes];
	    //go past quantity-codes
		pastffc4();
		//takes number from codes of size
		for(int j;j<16;j++){
			int numcodes= codesofsize[j];
			for(int k;k<numcodes;k++){
				fread(buff1,1, 2, ptr);
				//good because only codes supposed to be are there
				intermedcodes[intermedcodeind].literalcode=buff1;
				intermedcodes[intermedcodeind].size=j;
				intermedcodeind++;
			}
		}
		//resetting for other huffman tables
		intermedcodeind=0;
}	
*/

/*
Coord getChild(){
	Coord temp;
	temp=(last.row+1,last.column+last.column);
	return temp;
}
Coord getRight(){
	Coord temp;
	temp=(last.row,last.column+1);
	return temp;
}
*/
/*
char *getbincode(){
	String code;
	Coord currcoord;
	for(int j=0; j<totalnumcodes;j++){
		currcoord=treecodes[j].coord;
		//for each individual code
		while(currcoord!=(0,0)){
			if(currcoord.column%2==0){
				//add 0 to end because it is even
				//the column is a tricky issue
				strcat(code,"0");
				currcoord=(currcoord.row-1,currcoord.column-(currcoord.column/2));
			}
			else{
				//add 1 to end because it is odd
				strcat(code,"1");
				currcoord=(currcoord.row-1,currcoord.column-(currcoord.column-1)/2));
			}
		}
	}
	return code;
}
*/

/*
//index is for tree number
//find a way to construct the tree and fill in codes to struct array
void fillfromtree(int i){
//needs to be constructed after totalnumcodes is counted.
//this is just for one tree
//data is null because no code is of 0 bits
	
//need coord structure for lasttaken
int last;
int columnind;
int currrowmax;
struct codefromtree treecodes[totalnumcodes];
for(int j=0;j<totalnumcodes;j++){
	
	treecodes[j].literalcode=intermedcodes[j].literalcode;
	if(intermedcodes[j].size==last.x){
		treecodes[j].bincode=(intermedcodes[j].size,last.getRight());
	}
	else{
		treecodes[j].bincode=(intermedcodes[j].size,last.getChild());
	}
	
		//take it theoretically but not actually and 
		
		//calculate bincode;
		taken[intermedcodes[j].size][columnind]=1;
	}
	while(taken[intermedcodes[j].size][columnind]==1){
		columnind++;
		//calculate bincode;
	}
	taken[intermedcodes[j].size][columnind]=1;

    //save in huffman table marked by index i from argument of function
}
*/

int breakchar;
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
}
void main(){
	ptr=fopen("houtput.txt","r");
	wptr=fopen("cofl.txt","a+");
	for(int i=0;i<4;i++){
		codesofsizeind=0;
		//ptr=fopen("houtput.txt","r");
		readtoffc4();
		//wptr=fopen("cofl.txt","a+");
		fprintf(wptr,"\nTable %d:\n",tablecounter);
		tablecounter++;
		//0 to 15 is 16
		while(codesofsizeind!=16){
			fread(buff1,1, 2, ptr);
			fprintf(wptr,"# of codes of %d bits:%s\n",codesofsizeind,buff1);
			//adding to total number of codes in single tree
			totalnumcodes+=strtol(buff1, NULL, 16);
			//putting # of codes according to their bit size
			codesofsize[codesofsizeind]=strtol(buff1, NULL, 16);
			codesofsizeind++;
		}
		//pastffc4();
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		//intermedfill(i);
		//fillfromtree(i);
		
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
	}
	fclose(ptr);
	fclose(wptr);
	
}
		
//also need function to reset reading

//void readto something else
//fclose or no fclose?????


void pastffc4(void){
	ptr=fopen("houtput.txt","r");
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")==0){
			if(strstr(buff1,"C4")!=0){
				//32 chars plus identifier of huffman table=38
				fread(buff1,1,38,ptr);
				breakchar=1;
			}
		}
	}
	//maybe no fclose but instead a send back to the beginning
	fclose(ptr);
}
