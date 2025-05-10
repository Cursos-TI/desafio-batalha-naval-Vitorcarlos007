#include <stdio.h>

#define TAM_TABULEIRO 10    // Tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3         // Tamanho fixo dos navios
#define VALOR_AGUA 0        // Valor que representa água
#define VALOR_NAVIO 3       // Valor que representa parte do navio

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Coordenadas iniciais do navio vertical
    int linha_v = 5;
    int coluna_v = 7;

    // Verificação de limite e sobreposição - Navio horizontal
    if (coluna_h + TAM_NAVIO <= TAM_TABULEIRO) {
        int pode_posicionar = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != VALOR_AGUA) {
                pode_posicionar = 0;
                break;
            }
        }

        if (pode_posicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = VALOR_NAVIO;
            }
        }
    }

    // Verificação de limite e sobreposição - Navio vertical
    if (linha_v + TAM_NAVIO <= TAM_TABULEIRO) {
        int pode_posicionar = 1;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != VALOR_AGUA) {
                pode_posicionar = 0;
                break;
            }
        }

        if (pode_posicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = VALOR_NAVIO;
            }
        }
    }

    // Impressão do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
