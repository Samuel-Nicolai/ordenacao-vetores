#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int *leEntrada(char nomeArquivo[], int tamanho){
	FILE *arquivo;
	int *vet , i = 0;

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Nao foi possivel ler o arquivo!\n");
        return NULL;
    }    
    else{
    	vet = calloc(tamanho, sizeof(int));
    	if(vet == NULL){
    		printf("Nao foi possivel alocar memoria\n");
    		return NULL;
    	}
    	else{
    		while(fscanf(arquivo, "%d\n", (vet + i)) != EOF){
    			i++;
    		}
    		return vet;
    	}
    }
    fclose(arquivo);
}

int *geraVetorAleatorio(int semente, int tamanho){
	int *vet, i;

	vet = calloc(tamanho, sizeof(int));
	if(!vet){
		printf("Nao foi possivel alocar memoria para o vetor!\n");
		return NULL;
	}
	else{
		srand(semente);
		for(i = 0; i < tamanho; i++){
			vet[i] = rand() % tamanho;
		}
		return vet;
	}
}

void salvaEstatistica(int *v, char saida[], int tamanho, int nComp, int nMov){
    FILE *arquivo;
    int i;

    arquivo = fopen(saida, "a");
    if(arquivo == NULL){
        printf("Nao foi possivel escrever no arquivo.\n");
        return;
    }
    else{
    	fprintf(arquivo, "tamanho: %d\ncomparacoes: %d\nmovimentacoes: %d\n\n", tamanho, nComp, nMov);
    }
    fprintf(arquivo, "{\t");
    for(i = 0; i < tamanho; i++)
    	fprintf(arquivo, "%d\t", v[i]);
    fprintf(arquivo, "}\n\n");
    fclose(arquivo);
}