#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;


Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}


void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na sala: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho. Você chegou ao último cômodo.\n");
            break;
        }

        printf("Escolha um caminho: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Não há caminho à esquerda.\n");
            }
        } else if (escolha == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não há caminho à direita.\n");
            }
        } else if (escolha == 's') {
            printf("Exploração encerrada.\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}


int main() {
    Sala* hall = criarSala("Hall de Entrada");
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Cozinha");

    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita = criarSala("Jardim de Inverno");

    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita = criarSala("Área de Serviço");

    printf("Bem-vindo ao Detective Quest!\nExplore a mansão e descubra pistas...\n");

    explorarSalas(hall);
    
    return 0;
}