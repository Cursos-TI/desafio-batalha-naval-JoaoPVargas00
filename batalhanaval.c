#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

void tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    printf("   TABULEIRO BATALHA NAVAL\n   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int naval_battle[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = { {AGUA} };

    // Navio horizontal (linha 5, colunas G a I)
    for (int j = 6; j < 9; j++) {
        naval_battle[4][j] = NAVIO;
    }

    // Navio horizontal (linha 9, colunas C a E)
    for (int j = 2; j < 5; j++) {
        naval_battle[8][j] = NAVIO;
    }

    // Navios na diagonal
    for (int i = 0; i < 3; i++) {
        naval_battle[i][i] = NAVIO;
    }
    for (int i = 6; i < 9; i++) {
        naval_battle[i][i] = NAVIO;
    }

    // Efeito de cone (com centro em coluna 3)
    int cone_coluna = 3;
    for (int i = 0; i <= cone_coluna; i++) {
        for (int j = cone_coluna - i; j <= cone_coluna + i; j++) {
            if (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
                if (naval_battle[i][j] == NAVIO) {
                    naval_battle[i][j] = 5;
                } else {
                    naval_battle[i][j] = 1;
                }
            }
        }
    }

    // Efeito de cruz (centro em [5][5])
    int cruz = 5;
    for (int i = cruz; i < cruz + 4; i++) {
        if (i < TAMANHO_TABULEIRO) {
            if (naval_battle[i][cruz] == NAVIO) {
                naval_battle[i][cruz] = 5;
            } else {
                naval_battle[i][cruz] = 1;
            }
        }
    }

    // Linha horizontal da cruz (somente uma linha x=6)
    int x = cruz + 1;
    if (x >= 0 && x < TAMANHO_TABULEIRO) {
        for (int j = cruz - 3; j <= cruz + 3; j++) {
            if (j >= 0 && j < TAMANHO_TABULEIRO) {
                if (naval_battle[x][j] == NAVIO) {
                    naval_battle[x][j] = 5;
                } else {
                    naval_battle[x][j] = 1;
                }
            }
        }
    }

    // Efeito octaedro invertido (com base no topo do tabuleiro)
    int centro = 8;
    for (int i = centro - 6; i < centro - 3; i++) {
        if (i >= 0 && i < TAMANHO_TABULEIRO) {
            if (naval_battle[i][centro] == NAVIO) {
                naval_battle[i][centro] = 5;
            } else {
                naval_battle[i][centro] = 1;
            }
        }
    }

    int x2 = centro - 5;
    if (x2 >= 0 && x2 < TAMANHO_TABULEIRO) {
        for (int y = centro - 1; y <= centro + 1; y++) {
            if (y >= 0 && y < TAMANHO_TABULEIRO) {
                if (naval_battle[x2][y] == NAVIO) {
                    naval_battle[x2][y] = 5;
                } else {
                    naval_battle[x2][y] = 1;
                }
            }
        }
    }

    // Exibir o tabuleiro final
    tabuleiro(naval_battle);

    return 0;
}
