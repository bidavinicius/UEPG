#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int matricula;  
    char nome[50];     
    float notas[3];     
};

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[150];
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exercicio1_Tamanhos(){
    printf("char:    %zu bytes\n", sizeof(char));
    printf("int:     %zu bytes\n", sizeof(int));
    printf("float:   %zu bytes\n", sizeof(float));
    printf("double:  %zu bytes\n", sizeof(double));
}

void exercicio2_TamanhoEstrutura(){
    struct Aluno aluno_exemplo;

    size_t tamanho_estrutura = sizeof(struct Aluno);
    
    printf("O tamanho total em memória: %zu bytes\n\n", tamanho_estrutura);

    printf("Detalhamento do tamanho de cada membro:\n");
    printf("- matricula (int):    %zu bytes\n", sizeof(aluno_exemplo.matricula));
    printf("- nome (char[50]):    %zu bytes\n", sizeof(aluno_exemplo.nome));
    printf("- notas (float[3]):   %zu bytes\n", sizeof(aluno_exemplo.notas));
    printf("----------------------------------------\n");
}

struct Cadastro* alocaECadastra(int n) {
    struct Cadastro *vetor = (struct Cadastro*) malloc(n * sizeof(struct Cadastro));

    if (vetor == NULL) {
        return NULL;
    }

    limparBuffer();

    for (int i = 0; i < n; i++) {
        printf("\n--- Preenchendo dados do Cadastro %d ---\n", i + 1);

        printf("Digite o nome: ");
        fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = 0;

        printf("Digite a idade: ");
        scanf("%d", &vetor[i].idade);
        limparBuffer();

        printf("Digite o endereco: ");
        fgets(vetor[i].endereco, sizeof(vetor[i].endereco), stdin);
        vetor[i].endereco[strcspn(vetor[i].endereco, "\n")] = 0;
    }

    return vetor;
}

void exercicio3_GerenciarCadastros(){
    int n;
    printf("Quantas pessoas voce deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) return;

    struct Cadastro *cadastros = alocaECadastra(n);
    if (cadastros == NULL) return;

    for (int i = 0; i < n; i++) {
        printf("\n[%d] %s, %d anos. End: %s\n", i + 1, cadastros[i].nome, cadastros[i].idade, cadastros[i].endereco);
    }

    free(cadastros);
}

void exercicio4_VetorDinamico(){
    int tamanho, *vetor; 

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) return;

    vetor = (int*) malloc(tamanho * sizeof(int));

    if (vetor == NULL) return;

    printf("\nDigite os %d elementos do vetor\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vetor[i]); 
    }

    printf("\Conteudo: [\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");

    free(vetor);
}

void exercicio5_VetorValidado(){
    int n, *vetor;

    do { 
        printf("Digite o tamanho do vetor (um valor inteiro positivo): ");
        scanf("%d", &n);
    } while (n <= 0);

    vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) return;

    for (int i = 0; i < n; i++) {
        do {
            printf("Digite o valor para a posicao [%d]: ", i);
            scanf("%d", &vetor[i]);

            if (vetor[i] < 2) {
                printf("O numero deve ser maior ou igual a 2.\n");
            }
        } while (vetor[i] < 2);
    }

    printf("\nVetor: [\n");
    for (int i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("]\n");

    free(vetor);
}


int main(){
    exercicio1_Tamanhos();
    printf("\n----------------------------------------\n");

    exercicio2_TamanhoEstrutura();
    printf("\n----------------------------------------\n");

    exercicio3_GerenciarCadastros();
    printf("\n----------------------------------------\n");

    exercicio4_VetorDinamico();
    printf("\n----------------------------------------\n");

    exercicio5_VetorValidado();

    return 0;
}