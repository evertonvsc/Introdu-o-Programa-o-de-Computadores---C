#include <stdio.h>

int main(){

    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[40], cidade2[40];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontotur1, pontotur2;
    float dens_pop1, dens_pop2;
    float pib_pc1, pib_pc2;
    float soma1, soma2;
    int escolha1, escolha2;
    int pontos1, pontos2;


// Leitura Carta 1
    printf("*** Referente à primeira carta, insira as seguintes informações:\n\n");

    printf("Letra referente ao estado [A-H]: ");
    scanf(" %c", &estado1);

    printf("Numeração da carta [01-04]: ");
    scanf("%s", &codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", &cidade1);

    printf("Número de habitantes da cidade: ");
    scanf("%d", &populacao1);

    printf("Área da cidade em km2: ");
    scanf("%f", &area1);

    printf("PIB da cidade (Em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Quantidade de pontos turísticos na cidade: ");
    scanf("%d", &pontotur1);


// Leitura Carta 2
    printf("\n\n*** Referente à primeira carta, insira as seguintes informações:\n\n");

    printf("Letra referente ao estado [A-H]: ");
    scanf(" %c", &estado2);

    printf("Numeração da carta [01-04]: ");
    scanf("%s", &codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", &cidade2);

    printf("Número de habitantes da cidade: ");
    scanf("%d", &populacao2);

    printf("Área da cidade em km2: ");
    scanf("%f", &area2);

    printf("PIB da cidade (Em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Quantidade de pontos turísticos na cidade: ");
    scanf("%d", &pontotur2);


// Cálculos

    dens_pop1 = populacao1/area1;
    pib_pc1 = (pib1*1000000000)/populacao1;

    pib_pc2 = (pib2*1000000000)/populacao2;
    dens_pop2 = populacao2/area2;

    soma1 = 0;
    soma2 = 0;
    pontos1 = 0;
    pontos2 = 0;



// Menu
    printf("\n\n______________________________________________________\n");
    printf("\n>> Escolha o primeiro atributo para comparação [1-6]: \n\n[1] População\n[2] Área\n[3] PIB\n[4] Qtd de pontos turísticos\n[5] Densidade Populacional\n[6] PIB Per Capita\n>> ");
    scanf("%d", &escolha1);
    printf("\n>> Escolha o segundo:\n>> ");
    scanf("%d", &escolha2);
    printf("\n");


    while((escolha1 < 1 || escolha1 > 6 || escolha2 < 1 || escolha2 > 6) || (escolha1 == escolha2)){
        printf("\n\n______________________________________________________\n");
        printf("!!!! Escolhas inválidas, Tente novamente:\n");
        printf("\n>> Escolha o primeiro atributo para comparação [1-6]: \n\n[1] População\n[2] Área\n[3] PIB\n[4] Qtd de pontos turísticos\n[5] Densidade Populacional\n[6] PIB Per Capita\n>> ");
        scanf("%d", &escolha1);
        printf("\n>> Escolha o segundo:\n>> ");
        scanf("%d", &escolha2);
        printf("\n");
    }

    int escolhas[2] = { escolha1, escolha2 };

    printf("\n\n______________________________________________________\n");

    for (int i = 0; i < 2; i++) {
        switch(escolhas[i]){
            case 1:
                soma1 += (float)populacao1;
                soma2 += (float)populacao2;
                printf("\n>> População:\n%s %d x %d %s\n", cidade1, populacao1, populacao2, cidade2);
                if (populacao1 > populacao2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if (populacao1 < populacao2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                } else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            case 2:
                soma1 += area1;
                soma2 += area2;
                printf("\n>> Área (km2):\n%s %.2f x %.2f %s\n", cidade1, area1, area2, cidade2);
                if (area1 > area2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if (area1 < area2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                } else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            case 3:
                soma1 += pib1;
                soma2 += pib2;
                printf("\n>> PIB (bilhões):\n%s %.2f x %.2f %s\n", cidade1, pib1, pib2, cidade2);
                if (pib1 > pib2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if(pib1 < pib2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                } else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            case 4:
                soma1 += (float)pontotur1;
                soma2 += (float)pontotur2;
                printf("\n>> Quantidade de Pontos Turísticos:\n%s %d x %d %s\n", cidade1, pontotur1, pontotur2, cidade2);
                if (pontotur1 > pontotur2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if (pontotur1 < pontotur2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                }  else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            case 5:
                soma1 += dens_pop1;
                soma2 += dens_pop2;
                printf("\n>> Densidade Populacional (hab/km2):\n%s %.2f x %.2f %s\n", cidade1, dens_pop1, dens_pop2, cidade2);
                if (dens_pop1 < dens_pop2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if(dens_pop1 > dens_pop2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                } else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            case 6:
                soma1 += pib_pc1;
                soma2 += pib_pc2;
                printf("\n>> PIB per Capita (PIB/hab):\n%s %.2f x %.2f %s\n", cidade1, pib_pc1, pib_pc2, cidade2);
                if (pib_pc1 > pib_pc2){
                    printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
                    pontos1++;
                } else if (pib_pc1 < pib_pc2){
                    printf("== Carta 2 (%c%s) venceu!\n", estado1, codigo1);
                    pontos2++;
                } else {
                    printf("== Houve um empate\n");
                    pontos1++;
                    pontos2++;
                }
                break;
            default:
                printf("Opção Inválida!");

        }
    }

    printf("\n>> Soma dos atributos: %s %.2f x %.2f %s\n", cidade1, soma1, soma2, cidade2);
    if (soma1 > soma2){
        printf("== Carta 1 (%c%s) venceu!\n", estado1, codigo1);
        pontos1++;
    } else if (soma1 < soma2){
        printf("== Carta 2 (%c%s) venceu!\n", estado2, codigo2);
        pontos2++;
    } else {
        printf("== Houve um empate\n");
        pontos1++;
        pontos2++;
    }

// Resultado
    printf("\n\n______________________________________________________\n");
    printf("\n>> Resultado Final: %s %d x %d %s", cidade1, pontos1, pontos2, cidade2);

    (pontos1 > pontos2) ? printf("\n>>> A carta 1 (%c%s) saiu vencedora!!!\n", estado1, codigo1) :
    (pontos1 < pontos2) ? printf("\n>>> A carta 2 (%c%s) saiu vencedora!!!\n", estado2, codigo2) :
    printf("\n>>> A comparação terminou empatada!!!\n");



return 0;
}
