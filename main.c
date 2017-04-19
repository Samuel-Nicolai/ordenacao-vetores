#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "io.h"
#include "sort.h"

#define STRING 15

int main() {
	int *v, tam, escolha = 0;
	char entrada[STRING], saida[STRING];
	int nComp = 0, nMov = 0;

	printf("Digite o nome do arquivo de numeros aleatorios: \n");
	scanf("%s", entrada);
	printf("Digite o tamanho do vetor de numeros aleatorios: \n");
	scanf("%d", &tam);

	v = leEntrada(entrada, tam);

	while(escolha < 1 || escolha > 6){
	    printf("Escolha o algoritimo de ordenacao:\n1. BubbleSort\n2. BubbleSort Inteligente\n3. SelectSort\n4. InsertSort\n5. MergeSort\n6. QuickSort\n");
	    scanf("%d", &escolha);
	    if(escolha == 1)
	    	bubbleSort(v, tam, &nComp, &nMov);
	    else{
	    	if(escolha == 2)
	    		bubbleSortInteligente(v, tam, &nComp, &nMov);
	    	else{
	    		if(escolha == 3)
	    			selectSort(v, tam, &nComp, &nMov);
	    		else{
	    			if(escolha == 4)
	    				insertSort(v, tam, &nComp, &nMov);
	    			else{
	    				if(escolha == 5)
	    					mergeSort(v, 0, tam - 1, &nComp, &nMov);
	    				else{
	    					if(escolha == 6)
	    						quickSort(v, 0, tam - 1, &nComp, &nMov);
	    					else
	    						printf("Escolha invalida digite novamente:\n");
	    				}
	    			}
	    		}
	    	}
	    }
	}

	printf("Digite o nome do arquivo de saida: \n");
	scanf("%s", saida);
	salvaEstatistica(v, saida, tam, nComp, nMov);
	free(v);
    return 0;
}