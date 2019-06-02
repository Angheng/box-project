#include "board.h"
#include <iostream>

using namespace std;

/** State of Each NUmber **/
/** 0: Empty Space, 1: Wall, 2: Box **/
/** 3: Destination, 4: OuyBound, 5: Character **/
/** 10: Destination That completed **/

Board::Board() {
    board[MAX_ROW][MAX_COL] = {0};
}

Board::Board(int (*arr)[10], int r, int c)  {
    first_r = r; first_c = c;

    setPlayer(r, c);
    make_board(arr);
}


void Board::make_board(int (*arr)[10]) {

    for (int i = 0; i < MAX_ROW; i ++) {

        for (int j = 0; j < MAX_COL; j ++) {
            board[i][j] = first_board[i][j] = arr[i][j];

            if (arr[i][j] == 2)
                numBoxs ++;
        }

    }

}

void Board::print_board() {
    cout << "\n======= map =======\n";

    for (int i = 0; i < MAX_ROW; i ++) {

        for (int j = 0; j < MAX_COL; j ++) {
            if (player.r == i && player.c == j)
                cout << 5 << " ";
            else
                cout << board[i][j] << " ";
        }

        cout << endl;

    }
    cout << "-------------------\n";
    cout << "Player Moved : " << player_move << " || Box Moved: " << box_move << endl;

    cout << "===================\n";
}

void Board::moving(char direction) {
    int move_r = 0, move_c = 0;

    switch (direction) {
        case 'u':
            if (!isPosible(-1, 0)) {    // Can Player moving?
                break;
            }

            if (board[player.r - 1][player.c] == 2) {   // Case of Pushing Box
                board[player.r - 1][player.c] = 0;

                if (board[player.r - 2][player.c] == 3) {   // Box Entering the Destination
                    board[player.r - 2][player.c] = 10;
                    correctBoxs ++;
                } else {                                    // Default Case
                    board[player.r - 2][player.c] = 2;
                }

                box_move ++;

            } else if (board[player.r - 1][player.c] == 10){  // Case of Pushing Box at Destination.
                board[player.r - 1][player.c] = 3;

                if (board[player.r - 2][player.c] == 3) {
                    board[player.r - 2][player.c] = 10;
                } else {
                    board[player.r - 2][player.c] = 2;
                    correctBoxs --;
                }

                box_move ++;
            }

            player.r --; player_move ++;

            break;

        case 'd':
            if (!isPosible(1, 0)) {
                break;
            }

            if (board[player.r + 1][player.c] == 2) {   // Case of Pushing Box
                board[player.r + 1][player.c] = 0;

                if (board[player.r + 2][player.c] == 3) {   // Box Entering the Destination
                    board[player.r + 2][player.c] = 10;
                    correctBoxs ++;
                } else {                                    // Default Case
                    board[player.r + 2][player.c] = 2;
                }

                box_move ++;

            } else if (board[player.r + 1][player.c] == 10){  // Case of Pushing Box at Destination.
                board[player.r + 1][player.c] = 3;

                if (board[player.r + 2][player.c] == 3) {
                    board[player.r + 2][player.c] = 10;
                } else {
                    board[player.r + 2][player.c] = 2;
                    correctBoxs --;
                }

                box_move ++;
            }

            player.r ++; player_move ++;

            break;

        case 'l':
            if (!isPosible(0, -1)) {
                break;
            }

            if (board[player.r][player.c -1] == 2) {   // Case of Pushing Box
                board[player.r][player.c -1] = 0;

                if (board[player.r][player.c - 2] == 3) {   // Box Entering the Destination
                    board[player.r][player.c - 2] = 10;
                    correctBoxs ++;
                } else {                                    // Default Case
                    board[player.r][player.c - 2] = 2;
                }

                box_move ++;

            } else if (board[player.r][player.c - 1] == 10){  // Case of Pushing Box at Destination.
                board[player.r][player.c - 1] = 3;

                if (board[player.r][player.c - 2] == 3) {
                    board[player.r][player.c - 2] = 10;
                } else {
                    board[player.r][player.c - 2] = 2;
                    correctBoxs --;
                }

                box_move ++;
            }

            player.c --; player_move ++;

            break;

        case 'r':
            if (!isPosible(0, 1)) {
                break;
            }

            if (board[player.r][player.c + 1] == 2) {   // Case of Pushing Box
                board[player.r][player.c + 1] = 0;

                if (board[player.r][player.c + 2] == 3) {   // Box Entering the Destination
                    board[player.r][player.c + 2] = 10;
                    correctBoxs ++;
                } else {                                    // Default Case
                    board[player.r][player.c + 2] = 2;
                }

                box_move ++;

            } else if (board[player.r][player.c + 1] == 10){  // Case of Pushing Box at Destination.
                board[player.r][player.c + 1] = 3;

                if (board[player.r][player.c + 2] == 3) {
                    board[player.r][player.c + 2] = 10;
                } else {
                    board[player.r][player.c + 2] = 2;
                    correctBoxs --;
                }

                box_move ++;
            }

            player.c ++; player_move ++;

            break;
    }
}

bool Board::isPosible(int r_move, int c_move)  {
    if (r_move * 2 + player.r >= MAX_ROW || c_move * 2 + player.c >= MAX_COL)
        return false;


    if (board[r_move + player.r][c_move + player.c] == 2 || board[r_move + player.r][c_move + player.c] == 10) {
        if (board[r_move * 2 + player.r][c_move * 2 + player.c] == 0 || board[r_move * 2 + player.r][c_move * 2 + player.c] == 3)
            return true;
    }

    return ( board[r_move + player.r][c_move + player.c] == 0 || board[r_move + player.r][c_move + player.c] == 3 );
}

void Board::setPlayer(int r = 0, int c = 0) {
    player.r = r; player.c = c;
}

bool Board::is_end() {
    return numBoxs == correctBoxs;
}

void Board::reset() {
    for (int i = 0; i < MAX_ROW; i ++) {

        for (int j = 0; j < MAX_COL; j ++) {
            board[i][j] = first_board[i][j];
        }

    }

    correctBoxs = 0; setPlayer(first_r, first_c);
    player_move = box_move = 0;
}
