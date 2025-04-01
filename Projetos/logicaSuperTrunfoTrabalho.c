#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];          // Sigla do estado (ex: SP, RJ)
    char codigo[5];          // Código da carta (ex: A01, B02)
    char cidade[50];         // Nome da cidade
    int populacao;           // População em habitantes
    float area;              // Área em km²
    float pib;               // PIB em milhões
    int pontos_turisticos;   // Número de pontos turísticos
    float densidade_pop;     // Densidade populacional (calculada)
    float pib_per_capita;    // PIB per capita (calculado)
} Carta;

int main() {
    // Declaração das duas cartas
    Carta carta1, carta2;

    // Dados da Carta 1 - São Paulo
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.cidade, "Sao Paulo");
    carta1.populacao = 12300000;      // 12.3 milhões
    carta1.area = 1521.11;            // em km²
    carta1.pib = 699.28;              // em bilhões
    carta1.pontos_turisticos = 15;

    // Dados da Carta 2 - Rio de Janeiro
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "B01");
    strcpy(carta2.cidade, "Rio de Janeiro");
    carta2.populacao = 6000000;       // 6 milhões
    carta2.area = 1200.0;             // em km²
    carta2.pib = 353.32;              // em bilhões
    carta2.pontos_turisticos = 20;

    // Cálculo da Densidade Populacional e PIB per capita para Carta 1
    carta1.densidade_pop = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / (carta1.populacao / 1000000.0); // Ajuste para milhões

    // Cálculo da Densidade Populacional e PIB per capita para Carta 2
    carta2.densidade_pop = (float)carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / (carta2.populacao / 1000000.0); // Ajuste para milhões

    // Exibição dos dados calculados
    printf("Carta 1 - %s (%s):\n", carta1.cidade, carta1.estado);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_pop);
    printf("PIB per capita: %.2f milhões/hab\n\n", carta1.pib_per_capita);

    printf("Carta 2 - %s (%s):\n", carta2.cidade, carta2.estado);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_pop);
    printf("PIB per capita: %.2f milhões/hab\n\n", carta2.pib_per_capita);

    // Comparação das cartas pelo atributo População
    printf("Comparacao de cartas (Atributo: Populacao):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Lógica de decisão para determinar a vencedora
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}