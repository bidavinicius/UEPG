#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    char nome[100];
    data nascimento;
} pessoa;

typedef struct {
    char nome[50];
    int idade;
    float altura;
} atleta;

typedef struct {
    int codigo;
    char titulo[100];
    char autor[50];
    char area[50];
    int ano;
    char editora[50];
} livro;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exercicio1_CompararIdades(){
    pessoa pessoas[6];
    int maisvelha = 0, maisnova = 0;

    for (int i = 0; i < 6; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %[^\n]", pessoas[i].nome);

        printf("Digite a data de nascimento (DD MM AAAA): ");
        scanf("%d %d %d", &pessoas[i].nascimento.dia, &pessoas[i].nascimento.mes, &pessoas[i].nascimento.ano);
    }

    for (int i =1; i < 6; i++) {
        long total_dias_i = pessoas[i].nascimento.ano * 365 + pessoas[i].nascimento.mes * 30 + pessoas[i].nascimento.dia;
        long total_dias_maisvelha = pessoas[maisvelha].nascimento.ano * 365 + pessoas[maisvelha].nascimento.mes * 30 + pessoas[maisvelha].nascimento.dia;
        long total_dias_maisnova = pessoas[maisnova].nascimento.ano * 365 + pessoas[maisnova].nascimento.mes * 30 + pessoas[maisnova].nascimento.dia;

        if (total_dias_i < total_dias_maisvelha) {
            maisvelha = i;
        }
        if (total_dias_i > total_dias_maisnova) {
            maisnova = i;
    }
}

    printf("\nMais velha: %s\n", pessoas[maisvelha].nome);
    printf("Mais nova: %s\n", pessoas[maisnova].nome);
}

void exercicio2_EstatisticasAtletas(){
    atleta p[6];
    limparBuffer();

    for(int i = 0; i < 6; i++){
        printf("Atleta %d:\n", i+1);
        printf("Digite o nome: ");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = 0;

        printf("Digite a idade: ");
        scanf("%d", &p[i].idade);

        printf("Digite a altura: ");
        scanf("%f", &p[i].altura);
        limparBuffer();
    }

    int maisVelho = p[0].idade;
    float maisAlto = p[0].altura;

    for(int i = 1; i < 6; i++){
        if(p[i].idade > maisVelho){
            maisVelho = p[i].idade;
        }
        if(p[i].altura > maisAlto){
            maisAlto = p[i].altura;
        }
    }

    printf("\nAtleta mais velho: %d anos\n", maisVelho);
    printf("Atleta mais alto: %.2f metros\n", maisAlto);
}

void exercicio3_OrdenarAtletas(){
    atleta p[6];
    limparBuffer();

    for(int i = 0; i < 6; i++){
        printf("Atleta %d:\n", i+1);
        printf("Digite o nome: ");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = 0;

        printf("Digite a idade: ");
        scanf("%d", &p[i].idade);

        printf("Digite a altura: ");
        scanf("%f", &p[i].altura);
        limparBuffer();
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            if(p[j].idade > p[j+1].idade){
                atleta temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("\nAtletas por idade:\n");
    for(int i = 0; i < 6; i++){
        printf("%s - %d anos - %.2f metros\n", p[i].nome, p[i].idade, p[i].altura);
    }
}

void exercicio4_DiferencaDatas(){
    data d1, d2;
    printf("Digite a data 1 (DD MM AAAA): ");
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);

    printf("Digite a data 2 (DD MM AAAA): ");
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);

    long total_dias_d1 = d1.ano * 365 + d1.mes * 30 + d1.dia;
    long total_dias_d2 = d2.ano * 365 + d2.mes * 30 + d2.dia;

    long diferenca = labs(total_dias_d1 - total_dias_d2);
    printf("\nDiferenca entre as datas: %ld dias\n", diferenca);
}

void exercicio5_CadastroLivros(){
    livro livros[20];
    int total = 0, opcao;

    do {
        printf("\n1. Cadastrar\n2. Listar\n3. Pesquisar\n4. Ordenar\n5. Sair\nOpcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                if (total < 20) {
                    printf("Codigo: "); scanf("%d", &livros[total].codigo);
                    limparBuffer();
                    printf("Titulo: "); fgets(livros[total].titulo, 100, stdin);
                    printf("Autor: "); fgets(livros[total].autor, 100, stdin);
                    printf("Ano: "); scanf("%d", &livros[total].ano);
                    total++;
                }
                break;
            case 2:
                for (int i = 0; i < total; i++) printf("%d - %s (%d)\n", livros[i].codigo, livros[i].titulo, livros[i].ano);
                break;
            case 3: {
                int cod;
                printf("Codigo busca: "); scanf("%d", &cod);
                for (int i = 0; i < total; i++) {
                    if (livros[i].codigo == cod) printf("Encontrado: %s\n", livros[i].titulo);
                }
                break;
            }
            case 4:
                for (int i = 0; i < total - 1; i++) {
                    for (int j = 0; j < total - i - 1; j++) {
                        if (livros[j].ano > livros[j + 1].ano) {
                            livro temp = livros[j];
                            livros[j] = livros[j + 1];
                            livros[j + 1] = temp;
                        }
                    }
                }
                printf("Ordenado\n");
                break;
        }
    } while (opcao != 5);
}   

int main(){

    exercicio1_AnalisePessoas();
    exercicio2_EstatisticasAtletas();
    exercicio3_OrdenarAtletas();
    exercicio4_DiferencaDatas();
    exercicio5_CadastroLivros();

    return 0;
}
