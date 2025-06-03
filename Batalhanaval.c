#include <stdio.h>

#define LIN_CONE 5
#define COL_CONE 5

#define LIN_CRUZ 2
#define COL_CRUZ 7

#define LIN_OCTA 0   // Linha 1 (índice 0)
#define COL_OCTA 2

int main() {
    int tabuleiro[10][10] = {0};  // Inicializa tudo com zero (água)

    // === Navios (3) ===
    for (int col = 2; col <= 4; col++) {
        tabuleiro[0][col] = 3;
    }
    for (int lin = 4; lin <= 6; lin++) {
        tabuleiro[lin][7] = 3;
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
        tabuleiro[i][9 - i] = 3;
    }

    // === Cone (1) === - sobrepõe qualquer coisa que esteja lá
    for (int i = 0; i < 5; i++) {
        int linha = LIN_CONE + i;
        if (linha > 9) break;
        int inicio = COL_CONE - i;
        int fim = COL_CONE + i;
        if (inicio < 0) inicio = 0;
        if (fim > 9) fim = 9;
        for (int col = inicio; col <= fim; col++) {
            tabuleiro[linha][col] = 1;
        }
    }

    // === Cruz (2) === - sobrepõe qualquer coisa que esteja lá
    for (int offset = -2; offset <= 2; offset++) {
        int linha = LIN_CRUZ + offset;
        int col = COL_CRUZ + offset;

        if (linha >= 0 && linha <= 9) {
            tabuleiro[linha][COL_CRUZ] = 2;
        }
        if (col >= 0 && col <= 9) {
            tabuleiro[LIN_CRUZ][col] = 2;
        }
    }

    // === Octaedro (5) === - sobrepõe qualquer coisa que esteja lá
    int baseLinha = LIN_OCTA;
    int baseColuna = COL_OCTA;
    if (baseLinha + 4 < 10 && baseColuna + 4 < 10) {
        tabuleiro[baseLinha][baseColuna + 2] = 5;
        tabuleiro[baseLinha + 1][baseColuna + 1] = 5;
        tabuleiro[baseLinha + 1][baseColuna + 3] = 5;
        tabuleiro[baseLinha + 2][baseColuna] = 5;
        tabuleiro[baseLinha + 2][baseColuna + 4] = 5;
        tabuleiro[baseLinha + 3][baseColuna + 1] = 5;
        tabuleiro[baseLinha + 3][baseColuna + 3] = 5;
        tabuleiro[baseLinha + 4][baseColuna + 2] = 5;
    }

    // === Imprimir tabuleiro ===
    printf("   A B C D E F G H I J\n");
    for (int lin = 0; lin < 10; lin++) {
        printf("%2d ", lin + 1);
        for (int col = 0; col < 10; col++) {
            printf("%d ", tabuleiro[lin][col]);
        }
        printf("\n");
    }

    return 0;
}