#include <stdio.h>

void display_board(char aBoard[3][3]) {
    printf("---+---+---");
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf("%c", aBoard[i][j]);
            if (j == 2) {
                continue;
            }
            printf(" | ");
        }
        printf("\n");
        printf("---+---+---");
        printf("\n");
    }
}



int main() {
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '.';
        }
    }
    display_board(board);
}