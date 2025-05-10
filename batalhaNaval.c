#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para verificar se é possível posicionar um navio sem sair dos limites ou sobrepor
int pode_posicionar(int tabuleiro[TAM][TAM], int linhas[], int colunas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int l = linhas[i];
        int c = colunas[i];
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != VALOR_AGUA) {
            return 0; // inválido
        }
    }
    return 1; // válido
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linhas[], int colunas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhas[i]][colunas[i]] = VALOR_NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Navio 1 - Horizontal (linha 2, colunas 1,2,3)
    int linha1[] = {2, 2, 2};
    int coluna1[] = {1, 2, 3};

    // Navio 2 - Vertical (coluna 6, linhas 5,6,7)
    int linha2[] = {5, 6, 7};
    int coluna2[] = {6, 6, 6};

    // Navio 3 - Diagonal principal (3,3 → 5,5)
    int linha3[] = {3, 4, 5};
    int coluna3[] = {3, 4, 5};

    // Navio 4 - Diagonal secundária (0,9 → 2,7)
    int linha4[] = {0, 1, 2};
    int coluna4[] = {9, 8, 7};

    // Posicionar os navios se não houver sobreposição ou limite
    if (pode_posicionar(tabuleiro, linha1, coluna1, NAVIO)) {
        posicionar_navio(tabuleiro, linha1, coluna1, NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha2, coluna2, NAVIO)) {
        posicionar_navio(tabuleiro, linha2, coluna2, NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha3, coluna3, NAVIO)) {
        posicionar_navio(tabuleiro, linha3, coluna3, NAVIO);
    }

    if (pode_posicionar(tabuleiro, linha4, coluna4, NAVIO)) {
        posicionar_navio(tabuleiro, linha4, coluna4, NAVIO);
    }

    // Exibe o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
