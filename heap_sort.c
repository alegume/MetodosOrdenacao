/*
* Heapsort
* Author: Alexandre A. A. M de Abreu
*/

#include <stdio.h>

#define n(vet) (sizeof(vet) / sizeof(vet[0]))

#define TROCAR(vet, a, b) \
{ \
    int tmp = vet[a]; \
    vet[a] = vet[b]; \
    vet[b] = tmp; \
}

#define IMPRIMIR(vet, n) \
{ \
for (int i = 0; i < n; i++) printf("%d ", vet[i]); \
printf("\n"); \
}

int tamanho_heap;

void max_heapify(int vet[], int i) {
    int esquerda = i * 2;
    int direita = esquerda + 1;
    int maior = i;

    if (esquerda <= tamanho_heap && vet[esquerda] > vet[maior])
        maior = esquerda;

    if (direita <= tamanho_heap && vet[direita] > vet[maior])
        maior = direita;

    if (maior != i) { // Se violou condicao max heap
        TROCAR(vet, i, maior);
        max_heapify(vet, maior); // Chama recursivamente para a subarvore de 'maior'
    }
}

void build_max_heap(int vet[], int n) {
    tamanho_heap = n - 1; // Reduz o tamanho da max heap no arranjo

    for (int i = tamanho_heap / 2; i >= 0; i--) // nos a partir de (n / 2 + 1) sao folhas
        max_heapify(vet, i); // max_heapify eh chamado bottom-up

}

void heap_sort(int vet[], int n) {
    tamanho_heap = n - 1;
    // Passo 1
    build_max_heap(vet, n);
    // Passo 2
    for (int i = tamanho_heap; i > 0; i--) {
        IMPRIMIR(vet, n);
        TROCAR(vet, 0, i); // Troca elemento maximo e ultimo elemento na heap 
        tamanho_heap--; // Decrementa a o n de max heap
        max_heapify(vet, 0); // corrigir possivel violacao na raiz da heap
    }
}

int main() {
    int vet[] = {9, 3, 6, 7, 4, 1};
    int n = n(vet);

    IMPRIMIR(vet, n);
    heap_sort(vet, n);
    IMPRIMIR(vet, n);

    return 0;
} 
