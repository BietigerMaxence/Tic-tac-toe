#include <stdio.h>
#include <stdbool.h>

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

bool play_game(int a_case, char a_board[3][3], int a_move_number) {
    int ligne   = (a_case - 1) / 3;
    int column = (a_case - 1) % 3;

    if (a_board[ligne][column] == '.') {
        if (a_move_number % 2 == 0) {
            a_board[ligne][column] = 'X';
        }else {
            a_board[ligne][column] = 'O';
        }
        display_board(a_board);
        return true;
    } else {
        return false;
    }
}

char check_winner(char a_board[3][3]) {

    //Detect the column winner
    if (a_board[0][0] == a_board[1][1] && a_board[0][0] == a_board[2][2] && a_board[0][0] != '.') {
        return a_board[0][0];
    }

    if (a_board[0][2] == a_board[1][1] && a_board[0][2] == a_board[2][0] && a_board[0][2] != '.') {
        return a_board[0][2];
    }

    //Detect the line winner
    for (int i = 0; i < 3; i++) {
        if (a_board[i][0] == a_board[i][1] && a_board[i][1] == a_board[i][2] && a_board[i][0] != '.') {
            return a_board[i][0];
        }
        //Detect the column winner
        if (a_board[0][i] == a_board[1][i] && a_board[1][i] == a_board[2][i] && a_board[0][i] != '.') {
            return a_board[0][i];
        }
    }
    return '.';
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

    while (check_winner(board) == '.' && move_number < 9) {
        printf("On which case do you want to play ? \n");
        if (scanf("%d", &play_case) == 1) { // NOLINT(cert-err34-c)
            if (play_case > 0 && play_case < 10) {
                bool placed = play_game(play_case, board, move_number);
                if (placed) {
                    move_number++;
                }else {
                    printf("This case is already used, choose another one !\n");
                }
                continue;

            }else{
                printf("Invalid case, choose another one:\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
                continue;
            }
        }else{
            printf("Invalid number, choose another one between 1 and 9:\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }
    }

    if (move_number == 9 && check_winner(board) == '.') {
        printf("Draw, no one win !");
        return 0;
    }
    if (check_winner(board) == 'X') {
        printf("The winner is player1! (X)\n");
        return 0;
    } else {
        printf("The winner is player2! (O)\n");
        return 0;
    }
}