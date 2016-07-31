/*
* Shellsort
* Author: Alexandre A. A. M de Abreu
*/

#include<stdio.h>

#define N 6

void imprimir(int vet[]) {
	for (int i = 0; i < N; i++)
		printf("%d - ", vet[i]);
	printf("\n");
}

int main() {
	int vet[N] = {6, 3, 9, 7, 4, 1};
	int aux, i, j, h;
	imprimir(vet);

    for (h = N; h /= 2; ) { // h decrementa pela metade
        for (i = h; i < N; i++) {
        	//imprimir(vet); // Apenas imprime para acompanhar
            aux = vet[i]; // Auxiliar para a troca
            // J 'percorre' os multiplos de h (decrescente)
            for (j = i; j >= h && aux < vet[j - h]; j -= h) { 
                vet[j] = vet[j - h]; // Desloca os elementos em posicao multipla de h
            }
            vet[j] = aux; // Faz a troca
        }
    }

	imprimir(vet);

	return 0;
}