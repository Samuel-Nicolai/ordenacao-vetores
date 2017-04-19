#include <stdlib.h>
#include "sort.h"

void bubbleSort(int *v, int tam, int *nComp, int *nMov){
	int i, j, aux;

	for(i = 0; i < tam; i++){
		for(j = 0; j < tam - 1; j++){
			(*nComp)++;
			if(v[j] > v[j + 1]){
				aux = v[j + 1];
				v[j + 1] = v[j];
				v[j] = aux;
				(*nMov)++;
			}
		}
	}
}

void bubbleSortInteligente(int *v, int tam, int *nComp, int *nMov){
	int j, aux;

	while(tam > 1){
		for(j = 0; j < tam -1; j++){
			(*nComp)++;
			if(v[j] > v[j + 1]){
				aux = v[j + 1];
				v[j + 1] = v[j];
				v[j] = aux;
				(*nMov)++;
			}			
		}
		tam--;
	}
}

void selectSort(int *v, int tam, int *nComp, int *nMov){
	int marcador = 0, menor, i, aux;

	while(marcador < tam){
		menor = marcador;
		for(i = marcador + 1; i < tam; i++){
			(*nComp)++;
			if(v[menor] > v[i]){
				menor = i;
			}
		}
		if(menor != marcador){
			aux = v[marcador];
			v[marcador] = v[menor];
			v[menor] = aux;
			(*nMov)++;
		}
		marcador++;
	}
}

void insertSort(int *v, int tam, int *nComp, int *nMov){
	int marcador, pos, aux;
	for(marcador = 1; marcador < tam; marcador++){
		pos = marcador - 1;
		aux = v[marcador];
		while(aux < v[pos] && pos >= 0){
			v[pos + 1] = v[pos];
			pos--;
			(*nComp)++;
			(*nMov)++;
		}
		(*nMov)++;
		v[pos + 1] = aux;
	}
}

void merge(int *v, int inicio, int meio, int fim, int *nComp, int *nMov){
	int *temp, v1, v2, tamanho, i, j, k;
	int fimV1 = 0, fimV2 = 0;

	tamanho = fim - inicio + 1;
	v1 = inicio;
	v2 = meio + 1;

	temp = calloc(tamanho, sizeof(int));

	if(temp != NULL){
		for(i = 0; i < tamanho; i++){
			if(!fimV1 && !fimV2){
				(*nComp)++;
				if(v[v1] < v[v2]){
					temp[i] = v[v1++];
					(*nMov)++;
				}
				else{
					temp[i] = v[v2++];
					(*nMov)++;
				}
				if(v1 > meio)
					fimV1 = 1;
				if(v2 > fim)
					fimV2 = 1;
			}
			else{
				(*nComp)++;
				if(!fimV1){
					temp[i] = v[v1++];
					(*nMov)++;
				}
				else{
					temp[i] = v[v2++];
					(*nMov)++;
				}
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++){
			v[k] = temp[j];
		}
	}
	free(temp);
}

void mergeSort(int *v, int inicio, int fim, int *nComp, int *nMov){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		mergeSort(v, inicio, meio, nComp, nMov);
		mergeSort(v, meio + 1, fim, nComp, nMov);
		merge(v, inicio, meio, fim, nComp, nMov);
	}
}

int particiona(int *v, int inicio, int fim, int *nComp, int *nMov){
	int pivo = v[inicio], pos = inicio, i, aux;

	for(i = inicio + 1; i <= fim; i++){
		if(v[i] < pivo){
			pos++;
			if(i != pos){
				aux = v[pos];
				v[pos] = v[i];
				v[i] = aux;
			}
		}
	}
	aux = v[pos];
	v[pos] = pivo;
	v[inicio] = aux;
	return pos; 
}

void quickSort(int *v, int inicio, int fim, int *nComp, int *nMov){
	int pivo;
	if(inicio < fim){
		pivo = particiona(v, inicio, fim, nComp, nMov);
		quickSort(v, inicio, pivo - 1, nComp, nMov);
		quickSort(v, pivo + 1, fim, nComp, nMov);
	}
}