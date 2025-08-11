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
    float super_poder1, super_poder2;
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
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontotur1 + pib_pc1 + (1.0f/dens_pop1);
    pontos1 = 0;

    pib_pc2 = (pib2*1000000000)/populacao2;
    dens_pop2 = populacao2/area2;
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontotur2 + pib_pc2 + (1.0f/dens_pop2);
    pontos2 = 0;




// Exibição carta 1
    printf("\n\n______________________________________________________\n");
    printf("\n>> Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %c%s\n", estado1, codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km2\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontotur1);
    printf("Densidade Populacional: %.2f hab/km2\n",dens_pop1);
    printf("PIB per Capita: %.2f reais\n",pib_pc1);


// Exibição carta 2
    printf("\n>> Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %c%s\n", estado2, codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontotur2);
    printf("Densidade Populacional: %.2f hab/km2\n",dens_pop2);
    printf("PIB per Capita: %.2f reais\n",pib_pc2);




// Resultados
    printf("\n\n______________________________________________________\n");
    printf("\n>> Comparação de Cartas:\n");

    printf("População: %d x %d | ", populacao1, populacao2);
    if (populacao1 > populacao2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if (populacao1 < populacao2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("Área: %.2f x %.2f | ", area1, area2);
    if (area1 > area2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if (area1 < area2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("PIB: %.2f x %.2f | ", pib1, pib2);
    if (pib1 > pib2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if(pib1 < pib2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("Pontos Turísticos: %d x %d | ", pontotur1, pontotur2);
    if (pontotur1 > pontotur2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if (pontotur1 < pontotur2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    }  else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("Densidade Populacional: %.2f x %.2f | ", dens_pop1, dens_pop2);
    if (dens_pop1 < dens_pop2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if(dens_pop1 > dens_pop2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("PIB per Capita: %.2f x %.2f | ", pib_pc1, pib_pc2);
    if (pib_pc1 > pib_pc2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if (pib_pc1 < pib_pc2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }


    printf("Super Poder: %.2f x %.2f | ", super_poder1, super_poder2);
    if (super_poder1 > super_poder2){
        printf("Carta 1 venceu (1)\n");
        pontos1++;
    } else if(super_poder1 < super_poder2){
        printf("Carta 2 venceu (0)\n");
        pontos2++;
    } else {
        printf("Houve um empate\n");
        pontos1++, pontos2++;;
    }

    printf("\n\n______________________________________________________\n");
    printf("\n>> Resultado Final:\n");
    printf("\nCarta 1 (%c%s) %d x %d Carta 2 (%c%s)", estado1, codigo1, pontos1, pontos2, estado2, codigo2);

    if (pontos1 > pontos2){
        printf("\n\n>> Carta 1 (%c%s) venceu!\n", estado1, codigo1);
    } else if (pontos1 < pontos2){
        printf("\n\n>> Carta 2 (%c%s) venceu!\n", estado2, codigo2);
    } else {
        printf("EMPATE!\n");
    }




return 0;
}
