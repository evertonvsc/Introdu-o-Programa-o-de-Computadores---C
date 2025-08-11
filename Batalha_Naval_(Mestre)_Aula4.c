#include <stdio.h>

void divisor(){
    printf("\n==========================================\n");
}


int main()
{

    /*LEGENDA: '~' = Água
               'N' = Navio
               'O' = Área de água atingida pelo ataque
               'X' = Navio atingido pelo ataque

    */

    char tabuleiro[10][10];
    char novo_tabuleiro[10][10];
    int posicao;
    int linha, coluna;
    int ataque;
    int lin_atq, col_atq;
    char cone[5][5] = {{'~', '~', 'O', '~', '~'}, {'~', '~', 'O', '~', '~'}, {'~', 'O', 'O', 'O', '~'}, {'~', 'O', 'O', 'O', '~'}, {'O', 'O', 'O', 'O', 'O'}};
    char cruz[5][5] = {{'~', '~', 'O', '~', '~'}, {'~', '~', 'O', '~', '~'}, {'O', 'O', 'O', 'O', 'O'}, {'~', '~', 'O', '~', '~'}, {'~', '~', 'O', '~', '~'}};
    char octaedro[5][5] = {{'~', '~', 'O', '~', '~'}, {'~', 'O', 'O', 'O', '~'}, {'O', 'O', 'O', 'O', 'O'}, {'~', 'O', 'O', 'O', '~'}, {'~', '~', 'O', '~', '~'}};

// Criação do tabuleiro inicial

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabuleiro[i][j] = '~';
            novo_tabuleiro[i][j] = tabuleiro[i][j];
        }
    }

    printf("   "); // Espaço canto superior esquerdo
    for (int i = 0; i<10; i++)
        printf(" %d  ", i);
    printf("\n");

// Impressão do tabuleiro inicial

    for(int i = 0; i<10; i++) {
        printf("%d ", i);
        for(int j = 0; j < 10; j++) {
            printf(" ");
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }

// Menu de escolha para o posicionamento de 3 navios (1,3)

    for(int i=0; i<3; i++){
        do{
            divisor();
            printf("\n>> NAVIO %i: \n", i+1);
            printf("\nEscolha a orientação: \n\n");
            printf("[1] Horizontal\n[2] Vertical\n[3] Inclinado para direita[/]\n[4] Inclinado para esquerda [\\]\n\n>> ");
            scanf("%d", &posicao);

            if(posicao < 1 || posicao > 4){
                printf("\n!!! Valores inválidos...\n");
            } else {
                switch(posicao){
                    case 1:
                        do {
                            divisor();
                            printf("\nInsira agora as coordenadas:\n\n> Linha [0-9]: ");
                            scanf("%d", &linha);
                            printf("> Coluna [1-8]: ");
                            scanf("%d", &coluna);
                            if((linha < 0 || linha  > 9) || (coluna < 1 || coluna > 8)){
                                printf("\n!!! Posições inválidas...\n");
                            } else {
                                if(novo_tabuleiro[linha][coluna-1] == 'N' || novo_tabuleiro[linha][coluna] == 'N' || novo_tabuleiro[linha][coluna+1] == 'N'){
                                    printf("\n!!! Essa posição já está ocupada, tente novamente...\n");
                                    linha = -1;
                                } else{
                                    novo_tabuleiro[linha][coluna-1] = 'N';
                                    novo_tabuleiro[linha][coluna] = 'N';
                                    novo_tabuleiro[linha][coluna+1] = 'N';
                                }
                            }
                        } while((linha < 0 || linha  > 9) || (coluna < 1 || coluna > 8));
                        break;


                    case 2:
                        do {
                            divisor();
                            printf("\nInsira agora as coordenadas:\n\n> Linha [1-8]: ");
                            scanf("%d", &linha);
                            printf("> Coluna [0-9]: ");
                            scanf("%d", &coluna);
                            if((linha < 1 || linha  > 8) || (coluna < 0 || coluna > 9)){
                                printf("\n!!! Posições inválidas...\n");
                            } else {
                                if(novo_tabuleiro[linha-1][coluna] == 'N' || novo_tabuleiro[linha][coluna] == 'N' || novo_tabuleiro[linha+1][coluna] == 'N'){
                                    printf("\n!!! Essa posição já está ocupada, tente novamente...\n");
                                    linha = -1;
                                } else{
                                    novo_tabuleiro[linha-1][coluna] = 'N';
                                    novo_tabuleiro[linha][coluna] = 'N';
                                    novo_tabuleiro[linha+1][coluna] = 'N';
                                }
                            }
                        } while((linha < 1 || linha  > 8) || (coluna < 0 || coluna > 9));
                        break;


                    case 3:
                        do {
                            divisor();
                            printf("\nInsira agora as coordenadas:\n\n> Linha [1-8]: ");
                            scanf("%d", &linha);
                            printf("> Coluna [1-8]: ");
                            scanf("%d", &coluna);
                            if((linha < 1 || linha  > 8) || (coluna < 1 || coluna > 8)){
                                printf("\n!!! Posições inválidas...\n");
                            } else {
                                if(novo_tabuleiro[linha-1][coluna+1] == 'N' || novo_tabuleiro[linha][coluna] == 'N' || novo_tabuleiro[linha+1][coluna-1] == 'N'){
                                    printf("\n!!! Essa posição já está ocupada, tente novamente...\n");
                                    linha = -1;
                                } else{
                                    novo_tabuleiro[linha-1][coluna+1] = 'N';
                                    novo_tabuleiro[linha][coluna] = 'N';
                                    novo_tabuleiro[linha+1][coluna-1] = 'N';
                                }
                            }
                        } while((linha < 1 || linha  > 8) || (coluna < 1 || coluna > 8));
                        break;


                    case 4:
                        do {
                            divisor();
                            printf("\nInsira agora as coordenadas:\n\n> Linha [1-8]: ");
                            scanf("%d", &linha);
                            printf("> Coluna [1-8]: ");
                            scanf("%d", &coluna);
                            if((linha < 1 || linha  > 8) || (coluna < 1 || coluna > 8)){
                                printf("\n!!! Posições inválidas...\n");
                            } else {
                                if(novo_tabuleiro[linha-1][coluna-1] == 'N' || novo_tabuleiro[linha][coluna] == 'N' || novo_tabuleiro[linha+1][coluna+1] == 'N'){
                                    printf("\n!!! Essa posição já está ocupada, tente novamente...\n");
                                    linha = -1;
                                } else{
                                    novo_tabuleiro[linha-1][coluna-1] = 'N';
                                    novo_tabuleiro[linha][coluna] = 'N';
                                    novo_tabuleiro[linha+1][coluna+1] = 'N';
                                }
                            }
                        } while((linha < 1 || linha  > 8) || (coluna < 1 || coluna > 8));
                        break;



                    }
                }

            } while(posicao < 1 || posicao > 4);

    }

    divisor();


// Impressão do tabuleiro com os navios

    printf("   ");
    for (int i = 0; i<10; i++)
        printf(" %d  ", i);
    printf("\n");


    for(int i = 0; i<10; i++) {
        printf("%d ", i);
        for(int j = 0; j < 10; j++) {
            printf(" ");
            printf(" %c ", novo_tabuleiro[i][j]);
        }
        printf("\n\n");
    }



// Menu de escolha dos ataques

    do {
        divisor();
        printf("Qual ataque deseja utilizar?\n\n");
        printf("[1] Cone\n[2] Cruz\n[3] Octaedro\n\n>> ");
        scanf("%d", &ataque);

        if(ataque < 1 || ataque > 3){
            printf("\n!!! Opção Inválida, tente novamente ...\n");
        }

    } while(ataque < 1 || ataque > 3);

    do {
        divisor();
        printf("Agora insira as coordenadas centrais do ataque:\n\n");
        printf("> Linha [2-7]: ");
        scanf("%d", &lin_atq);
        printf("> Coluna [2-7]: ");
        scanf("%d", &col_atq);

        if((lin_atq < 2 || lin_atq > 7) || (col_atq < 2 || col_atq > 7)){
            printf("\n!!! Opção Inválida, tente novamente ...\n");
        }

        } while((lin_atq < 2 || lin_atq > 7) || (col_atq < 2 || col_atq > 7));


        switch(ataque){
            case 1:
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        if (cone[i][j] == 'O'){
                            if(novo_tabuleiro[i+lin_atq-2][j+col_atq-2] == '~'){
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = cone[i][j];
                            } else{
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = 'X';
                            }
                        }


                    }
                }
                break;

            case 2:
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        if (cruz[i][j] == 'O'){
                            if(novo_tabuleiro[i+lin_atq-2][j+col_atq-2] == '~'){
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = cruz[i][j];
                            } else{
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = 'X';
                            }
                        }


                    }
                }
                break;


            case 3:
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        if (octaedro[i][j] == 'O'){
                            if(novo_tabuleiro[i+lin_atq-2][j+col_atq-2] == '~'){
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = octaedro[i][j];
                            } else{
                                novo_tabuleiro[i+lin_atq-2][j+col_atq-2] = 'X';
                            }
                        }


                    }
                }
                break;
        }


// Impressão do tabuleiro com o ataque

    divisor();
    printf("   ");
    for (int i = 0; i<10; i++)
        printf(" %d  ", i);
    printf("\n");


    for(int i = 0; i<10; i++) {
        printf("%d ", i);
        for(int j = 0; j < 10; j++) {
            printf(" ");
            printf(" %c ", novo_tabuleiro[i][j]);
        }
        printf("\n\n");
    }

  return 0;
}
