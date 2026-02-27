#include <stdio.h>
#include <stdlib.h>

int soma(int n) {
    if (n == 1) return 1;
    return n + soma(n - 1);
}

void crescente(int n) {
    if (n < 0) return;
    crescente(n - 1);
    printf("%d ", n);
}

void decrescente(int n) {
    if (n < 0) return;
    printf("%d ", n);
    decrescente(n - 1);
}

int soma_vetor(int vetor[], int tamanho) {
    if (tamanho == 0) return 0;
    return vetor[tamanho - 1] + soma_vetor(vetor, tamanho - 1);
}

float media_vetor(int vetor[], int tamanho) {
    if (tamanho == 0) return 0.0;
    return (float)soma_vetor(vetor, tamanho) / tamanho;
}

int potencia(int x, int y) {
    if (y == 0) return 1;
    return x * potencia(x, y - 1);
}

int multiplica(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    return a + multiplica(a, b - 1);
}

int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int inverte(int n, int invertido) {
    if (n == 0) return invertido;
    return inverte(n / 10, invertido * 10 + (n % 10));
}

int inverteNum(int n) {
    return inverte(n, 0);
}

void decParaBin(int n) {
    if (n > 0) {
        decParaBin(n / 2);
        printf("%d", n % 2);
    }
}

double serie_S(int n) {
    if (n == 1) return 2.0;
    double termo_atual = (1.0 + n * n) / n;
    return termo_atual + serie_S(n - 1);
}

int menor(int vetor[], int tamanho) {
    if (tamanho == 1) return vetor[0];
    
    int menorResto = menor(vetor, tamanho - 1);
    return (menorResto < vetor[tamanho - 1]) ? menorResto : vetor[tamanho - 1];
}

void demonstrarRecursao() {
    //Preferi fazer uma única função que mostra o funcionamento de todas as outras, para simplificar o main
    int vet[] = {10, 20, 30, 40};
    int vetSemOrdem[] = {50, 12, 100, 9, 42};

    printf("Soma (1 a 10): %d\n", soma(10));
    
    printf("Crescente (ate 8): "); crescente(8); printf("\n");
    printf("Decrescente (de 8): "); decrescente(8); printf("\n");
    
    printf("Soma do vetor: %d\n", soma_vetor(vet, 4));
    printf("Media do vetor: %.2f\n", media_vetor(vet, 4));
    
    printf("Potencia (2^10): %d\n", potencia(2, 10));
    printf("Multiplicacao (7x3): %d\n", multiplica(7, 3));
    printf("Fatorial (5!): %d\n", fatorial(5));
    printf("Fibonacci (posicao 10): %d\n", fibonacci(10));
    printf("Inversao de 12345: %d\n", inverteNum(12345));
    
    printf("Binario de 25: ");
    if (25 == 0) printf("0"); else decParaBin(25);
    printf("\n");
    
    printf("Serie S (n=3): %.2f\n", serie_S(3));
    printf("Menor valor do vetor: %d\n", menor(vetSemOrdem, 5));
}

int main() {
    demonstrarRecursao();
    return 0;
}