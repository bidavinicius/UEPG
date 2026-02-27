#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarArquivoBinario(){
    FILE *arquivo;
    arquivo = fopen("exemplo.bin", "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir.\n");
        return;
    }

    fclose(arquivo);
}

void escreverArquivoTexto(){
    FILE *arquivo;
    char string[100];

    arquivo = fopen("arquivo.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0;  

    for(int i=0; i<strlen(string); i++){
        fputc(string[i], arquivo);
    }

    fclose(arquivo);
}

void lerCinquentaCaracteres(){
    FILE *arquivo;
    char c;

    arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for(int i=0; i<50; i++){
        c = fgetc(arquivo);
        if (c == EOF) break; 
        printf("%c", c);
    }

    fclose(arquivo);
}

void lerArquivoCompleto(){
    FILE *arquivo;
    char c;

    arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while((c = fgetc(arquivo)) != EOF){
        printf("%c", c);
    }
    printf("\n");

    fclose(arquivo);
}

int main(){
    criarArquivoBinario();

    escreverArquivoTexto();

    lerCinquentaCaracteres();

    lerArquivoCompleto();

    system("pause");

    return 0;
}
