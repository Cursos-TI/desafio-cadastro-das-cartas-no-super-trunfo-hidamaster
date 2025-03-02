#include <stdio.h>


#define MAX_NOME 100

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[20]; // Nome do estado completo
    char codigo[4];  // Ex: "A01", "B03"
    char nomeCidade[MAX_NOME];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para preencher a Carta 1
void preencherCarta1(Carta *carta) {
    strcpy(carta->estado, "Paraíba");
    strcpy(carta->codigo, "A01");
    strcpy(carta->nomeCidade, "João Pessoa");
    carta->populacao = 88000;
    carta->area = 1521.00;
    carta->pib = 708.00;
    carta->pontosTuristicos = 50;
}

// Função para preencher a Carta 2
void preencherCarta2(Carta *carta) {
    strcpy(carta->estado, "Rio de Janeiro");
    strcpy(carta->codigo, "B01");
    strcpy(carta->nomeCidade, "Duque de Caxias");
    carta->populacao = 56000;
    carta->area = 230.00;
    carta->pib = 102.00;
    carta->pontosTuristicos = 30;
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    Carta carta1, carta2;

    // Preencher as Cartas 1 e 2
    preencherCarta1(&carta1);
    preencherCarta2(&carta2);

    // Exibir as cartas cadastradas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}