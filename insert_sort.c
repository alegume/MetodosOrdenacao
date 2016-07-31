/*
* Insertion sort
* Author: Alexandre A. A. M de Abreu
*/
#include<stdio.h>

#define N 10

void imprimir(int vet[]) {
	for (int i = 0; i < N; i++)
		printf("%d - ", vet[i]);
	printf("\n");
}

void inicializar(int *vet) {
	for (int i = N - 1; i >= 0; i--)
		vet[i] = N - i;
}

int main() {
	int vet[N], aux, j;
	inicializar(&vet[0]);
	imprimir(vet);

	for (int i = 1; i < N; i++) { // A partir do segundo elemento
		aux = vet[i]; // Copia do elemento a ser movido
		j = i - 1; // Posicao anterior ao elemento a ser movido
		// Ate encontrar em elemento menor que aux ou ate a 1a posicao
		while (j >= 0 && vet[j] > aux) { 
			vet[j+1] = vet[j]; // Move elementos para a direita
			j--;
 		}
		vet[j+1] = aux; // Copia elemento para sua posicao
	}

	imprimir(vet);

	return 0;
}