#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){ 
    //initscr ();
    //curs_set(0);
        
        
	FILE *fp=fopen("sequence.txt","r");
	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);  /* same as rewind(f); */

	char *genome = malloc(fsize + 1);
	fread(genome, fsize, 1, fp);
	fclose(fp);
        
	fp=fopen("gene.txt","r");
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);  /* same as rewind(f); */

	char *gene = malloc(fsize + 1);
	fread(gene, fsize, 1, fp);
	fclose(fp);

	int genomelen=strlen(genome);
	int genelen=strlen(gene);
	
	int maxscore;
	//maxscoreind is the starting point of the gene in the genome
	int maxscoreind;
	int scorecounter;

	while(i<genomelen){
		for(int j=i;j<genelen+i;j++){
			if(strcmp(gene[j-i],genome[j])==0){
			    scorecounter++;
			}
			//no reason to have an else case
		}
		//updating maxscore
		if(scorecounter>maxscore){maxscore=scorecounter; maxscoreind=i;}
		scorecounter=0;
		i++;
		//break because otherwise comparing irrelevant memory and may cause segfault
		if((genomelen-i)<genelen){break;}
	}
	//trying to print that segment that matches the closest
	for(int i=maxscoreind;i<genelen+maxscoreind;i++){
		printf("%c",genome[i]);
	}
}
