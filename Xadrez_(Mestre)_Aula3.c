#include <stdio.h>

void imprime_torre(int a, int b){
    int movimento = a;

    if (b <= 0){
        return;
    }

    switch (movimento) {
        case 1: printf("Cima "); break;
        case 2: printf("Baixo "); break;
        case 3: printf("Direita "); break;
        case 4: printf("Esquerda "); break;
        default: printf("Movimento inválido");
    }
    imprime_torre(movimento, b - 1);
}

void imprime_bispo(int a, int b){
    int movimento = a;

    if (b <= 0){
        return;
    }

    switch (movimento) {
        case 1: printf("Cima Direita "); break;
        case 2: printf("Cima Esquerda "); break;
        case 3: printf("Baixo Direita "); break;
        case 4: printf("Baixo Esquerda "); break;
        default: printf("Movimento inválido");
    }
    imprime_bispo(movimento, b - 1);
}


void imprime_rainha(int a, int b){
    int movimento = a;

    if (b <= 0){
        return;
    }

    switch (movimento) {
        case 1: printf("Cima "); break;
        case 2: printf("Baixo "); break;
        case 3: printf("Direita "); break;
        case 4: printf("Esquerda "); break;
        case 5: printf("Cima Direita "); break;
        case 6: printf("Cima Esquerda "); break;
        case 7: printf("Baixo Direita "); break;
        case 8: printf("Baixo Esquerda "); break;
        default: printf("Movimento inválido");
    }
    imprime_rainha(movimento, b - 1);
}


void imprime_cavalo(int a){
    int movimento = a;
    int i,j;

    switch (movimento) {
        case 1:
            for (i = 0; i < 2; i++) { printf("Cima ");
            } for (j = 0; j < 1; j++) { printf("Direita ");}
            break;
        case 2:
            for (i = 0; i < 2; i++) { printf("Cima ");
            } for (j = 0; j < 1; j++) { printf("Esquerda ");}
            break;
        case 3:
            for (i = 0; i < 2; i++) { printf("Baixo ");
            }for (j = 0; j < 1; j++) { printf("Direita ");}
            break;
        case 4:
            for (i = 0; i < 2; i++) { printf("Baixo ");
            }for (j = 0; j < 1; j++) { printf("Esquerda ");}
            break;
        case 5:
            for (i = 0; i < 1; i++) { printf("Cima ");
            } for (j = 0; j < 2; j++) { printf("Direita ");}
            break;
        case 6:
            for (i = 0; i < 1; i++) { printf("Cima ");
            } for (j = 0; j < 2; j++) { printf("Esquerda ");}
            break;
        case 7:
            for (i = 0; i < 1; i++) { printf("Baixo ");
            } for (j = 0; j < 2; j++) { printf("Direita ");}
            break;
        case 8:
            for (i = 0; i < 1; i++) { printf("Baixo ");
            } for (j = 0; j < 2; j++) { printf("Esquerda ");}
            break;
        default: printf("Movimento inválido");
    }

}



int main() {
    int pos_linha, pos_coluna;
    int nova_linha, nova_coluna;
    int escolha_peca;
    char *pecas[] = {"Torre", "Bispo", "Rainha", "Cavalo"};
    int movimento;
    int quantidade;

// Escolha da peça
    do {
        printf("\n=======================================================\n");
        printf("Escolha a sua peça: \n");
        printf("[1] Torre\n");
        printf("[2] Bispo\n");
        printf("[3] Rainha\n");
        printf("[4] Cavalo\n");
        printf(">> ");
        scanf("%d", &escolha_peca);
    } while (escolha_peca < 1 || escolha_peca > 4);

// Escolha da posição inicial
    do {
        printf("\n=======================================================\n");
        printf("Agora escolha as posições da peça %s:\n", pecas[escolha_peca - 1]);
        printf("1. Linha [1-8]: ");
        scanf("%d", &pos_linha);
        printf("1. Coluna [1-8]: ");
        scanf("%d", &pos_coluna);
    } while (pos_linha < 1 || pos_linha > 8 || pos_coluna < 1 || pos_coluna > 8);

// Imprime o tabuleiro inicial
    printf("\n=======================================================\n");
    printf("Aí está sua peça:\n\n");
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (i == pos_linha && j == pos_coluna)
                printf("X ");
            else
                printf("_ ");
        }
        printf("\n");
    }

// Movimentação das peças
    switch (escolha_peca) {
        case 1: // Torre
            do {
                printf("\nPara onde deseja movimentar a Torre?\n");
                printf("[1] Cima\n[2] Baixo\n[3] Direita\n[4] Esquerda\n>> ");
                scanf("%d", &movimento);
                printf("Quantas casas?\n>> ");
                scanf("%d", &quantidade);

                nova_linha = pos_linha;
                nova_coluna = pos_coluna;

                switch (movimento) {
                    case 1: nova_linha -= quantidade; break;
                    case 2: nova_linha += quantidade; break;
                    case 3: nova_coluna += quantidade; break;
                    case 4: nova_coluna -= quantidade; break;
                    default: nova_linha = nova_coluna = -1;
                }

                if (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8){
                    printf("!!! Movimento inválido\n");
                } else {
                    printf("\nMovimentação feita: \n");
                    imprime_torre(movimento, quantidade);
                    }

            } while (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8);
            break;

        case 2: // Bispo
            do {
                printf("\nPara onde deseja movimentar o Bispo?\n");
                printf("[1] Diagonal superior direita\n");
                printf("[2] Diagonal superior esquerda\n");
                printf("[3] Diagonal inferior direita\n");
                printf("[4] Diagonal inferior esquerda\n>> ");
                scanf("%d", &movimento);
                printf("Quantas casas?\n>> ");
                scanf("%d", &quantidade);

                nova_linha = pos_linha;
                nova_coluna = pos_coluna;

                switch (movimento) {
                    case 1: nova_linha -= quantidade; nova_coluna += quantidade; break;
                    case 2: nova_linha -= quantidade; nova_coluna -= quantidade; break;
                    case 3: nova_linha += quantidade; nova_coluna += quantidade; break;
                    case 4: nova_linha += quantidade; nova_coluna -= quantidade; break;
                    default: nova_linha = nova_coluna = -1;
                }

                if (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8){
                    printf("!!! Movimento inválido\n");
                } else {
                    printf("\nMovimentação feita: \n");
                    imprime_bispo(movimento, quantidade);
                }

            } while (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8);
            break;



        case 3: // Rainha
            do {
                printf("\nPara onde deseja movimentar a Rainha?\n");
                printf("[1] Cima\n[2] Baixo\n[3] Direita\n[4] Esquerda\n");
                printf("[5] Diagonal superior direita\n[6] Diagonal superior esquerda\n");
                printf("[7] Diagonal inferior direita\n[8] Diagonal inferior esquerda\n>> ");
                scanf("%d", &movimento);
                printf("Quantas casas?\n>> ");
                scanf("%d", &quantidade);

                nova_linha = pos_linha;
                nova_coluna = pos_coluna;

                switch (movimento) {
                    case 1: nova_linha -= quantidade; break;
                    case 2: nova_linha += quantidade; break;
                    case 3: nova_coluna += quantidade; break;
                    case 4: nova_coluna -= quantidade; break;
                    case 5: nova_linha -= quantidade; nova_coluna += quantidade; break;
                    case 6: nova_linha -= quantidade; nova_coluna -= quantidade; break;
                    case 7: nova_linha += quantidade; nova_coluna += quantidade; break;
                    case 8: nova_linha += quantidade; nova_coluna -= quantidade; break;
                    default: nova_linha = nova_coluna = -1;
                }

                if (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8){
                    printf("!!! Movimento inválido\n");
                } else {
                    printf("\nMovimentação feita: \n");
                    imprime_rainha(movimento, quantidade);
                }


            } while (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8);
            break;

        case 4: // Cavalo
            do {
                printf("\nPara onde deseja movimentar o Cavalo?\n");
                printf("[1] 2 cima + 1 direita\n[2] 2 cima + 1 esquerda\n");
                printf("[3] 2 baixo + 1 direita\n[4] 2 baixo + 1 esquerda\n");
                printf("[5] 2 direita + 1 cima\n[6] 2 esquerda + 1 cima\n");
                printf("[7] 2 direita + 1 baixo\n[8] 2 esquerda + 1 baixo\n>> ");
                scanf("%d", &movimento);

                nova_linha = pos_linha;
                nova_coluna = pos_coluna;

                switch (movimento) {
                    case 1: nova_linha -= 2; nova_coluna += 1; break;
                    case 2: nova_linha -= 2; nova_coluna -= 1; break;
                    case 3: nova_linha += 2; nova_coluna += 1; break;
                    case 4: nova_linha += 2; nova_coluna -= 1; break;
                    case 5: nova_linha -= 1; nova_coluna += 2; break;
                    case 6: nova_linha -= 1; nova_coluna -= 2; break;
                    case 7: nova_linha += 1; nova_coluna += 2; break;
                    case 8: nova_linha += 1; nova_coluna -= 2; break;
                    default: nova_linha = nova_coluna = -1;
                }

                if (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8){
                    printf("!!! Movimento inválido\n");
                } else {
                    printf("\nMovimentação feita: \n");
                    imprime_cavalo(movimento);
                }

            } while (nova_linha < 1 || nova_linha > 8 || nova_coluna < 1 || nova_coluna > 8);
            break;
    }

// Nova posição da peça
    pos_linha = nova_linha;
    pos_coluna = nova_coluna;

// Imprime tabuleiro final
    printf("\n=======================================================\n");
    printf("Nova posição da peça %s:\n\n", pecas[escolha_peca - 1]);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (i == pos_linha && j == pos_coluna)
                printf("X ");
            else
                printf("_ ");
        }
        printf("\n");
    }

    return 0;
}
