#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void inicializaTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void imprimeTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Exemplo: habilidade em cruz
void habilidadeCruz(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < TAM)
            tabuleiro[x + i][y] = 5;
        if (y + i >= 0 && y + i < TAM)
            tabuleiro[x][y + i] = 5;
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializaTabuleiro(tabuleiro);

    // Posiciona um navio (exemplo)
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[4][6] = 3;

    // Ativa habilidade
    habilidadeCruz(tabuleiro, 4, 5);

    // Mostra o tabuleiro
    imprimeTabuleiro(tabuleiro);

    return 0;
}
