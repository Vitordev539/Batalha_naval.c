#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicializar tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal de tamanho 3 (linha 1, colunas 1-3 => [0][0] a [0][2])
    for (int j = 2; j <= 4; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio vertical de tamanho 3 (coluna H, linhas 5-7 => [4][7] a [6][7])
    for (int i = 4; i <= 6; i++) {
        tabuleiro[i][7] = 3;
    }
    // Navio diagonal principal (de [0][0] a [2][2])
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal secundária (de [0][9] a [2][7])
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }
    

    // Imprimir cabeçalho das colunas (A-J)
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Imprimir linhas numeradas de 1 a 10
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);  // Agora imprime sempre 0 ou 3
        }
        printf("\n");
    }

    return 0;
}

