/*
* Quicksort
* Author: Alexandre A. A. M de Abreu
*/
#include <stdio.h>

#define N 6

void imprimir(int vet[]) {
	for (int i = 0; i < N; i++)
		printf("%d - ", vet[i]);
	printf("\n");
}

int particao(int vet[], int esq, int dir) {
	int pivo, i, j, aux;

	pivo = vet[esq];
	i = esq; 
	j = dir;
		
	while (i < j) {
		while (vet[i] <= pivo && i <= dir) i++;
		while (vet[j] > pivo) j--;
		if (i < j) {
			aux = vet[i]; 
			vet[i] = vet[j];
			vet[j] = aux;
		}
	}

	aux = vet[esq];
	vet[esq] = vet[j];
	vet[j] = aux;

	return j;
}

void quick_sort(int vet[], int esq, int dir) {
	int j;
	// Etapa de divisao e conquista
	if (esq < dir) {
		j = particao(vet, esq, dir);
		quick_sort(vet, esq, j-1);
		quick_sort(vet, j+1, dir);
	}
	
}

int main() {
	int vet[N] = {6, 3, 9, 7, 4, 1};
	int i;

	imprimir(vet);
	quick_sort(vet, 0, N - 1);
	imprimir(vet);

	return 0;
}


