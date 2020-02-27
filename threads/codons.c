

struct gene{
   struct codonNode *next;
}

struct geneNode{
   struct gene data;
   struct geneNode *next;
};

struct amino {
    char acid;
};

struct aminoNode{
   struct amino data;
   struct aminoNode *next;
};

struct codon {
    char one;
    char two;
    char three;
};

struct codonNode{
   struct codon data;
   struct codonNode *next;
};

void codonify(struct cellNode *tempcellnp){
   struct codonNode *link = (struct codonNode*) malloc(sizeof(struct codonNode));
   struct codonNode *p;
   int i=0;
  
   while(i<paircount(tempcellnp)){
        char one;
        char two;
        char three;
        for(int j=i;j<i+3;j++){
		char temp=pairget(tempcellnp,j).base;
		switch(temp){
		   case 'A':
		   break;
		   case 'T':
			if(j==i){one='U';}
			else{one=temp;}
			if(j==i+1){two='U';}
			else{two=temp;}
			if(j==i+2){three='U';}
			else{three=temp;}
		   break;
		   case 'G':
		   break;
		   case 'C':
		   break;
		}
	}
	struct codon data={one,two,three};
        codoninsert(tempcellnp,data);
   }
   i+=3;
    
}

void codoninsert(struct cellNode *tempcellnp,struct codon data) {
   //create a link
   struct codonNode *link = (struct codonNode*) malloc(sizeof(struct codonNode));
   struct codonNode *p;
   
   //tempcell=cellget(cellind);
   //link->key = key;
   link->data = data;

   //point it to old first cellNode
   link->next = NULL;

   if(tempcellnp->data.codonHead == NULL){
        tempcellnp->data.codonHead = link;     //when linked list is empty
    }
    else{
        p  = tempcellnp->data.codonHead;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last cellNode.The last cellNode always points to NULL.
        }
        p->next = link;//Point the previous last cellNode to the new cellNode created.
    }

   //point first to new first cellNode
   //head = link;
}

void aminify(struct cellNode *tempcellnp){
   int i=0;
  
   while(i<codoncount(tempcellnp)){
        struct codon tempcodon = codonget(tempcellnp,i);
        //look through amino acid codes
        struct amino tempamino= aminosearch(tempcellnp,i);
        aminoinsert(tempcellnp,tempamino);
   }
   i++;
}

struct amino aminosearch(struct cellNode *tempcellnp, int codonind){
	struct codon temp= codonget(tempcellnp,codonind);
        
         
}

void rnapol(){
   

}

//amino acids

char *isoleucine(I)[3]={"AUU","AUC","AUA"};
char *leucine(L)[6]={"CUU","CUC","CUA","CUG","UUA","UUG"};
char *valine(V)[4]={"GUU","GUC","GUA","GUG"};
char *phenylalanine(F)[2]={"UUU","UUC"};
char *methionine(M)[1]={"AUG"};
char *cysteine(C)[2]={"UGU","UGC"};
char *alanine(A)[4]={"GCU","GCC","GCA","GCG"};
char *glycine(G)[4]={"GGU","GGC","GGA","GGG"};
char *proline(P)[4]={"CCU","CCC","CCA","CCG"};
char *threonine(T)[4]={"ACU","ACC","ACA","ACG"};
char *serine(S)[6]={"UCU","UCC","UCA","UCG","AGU","AGC"};
char *tyrosine(Y)[2]={"UAU","UAC"};
char *tryptophan(W)[1]={"UGG"};
char *glutamine(Q)[2]={"CAA","CAG"};
char *asparagine(N)[2]={"AAU","AAC"};
char *histidine(H)[2]={"CAU","CAC"};
char *glutamicacid(E)[2]={"GAA","GAG"};
char *asparticacid(D)[2]={"GAU","GAC"};
char *lysine(K)[2]={"AAA","AAG"};
char *arginine(R)[6]={"CGU","CGC","CGA","CGG","AGA","AGG"};
char *stop(/)[3]={"UAA","UAG","UGA"};







