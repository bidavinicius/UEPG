#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* encontrarSubString(const char *str, const char *str2) {
    if (str == NULL || str2 == NULL) return NULL;

    const char *p1 = str;
    const char *p2 = str2;

    while (*p1 != '\0') {
        const char *inicio = p1;
        p2 = str2;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') return inicio; 
        p1 = inicio + 1; 
    }
    return NULL; 
}

void preencherVetor(int *vet, int tam, int valor) {
    int *fim = vet + tam;
    for (int *ptr = vet; ptr < fim; ptr++) {
        *ptr = valor;
    }
}

void imprimirVetor(int *vet, int tam) {
    printf("[ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(vet + i));
    }
    printf("]\n");
}

void multiplosPonteiros(int valor) {
    int *b = &valor; 
    int **c = &b; 
    int ***d = &c; 

    printf("Valor original: %d\n", valor);
    printf("Dobro (*b): %d\n", (*b) * 2);
    printf("Triplo (**c): %d\n", (**c) * 3);
    printf("Quadruplo (***d): %d\n", (***d) * 4);
}

void imprimirEnderecosMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Endereco [%d][%d]: %p\n", i, j, (void*)&matriz[i][j]);
        }
    }
}

void imprimirEnderecosPares(int *ptr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (*(ptr + i) % 2 == 0) {
            printf("Valor PAR %d encontrado no endereco: %p\n", *(ptr + i), (void*)(ptr + i));
        }
    }
}

void demonstrarPonteiros() {
    printf("--- 1. Busca de Substring ---\n");
    const char *texto = "O rato roeu a roupa do rei de Roma.";
    const char *busca = "roupa";
    if (encontrarSubString(texto, busca)) {
        printf("Encontrado!\n");
    }

    printf("\n--- 2. Preenchimento de Vetor por Endereco ---\n");
    int vetor[5];
    preencherVetor(vetor, 5, 7);
    imprimirVetor(vetor, 5);

    printf("\n--- 3. Multiplos Niveis de Ponteiros ---\n");
    multiplosPonteiros(10);

    printf("\n--- 4. Enderecos de uma Matriz 3x3 ---\n");
    int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    imprimirEnderecosMatriz(matriz);

    printf("\n--- 5. Enderecos de Valores Pares no Vetor ---\n");
    int numeros[] = {11, 22, 33, 44, 55};
    imprimirEnderecosPares(numeros, 5);
    printf("--------------------------------------\n");
}

int main() {
    demonstrarPonteiros();
    return 0;
}