#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicializar tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal de tamanho 3 (linha 2, colunas B-D => [1][1] a [1][3])
    for (int j = 1; j <= 3; j++) {
        tabuleiro[1][j] = 3;
    }

    // Navio vertical de tamanho 3 (coluna H, linhas 5-7 => [4][7] a [6][7])
    for (int i = 4; i <= 6; i++) {
        tabuleiro[i][7] = 3;
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

