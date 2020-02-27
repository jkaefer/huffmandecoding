#ifndef AMINO_ACIDS_H
#define AMINO_ACIDS_H

//codons come from rna
//so the pairs need to be translated somehow

char *codes[64][2]={
//isoleucine
	{"ATT","I"},{"ATC","I"},{"ATA","I"},
//leucine
	{"CTT","L"},{"CTC","L"},{"CTA","L"},{"CTG","L"},{"TTA","L"},{"TTG","L"},
//valine
	{"GTT","V"},{"GTC","V"},{"GTA","V"},{"GTG","V"},
//phenylalanine
	{"TTT","F"},{"TTC","F"},
//methionine
	{"ATG","M"},
//cysteine
	{"TGT","C"},{"TGC","C"},
//alanine
	{"GCT","A"},{"GCC","A"},{"GCA","A"},{"CCG","A"},
//glycine
	{"GGT","G"},{"GGC","G"},{"GGA","G"},{"GGG","G"},
//proline
	{"CCT","P"},{"CCC","P"},{"CCA","P"},{"CCG","P"},
//threonine
	{"ACT","T"},{"ACC","T"},{"ACA","T"},{"ACG","T"},
//serine
	{"TCT","S"},{"TCC","S"},{"TCA","S"},{"TCG","S"},{"AGT","S"},{"AGC","S"},
//tyrosine
	{"TAT","Y"},{"TAC","Y"},
//tryptophan
	{"TGG","W"},
//glutamine
	{"CAA","Q"},{"CAG","Q"},
//asparagine
	{"AAT","N"},{"AAC","N"},
//histidine
	{"CAT","H"},{"CAC","H"},
//glutamic acid
	{"GAA","E"},{"GAG","E"},
//aspartic acid
	{"GAT","D"},{"GAC","D"},
//lysine
	{"AAA","K"},{"AAG","K"},
//arginine
	{"CGT","R"},{"CGC","R"},{"CGA","R"},{"CGG","R"},{"AGA","R"},{"AGG","R"},
//stop
	{"TAA","STOP"},{"TAG","STOP"},{"TGA","STOP"}

};
/*
char *isoleucine(I)={"ATT","ATC","ATA"};
char *leucine(L)={"CTT","CTC","CTA","CTG","TTA","TTG"};
char *valine(V)={"GTT","GTC","GTA","GTG"};
char *phenylalanine(F)={"TTT","TTC"};
char *methionine(M)={"ATG"};
char *cysteine(C)={"TGT","TGC"};
char *alanine(A)={"GCT","GCC","GCA","GCG"};
char *glycine(G)={"GGT","GGC","GGA","GGG"};
char *proline(P)={"CCT","CCC","CCA","CCG"};
char *threonine(T)={"ACT","ACC","ACA","ACG"};
char *serine(S)={"TCT","TCC","TCA","TCG","AGT","AGC"};
char *tyrosine(Y)={"TAT","TAC"};
char *tryptophan(W)={"TGG"};
char *glutamine(Q)={"CAA","CAG"};
char *asparagine(N)={"AAT","AAC"};
char *histidine(H)={"CAT","CAC"};
char *glutamic acid(E)={"GAA","GAG"};
char *aspartic acid(D)={"GAT","GAC"};
char *lysine(K)={"AAA","AAG"};
char *arginine(R)={"CGT","CGC","CGA","CGG","AGA","AGG"};
char *stop(STOP)={"TAA","TAG","TGA"};
*/





#endif
