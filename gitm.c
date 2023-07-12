// name: Muhammed Enes Gide

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIST '@'
#define BLANK '.'
#define BLACKSTONE '#'
#define WHITESTONE 'o'

int checkWinRight(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[1] > 15) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1][stonePos[1]-1+offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinLeft(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[1] < 5) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1][stonePos[1]-1-offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinBottom(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    //printf("Stone pos: (%d, %d)\n", stonePos[0], stonePos[1]);

    if (stonePos[0] > 15) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1+offset][stonePos[1]-1];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinTop(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[0] < 5) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1-offset][stonePos[1]-1];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinTopRight(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[1] > 15 || stonePos[0] < 5) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1-offset][stonePos[1]-1+offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinTopLeft(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[0] < 5 || stonePos[1] < 5) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1-offset][stonePos[1]-1-offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinBottomRight(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[1] > 15 || stonePos[0] > 15) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1+offset][stonePos[1]-1+offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}

int checkWinBottomLeft(char rows[19][19], int stonePos[2], char playerStone) {
    int winner = 0;
    int count = 1; //since stone exists, consecutive count = 1

    if (stonePos[1] < 5 || stonePos[0] > 15) {
        return winner;
    }

    for (int offset = 1; offset < 5; offset++) {
        char c = rows[stonePos[0]-1+offset][stonePos[1]-1-offset];

        if (c == playerStone) {
            count++;
        } else {
            break;
        }

        if (count == 5) {
            winner = 1;
            break;
        }
    }

    return winner;
}


int checkWin(char player, char rows[19][19], int stonePos[2]) {
    char playerStone;
    if (player == 'B') {
        playerStone = BLACKSTONE;
    } else {
        playerStone = WHITESTONE;
    }

    if (checkWinRight(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinLeft(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinBottom(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinTop(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinTopRight(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinTopLeft(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinBottomRight(rows, stonePos, playerStone) == 1) {
        return 1;
    } else if (checkWinBottomLeft(rows, stonePos, playerStone) == 1) {
        return 1;
    }

    return 0;
}

void updateGridHole( char rows[19][19], int hole[2]) {
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            if (rows[i-1][j-1] == BLANK) {
                rows[i-1][j-1] = MIST;
            }
        }
    }

    for (int i = 1; i <= 19; i++) {
        if (abs(hole[1]-i) <= 3) {
            for (int j = 1; j <= 19; j++) {
                if (abs(hole[0]-j) <= 3) {
                    if (rows[i-1][j-1] == MIST) {
                        rows[i-1][j-1] = BLANK;
                    }
                }
            }
        }
    }
}

void moveHole(int hole[2], int stonePos[2]) {
    //stonePos[0] = row (Y), [1] = column (X)

    int x = 1 + (5*stonePos[1]*stonePos[1] + 3*stonePos[1] + 4) % 19;
    int y = 1 + (4*stonePos[0]*stonePos[0] + 2*stonePos[0] - 4) % 19;

    hole[1] = x;
    hole[0] = y;
}

void who(char player) {
    printf("%c\n", player);
}

void term() {
    exit(1);
}

void history(char moves[362][4], int movesIndex) {
    for (int i = 0; i < movesIndex; i++) {
        if (moves[i][2] == '\n' || moves[i][2] == '\0') {
            printf("%c%c", moves[i][0], moves[i][1]);
        } else {
            printf("%c%c%c", moves[i][0], moves[i][1], moves[i][2]);
            //printf("%s", moves[i]);
        }
    }
    printf("\n");
}

void printWinner(char player) {
     if (player == 'B') {
        printf("Black wins!\n");
    } else {
        printf("White wins!\n");
    }
}

void resign(char resignedPlayer) {
    if (resignedPlayer == 'B') {
        printWinner('W');
    } else {
        printWinner('B');
    }
}

/*void viewGrid(char rows[19][19]) {
    printf("\n");
    for (int i = 0; i < 19; i++) {
        if (i < 9) {
            printf("  %d", i + 1);
        } else {
            printf(" %d", i + 1);
        }

        for (int j = 0; j < 19; j++) {
            printf(" %c", rows[i][j] );
        }
        printf("\n");
    }
    printf("    A B C D E F G H I J K L M N O P Q R S\n\n");
}*/

void view(char rows[19][19], int hole[2]) {
    char xChar = hole[1] + 64; //columns ABC
    int y = hole[0]; //rows 123

    printf("%c%d,", xChar, y);

    for (int i = hole[0]+3; i >= hole[0]-3; i--) {
        int col = i;
        for (int j = hole[1]-3; j <= hole[1]+3; j++) {
            int row = j;
            if (row < 1 || row > 19 || col < 1 || col > 19) {
                printf("x");
            } else {
                printf("%c", rows[row-1][col-1]);
            }
        }
    }

    printf("\n");
}

void switchTurn(char *player) {
    if (*player == 'B') {
        *player = 'W';
    } else {
        *player = 'B';
    }
}

int updateGridSlot(char player, char rows[19][19], int colIndex, int rowIndex, int hole[2]) {
    if (colIndex < 1 || colIndex > 19 || rowIndex < 1 || rowIndex > 19) {
        printf("Invalid coordinate\n");
        return 0;
    }

    colIndex--;
    rowIndex--;

    char slot = rows[rowIndex][colIndex];
    if (slot == BLACKSTONE || slot == WHITESTONE) {
        printf("Occupied coordinate\n");
        return 0;
    }

    if (player == 'B') {
        rows[rowIndex][colIndex] = BLACKSTONE;
    } else {
        rows[rowIndex][colIndex] = WHITESTONE;
    }

    int stonePos[2] = {rowIndex+1, colIndex+1};
    //printf("Set stone pos to {%d, %d}\n", stonePos[0], stonePos[1]);

    moveHole(hole, stonePos);
    //printf("Hole moved, stone pos to {%d, %d}\n", stonePos[0], stonePos[1]);

    if (checkWin(player, rows, stonePos) == 1) {
        return 2;
    }

    return 1;
}

int place(char *player, char rows[19][19], char pos[4], char moves[362][4], int *movesIndex, int hole[2]) {
    //printf("Player %c placed stone in position %s\n", *player, pos);

    char colChar;
    char rowStr[4];

    colChar = pos[0];
    strncpy(rowStr, pos + 1, 2);

    int colIndex = colChar - 64;

    //printf("rowStr = %c%c\n", rowStr[0], rowStr[1]);
    int rowIndex = atoi(rowStr);

    int success = updateGridSlot(*player, rows, colIndex, rowIndex, hole);

    if (success > 0) {
        if (*movesIndex < 361) {
            strcpy(moves[*movesIndex], pos);
            *movesIndex = *movesIndex + 1;
        }

        if (*movesIndex == 361) {
            //viewGrid(rows);
            printf("Wow, a tie!\n");
            return 1;
        }

        if (success == 2) {
            printWinner(*player);
            return 1;
        }

        switchTurn(player);
    }

     return 0;
}

void setupGrid(char rows[19][19]) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            rows[i][j] = BLANK;
        }
    }
}

int main() {
    char player;
    int hole[2] = {10, 10};
    char rows[19][19];
    char moves[362][4];
    int movesIndex = 0;

    setupGrid(rows);
    switchTurn(&player);

    while (1) {
        updateGridHole(rows, hole);

        char cmd[12];
        //printf("Start fgets\n");
        //fgets(cmd, 12, stdin);
        //fseek(stdin, 0, SEEK_END);
        //printf("End fseek\n");

        //printf("Length: %d\n", strlen(cmd));
        //printf("Cmd: %s\n", cmd);
        //printf("Char: %c\n", cmd[9]);

        //printf("Start space count\nIteration: ");
        int spaces = 0;
        char c;
        int i = 0;
        while ((c = getchar()) != EOF && c != '\n') {
            //printf("%c", c);
            if (i < 10) {
                cmd[i] = c;
                i++;
            }
            if (c == ' ') {
                spaces++;
            }
        }
        //printf("Setting cmd[%d] to 0 char\n", i);
        cmd[i] = '\0';
        //printf("\nLetters found: %d\nSpaces found: %d\n", i, spaces);

        //if (cmd[0] == '\0' || cmd[0] == 4 || cmd[0] == 3) {
            //printf("true");
        if (1 == 2) {
        } else {
            //printf("Cmd 1: %c%c%c\n", cmd[0], cmd[1], cmd[2]);
            //printf("String %s with len %d\n", cmd, strlen(cmd));
            if (strncmp(cmd, "who", 3) == 0) {
                if (strlen(cmd) > 3) {
                    printf("Invalid!\n");
                } else {
                    who(player);
                }
            } else if (strncmp(cmd, "view", 4) == 0) {
                if (strlen(cmd) > 4) {
                    printf("Invalid!\n");
                } else {
                    view(rows, hole);
                }
            } else if (strncmp(cmd, "history", 7) == 0) {
                if (strlen(cmd) > 7) {
                    printf("Invalid!\n");
                } else {
                    history(moves, movesIndex);
                }
            } else if (strncmp(cmd, "term", 4) == 0) {
                if (strlen(cmd) > 4) {
                    printf("Invalid!\n");
                } else {
                    term();
                }
            } else if (strncmp(cmd, "resign", 6) == 0) {
                if (strlen(cmd) > 6) {
                    printf("Invalid!\n");
                } else {
                    resign(player);
                    break;
                }
            } else if (strncmp(cmd, "place ", 6) == 0) {
                int invalid = 0;
                if (spaces > 1) {
                    invalid = 1;
                    printf("Invalid!\n");
                }
                /*for (int i = 0; i < strlen(cmd); i++) {
                    if (cmd[i] == ' ' && i != 5) {
                        invalid = 1;
                        printf("Invalid!\n");
                        break;
                    }
                }*/

                if (invalid == 0) {
                    if (strlen(cmd) < 8 || cmd[6] == ' ' || cmd[8] == ' ') {
                        printf("Invalid!\n");
                    } else if (strlen(cmd) > 9 || cmd[7] == '0') {
                        printf("Invalid coordinate\n");
                    } else {
                        char pos[4];
                        strncpy(pos, cmd + 6, 3);
                        int gameOver = place(&player, rows, pos, moves, &movesIndex, hole);
                        if (gameOver == 1) {
                            break;
                        }
                    }
                }
            //} else if (strncmp(cmd, "grid", 3) == 0) {
                //viewGrid(rows);
            } else {
                printf("Invalid!\n");
            }
        }
    }

    history(moves, movesIndex);
    printf("Thank you for playing!\n");

    return 0;
}
