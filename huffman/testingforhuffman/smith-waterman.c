#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>



 int currmax=0;
  int currmaxi=0;
  int currmaxj=0;

int max(int a,int b){
	int max= a > b ? a : b;
     	return max;

}

int levenshtein_n(const char *a, const int length, const char *b, const int bLength,int matchscore,int gapscore, int cache[strlen(a)+1][strlen(b)+1]) {
  //int cache[length][bLength];
  for(int i=0;i<length;i++){
	for(int j=0;j<bLength;j++){
		cache[i][j]=0;
	}
  }

  for(int i=1;i<length;i++){
	for(int j=1;j<bLength;j++){
		// j in itertools.product(range(1, H.shape[0]), range(1, H.shape[1])):
		int match = a[i - 1] == b[j - 1] ? cache[i - 1][j - 1] + matchscore : cache[i - 1][j - 1] - matchscore;
        	//int match = cache[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? matchscore : - matchscore);
        	int delete = cache[i - 1][j] - gapscore;
        	int insert = cache[i][j - 1] - gapscore;
		
        	cache[i][j] = max(max(max(match, delete), insert),0);
		//printf("match:%d\n",cache[i][j]);
		//break;
		currmaxi=cache[i][j]>currmax?i:currmaxi;
		currmaxj=cache[i][j]>currmax?j:currmaxj;
		currmax=max(currmax,cache[i][j]);
	}
	//printf("a:%c b:%c\n",a[currmaxi],b[currmaxj]);
  }
  return currmax;
    //return H

  //free(cache);

  //return result;
}

int
levenshtein(const char *a, const char *b,int cache[strlen(a)+1][strlen(b)+1]) {
  const int length = strlen(a)+1;
  const int bLength = strlen(b)+1;

  return levenshtein_n(a, length, b, bLength,3,2,cache);
}

void main(){

	
	char* a="GGTTGACTA";
	char* b="TGTTACGG";
	int cache[strlen(a)+1][strlen(b)+1];
	
	printf("%d\n",levenshtein(a, b,cache));
	printf("a: %c b: %d\n",a[currmaxi],b[currmaxj]);

	for(int i=0;i<strlen(a)+1;i++){
	for(int j=0;j<strlen(b)+1;j++){
		printf("%d",cache[i][j]);
	}
	printf("\n");
 	 }
        
	int tracebkstrsz=0;
	//if(strlen(a)>strlen(b)){
		tracebkstrsz=strlen(a)>strlen(b)?strlen(a):strlen(b);

	//}
	char tracebkstr1[tracebkstrsz+1];
	char tracebkstr2[tracebkstrsz+1];
	//not evaluating currmax here, but ones before
	char addchara;
	char addcharb;
	//if(a[currmaxi]==b[currmaxj]){addcharb=a[currmaxi];addcharb=a[currmaxj]}
	//else{addchara="";addcharb="";}

	//tracebkstr1[0]=addchara;
	//tracebkstr2[0]=addcharb;
	
        //because already have 0
	int tracebkind=0;
	int i=currmaxi;
	int j=currmaxj;
	while(i>=1&&j>=1){
	//for(int i=currmaxi;i>=0;i--){
		//for(int j=currmaxj;j>=0;j--){
			if(a[i-1]==b[j-1]){
				//done
				tracebkstr1[tracebkind]=a[i-1];
				tracebkstr2[tracebkind]=b[j-1];
				//diag by default
				i--;
				j--;
				tracebkind++;
				continue;
			}else{
				//int diag=0;
				int up=0;
				int left=0;
				int nextmax = 0;
				//if(i>2&&j>2){
				 //diag = cache[i - 1][j-1];
				up = cache[i-1][j];
				left = cache[i][j-1];
				nextmax = max(up, left);
				
				if(nextmax==up){
					addchara=a[i-1];
					addcharb='-';
					i--;			
				}
				if(nextmax==left){
					addchara='-';
					addcharb=b[j-1];	
					j--;		
				}
				//printf("chara: %c charb: %c\n",addchara,addcharb);
				tracebkstr1[tracebkind]=addchara;
				tracebkstr2[tracebkind]=addcharb;
				tracebkind++;
				continue;
			}
			
			
			//currmaxi
			//printf("%d\n",cache[currmaxi][currmaxj]);
		//}
	}
	tracebkstr1[tracebkind]='\0';
	tracebkstr2[tracebkind]='\0';
	printf("%s\n",tracebkstr1);
	printf("%s\n",tracebkstr2);
	
}
