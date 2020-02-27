
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
#include "hufflinklist.h"
#include "quantlinklist.h"
#include "soflinklist.h"

#define hufftabnum 4
#define quanttabnum 2
#define softabnum 1


//need something to convert hex to int
int totalnumcodes;
char buff1[100];
 

//these are the identifiers for each region
char hufflen[10];
char huffacdc[10];
char hufftnum[10];

char quantlen[10];
char quantprec[10];
char quanttnum[10];

char soflen[10];
char sofprec[10];
char sofheight[10];
char sofwidth[10];
char sofnumcomps[10];




char buff3[10];

//for define huffman codes
struct huffNode *huffslocation[hufftabnum];
struct huff hufftables[hufftabnum];

struct quantNode *quantslocation[quanttabnum];
struct quant quanttables[quanttabnum];

struct sofNode *sofslocation[softabnum];
struct sof softables[softabnum];


/*struct hufftab{
	//also somehow need to determine this initializer
	struct huffentry huffentries[1000];
}*/

//struct hufftab hufftables[4];

int huffind;

int numcodes;

	


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
char* getbincode(){
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
}*/

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

int breakchar=0;


FILE *ptr;
FILE *wptr;

int c;
int tablecounter=1;

//should be an int array so fillval can use it later
int codesofsize[16];
//used to stop finding quantity-codes
int codesofsizeind;



int findcodes(char* code){
	fseek(ptr, 0, SEEK_END);
	int sz = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	//ftell(ptr)!<sz;
	int codecount=0;
	//printf("round\n %d",ftell(ptr));
	//while(ptr!=EOF){
		while(1){
			//printf("round\n %d",ftell(ptr));
			fread(buff1,1, 2, ptr);
			if(ftell(ptr)>=sz){break;}
			if(strstr(buff1,"FF")!=0){
				fread(buff1,1, 2, ptr);
				if(ftell(ptr)>=sz){break;}
				if(strstr(buff1,code)!=0){
					codecount+=1;
					//breakchar=1;
				}
			}
		}
	//}
	//breakchar=0;
	//fread(huffclass2,1,6,ptr);
	return codecount;
	
}





//this is continuous so don't reset file pointer
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
	fread(hufflen,1,4,ptr);
	fread(huffacdc,1,1,ptr);
	fread(hufftnum,1,1,ptr);
	//printf("codes: %s\n",identifiers);
}

void pastffc4(void){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1,2,ptr);
			if(strstr(buff1,"C4")!=0){
				//fseek(ptr,32,SEEK_CUR);
				//fread(buff1,1,6,ptr);
				fseek(ptr,38,SEEK_CUR);
				//fread(buff1,1,18,ptr);
				breakchar=1;
			}
		}
	}
	breakchar=0;
	
}

void readtoffdb(){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1, 2, ptr);
			if(strstr(buff1,"DB")!=0){
				breakchar=1;
			}
		}
	}
	breakchar=0;
	fread(quantlen,1,4,ptr);
	fread(quantprec,1,1,ptr);
	fread(quanttnum,1,1,ptr);
	//fread(huffclass,1,6,ptr);
	//printf("codes: %s\n",identifiers);
}

void pastffdb(void){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1,2,ptr);
			if(strstr(buff1,"DB")!=0){
				//fseek(ptr,32,SEEK_CUR);
				//fread(buff1,1,6,ptr);
				fseek(ptr,6,SEEK_CUR);
				//fread(buff1,1,18,ptr);
				breakchar=1;
			}
		}
	}
	breakchar=0;
	
}
void readtoffc0(){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1, 2, ptr);
			if(strstr(buff1,"C0")!=0){
				breakchar=1;
			}
		}
	}
	breakchar=0;
	fread(soflen,1,4,ptr);
	fread(sofprec,1,2,ptr);
	fread(sofheight,1,4,ptr);
	fread(sofwidth,1,4,ptr);
	fread(sofnumcomps,1,2,ptr);
	//fread(huffclass,1,6,ptr);
	//printf("codes: %s\n",identifiers);
}

void pastffc0(void){
	while(breakchar==0){
		fread(buff1,1, 2, ptr);
		if(strstr(buff1,"FF")!=0){
			fread(buff1,1,2,ptr);
			if(strstr(buff1,"C0")!=0){
				//fseek(ptr,32,SEEK_CUR);
				//fread(buff1,1,6,ptr);
				fseek(ptr,6,SEEK_CUR);
				//fread(buff1,1,18,ptr);
				breakchar=1;
			}
		}
	}
	breakchar=0;
	
}

int huffind;



void inithuff(){

    int currind=0;
    struct huff currhuff;
    for(int rows=0;rows<hufftabnum;rows++){
	    
               currhuff=hufftables[rows];
               huffinsert(currhuff);
               //cellinsert(&tablelocation[rows],currCell);
               huffslocation[rows]=huffNodeget(currind);
               //tablelocation[rows]=cellNodeget(&hufftables[rows],currind);
               currind++;
               
	       //codoninsert(struct cellNode *tempcell,struct codon data);
 	       
				
    }
    //printf("numcells: %d",cellcount(&tablelocation[currind]));

}
void initquant(){

    int currind=0;
    struct quant currquant;
    for(int rows=0;rows<quanttabnum;rows++){
	    
               currquant=quanttables[rows];
               quantinsert(currquant);
               //cellinsert(&tablelocation[rows],currCell);
               quantslocation[rows]=quantNodeget(currind);
               //tablelocation[rows]=cellNodeget(&hufftables[rows],currind);
               currind++;
               
	       //codoninsert(struct cellNode *tempcell,struct codon data);
 	       
				
    }
    //printf("numcells: %d",cellcount(&tablelocation[currind]));

}
void initsof(){

    int currind=0;
    struct sof currsof;
    for(int rows=0;rows<softabnum;rows++){
	    
               currsof=softables[rows];
               sofinsert(currsof);
               //cellinsert(&tablelocation[rows],currCell);
               sofslocation[rows]=sofNodeget(currind);
               //tablelocation[rows]=cellNodeget(&hufftables[rows],currind);
               currind++;
               
	       //codoninsert(struct cellNode *tempcell,struct codon data);
 	       
				
    }
    //printf("numcells: %d",cellcount(&tablelocation[currind]));

}

void inithuffstats(){
	ptr=fopen("houtput.txt","r");
	//readtoffc4();
	for(int i=0;i<hufftabnum;i++){
		codesofsizeind=0;
		//ptr=fopen("houtput.txt","r");
		
		readtoffc4();
		huffmodclass(i,strtol(hufflen,NULL,16),strtol(huffacdc,NULL,16),strtol(hufftnum,NULL,16));
		//wptr=fopen("cofl.txt","a+")huffsubinsert(location[0],temphuffsub);;
	
		//0 to 15 is 16
		while(codesofsizeind!=16){
			//printf("stored %d\n",huffsubget(location[0],0).data);
			fread(buff1,1, 2, ptr);
  			printf("%s\n",buff1);
                        struct huffsub temphuffsub;
                        
			temphuffsub.data=strtol(buff1, NULL, 16);
   			huffsubinsert(huffslocation[i],temphuffsub);
			//huffsubinsert(&tablelocation[i],temphuffsub);
			
			
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
			//struct huffsub temphuffsub;
			//temphuffsub.data=strtol(buff1, NULL, 16);
			fprintf(wptr,"# of codes of %d bits:%d\n",codesofsizeind+1,huffsubget(huffsubNodeGet(huffslocation[i],codesofsizeind)).data);
			codesofsizeind++;
		}
	}
	fclose(wptr);
}
void initquantstats(){
	ptr=fopen("houtput.txt","r");
	//readtoffc4();
	for(int i=0;i<quanttabnum;i++){
		//ptr=fopen("houtput.txt","r");
		readtoffdb();

		
		
		quantmodclass(i,strtol(quantlen,NULL,16),strtol(quantprec,NULL,16),strtol(quanttnum,NULL,16));
		// or modnodeclass getnode[i]=quanttabnum;
		
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
			//struct quantsub tempquantsub;
			//tempquantsub.data=strtol(buff1, NULL, 16);
			fprintf(wptr,"# of codes of %d bits:%d\n",codesofsizeind+1,quantsubget(quantsubNodeGet(quantslocation[i],codesofsizeind)).data);
			codesofsizeind++;
		}
	}
	fclose(wptr);
}

void initsofstats(){
	ptr=fopen("houtput.txt","r");
	//readtoffc4();
	for(int i=0;i<softabnum;i++){
		//ptr=fopen("houtput.txt","r");
		readtoffc0();

		
		char soflen[10];
		char sofprec[10];
		char sofheight[10];
		char sofwidth[10];
		char sofnumcomps[10];
		sofmodclass(i,strtol(soflen,NULL,16),strtol(sofprec,NULL,16),strtol(sofheight,NULL,16),strtol(sofwidth,NULL,16),strtol(sofnumcomps,NULL,16));
		// or modnodeclass getnode[i]=softabnum;
		
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
			//struct sofsub tempsofsub;
			//tempsofsub.data=strtol(buff1, NULL, 16);
			fprintf(wptr,"# of codes of %d bits:%d\n",codesofsizeind+1,sofsubget(sofsubNodeGet(sofslocation[i],codesofsizeind)).data);
			codesofsizeind++;
		}
	}
	fclose(wptr);
}



void inithuffdata(){
	ptr=fopen("houtput.txt","r");
	//pastffc4();
	
	//printf("table %d speccode: %d\n",table,strtol(buff1, NULL, 16));
	//go past quantity-codes
	for(int table=0;table<hufftabnum;table++){
		fseek(ptr,0,SEEK_SET);
		for(int runpast=0;runpast<table+1;runpast++){
			pastffc4();
		}
		//takes number from codes of size
		for(int huffsub=0;huffsub<16;huffsub++){
			int numcodes= huffsubget(huffsubNodeGet(huffslocation[table],huffsub)).data;
			//don't want or need to record those
			//speccodeinsert(huffsubNodeGet(tablelocation[0],0),10);
			for(int k=0;k<numcodes;k++){
				fread(buff3,1, 2, ptr);
				huffspeccodeinsert(huffsubNodeGet(huffslocation[table],huffsub),strtol(buff1, NULL, 16));
				printf("table %d speccode: %d\n",table,strtol(buff3, NULL, 16));
			}
		}
		
	}
	fclose(ptr);
}
void initquantdata(){
	ptr=fopen("houtput.txt","r");
	//pastffc4();
	
	//printf("table %d speccode: %d\n",table,strtol(buff1, NULL, 16));
	//go past quantity-codes
	for(int table=0;table<quanttabnum;table++){
		fseek(ptr,0,SEEK_SET);
		for(int runpast=0;runpast<table+1;runpast++){
			pastffdb();
		}
		//takes number from codes of size

		//-3 because of identifiers
		for(int quantsub=0;quantsub<quantget(table).length-3;quantsub++){
				fread(buff3,1, 2, ptr);
				//quantspeccodeinsert(quantsubNodeGet(tablelocation[table],quantsub),strtol(buff1, NULL, 16));
                                struct quantsub tempquantsub;
				tempquantsub.data=strtol(buff3, NULL, 16);
   				quantsubinsert(quantslocation[i],tempquantsub);
				
				//printf("table %d speccode: %d\n",table,strtol(buff3, NULL, 16));
		}
		
	}
	fclose(ptr);
}
void initsofdata(){
	ptr=fopen("houtput.txt","r");
	//pastffc4();
	
	//printf("table %d speccode: %d\n",table,strtol(buff1, NULL, 16));
	//go past quantity-codes
	for(int table=0;table<softabnum;table++){
		fseek(ptr,0,SEEK_SET);
		for(int runpast=0;runpast<table+1;runpast++){
			pastffc0();
		}
		//takes number from codes of size

		//-3 because of identifiers
		for(int sofsub=0;sofsub<sofget(table).length-8;sofsub++){
				struct sofsub tempsofsub;
				fread(buff3,1, 2, ptr);
				//quantspeccodeinsert(quantsubNodeGet(tablelocation[table],quantsub),strtol(buff1, NULL, 16));
				tempsofsub.compid=strtol(buff3, NULL, 16);
				fread(buff3,1, 1, ptr);
				tempsofsub.sampfacth=strtol(buff3, NULL, 16);
				fread(buff3,1, 1, ptr);
				tempsofsub.sampfactv=strtol(buff3, NULL, 16);
				fread(buff3,1, 2, ptr);
				tempsofsub.quanttnum=strtol(buff3, NULL, 16);
   				sofsubinsert(sofslocation[i],tempsofsub);
				
				//printf("table %d speccode: %d\n",table,strtol(buff3, NULL, 16));
		}
		
	}
	fclose(ptr);
}
/*void inithuffdata(){
	
	//speccodeinsert(struct codonNode *tempcodonNode,struct codesoflenlist data)
}*/
void main(){
	ptr=fopen("houtput.txt","r");
	//static int hufftabnum=findcodes("C4");
	printf("#fdda: %d \n", findcodes("DA"));
	printf("#ffc0: %d \n", findcodes("C0"));
	printf("#ffc4: %d \n", findcodes("C4"));
	printf("#ffdb: %d \n", findcodes("DB"));
	//findffda();
	//findffda();
	fclose(ptr);
	inithuff();
	//inithuffstats();
	//inithuffdata();
	huffmodclass(0,1);
	printf("modclass: %d\n",huffget(0).huffclass);
	
	
}
		
//also need function to reset reading

//void readto something else
//fclose or no fclose?????



