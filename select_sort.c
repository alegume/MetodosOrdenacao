/*
* Selection sort
* Author: Alexandre A. A. M de Abreu
*/

#include<stdio.h>

#define N 15

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
	int vet[N], min, aux;
	inicializar(&vet[0]);
	imprimir(vet);

	for (int i = 0; i < N - 1; i++) { // O ultimo elemento ja estara em sua posicao
		min = i; // posicao para trocar o menor elemento da SUBlista 
		for (int j = i + 1; j < N; j++) { // Verifica o menor elemento na sublista [j..N]
			if (vet[j] < vet[min])
				min = j; // Atualiza posicao do menor
		}
		aux = vet[min]; // Auxiliar armazena menor valor da sublista
		vet[min] = vet[i]; // Elemento na posicao do menor vai para a posicao do menor
		vet[i] = aux; // Menor eh transferido para sua posicao
	}

	imprimir(vet);

	return 0;
}