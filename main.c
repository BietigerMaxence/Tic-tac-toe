#include <stdio.h>

void display_board(char a_board[3][3]) {
    printf("---+---+---\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf("%c", a_board[i][j]);
            if (j == 2) {
                continue;
            }
            printf(" | ");
        }
        printf("\n---+---+---\n");
    }
}

char play_game(int a_case, char a_board[3][3], int a_move_number) {
    int ligne   = (a_case - 1) / 3;      // division entière
    int colonne = (a_case - 1) % 3;      // modulo

    if (a_move_number % 2 == 0) {
        a_board[ligne][colonne] = 'X';
    }else {
        a_board[ligne][colonne] = 'O';
    }
    display_board(a_board);
}

int main() {
    int play_case;
    int move_number = 0;

    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '.';
        }
    }
    display_board(board);

    while (move_number < 5) {
        printf("Sur quelle case voulez-vous jouer ? \n");
        scanf("%d", &play_case); // NOLINT(cert-err34-c)

        play_game(play_case, board, move_number);
        move_number++;
    }
}