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
	int vet[N], aux;
	inicializar(&vet[0]);
	imprimir(vet);

	for (int i = 0; i < N - 1; i++) { // O ultimo elemento ja estara em sua posicao
		
	}

	imprimir(vet);

	return 0;
}