#include <stdio.h>
#include <string.h>

// Estrutura da Carta
typedef struct {
    char estado[20];
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int numero;
} Carta;

// Função para preencher uma carta
void preencherCarta(Carta *carta, char estado[], char codigo[], int populacao, float area, float pib, int numero) {
    strcpy(carta->estado, estado);
    strcpy(carta->codigo, codigo);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->numero = numero;
}

// Funções auxiliares para cálculo
float calcularDensidade(Carta carta) {
    return carta.populacao / carta.area;
}

float calcularPibPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

// Função para comparar um atributo e exibir o resultado
void compararAtributo(char nome[], float valor1, float valor2, Carta carta1, Carta carta2, int menorVence) {
    printf("\n=== Comparação de %s ===\n", nome);
    printf("Carta %d - %s: %.2f\n", carta1.numero, carta1.estado, valor1);
    printf("Carta %d - %s: %.2f\n", carta2.numero, carta2.estado, valor2);

    // Determina o vencedor
    if ((valor1 > valor2 && !menorVence) || (valor1 < valor2 && menorVence)) {
        printf("Resultado: Carta %d - %s venceu!\n", carta1.numero, carta1.estado);
    } else if ((valor2 > valor1 && !menorVence) || (valor2 < valor1 && menorVence)) {
        printf("Resultado: Carta %d - %s venceu!\n", carta2.numero, carta2.estado);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função principal para comparar as cartas
void compararCartas(Carta carta1, Carta carta2) {
    compararAtributo("População", carta1.populacao, carta2.populacao, carta1, carta2, 0);
    compararAtributo("Área", carta1.area, carta2.area, carta1, carta2, 0);
    compararAtributo("PIB", carta1.pib, carta2.pib, carta1, carta2, 0);
    compararAtributo("PIB per capita", calcularPibPerCapita(carta1), calcularPibPerCapita(carta2), carta1, carta2, 0);
    compararAtributo("Densidade Populacional", calcularDensidade(carta1), calcularDensidade(carta2), carta1, carta2, 1);
}

int main() {
    // Criando as cartas
    Carta carta1, carta2;
    preencherCarta(&carta1, "Paraíba", "A01", 88000, 1521.00, 708.00, 1);
    preencherCarta(&carta2, "Rio de Janeiro", "B01", 56000, 230.00, 102.00, 2);

    // Comparação entre as cartas
    compararCartas(carta1, carta2);

    return 0;
}