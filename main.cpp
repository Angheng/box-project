#include "board.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

void test_in_console(int map[MAX_ROW][MAX_COL], int start_r, int start_c) {
    Board board(map, start_r ,start_c);

    board.print_board();

    char input;

    do {
        cout << "\ninput  W(up), A(Left), S(Down), D(Right) to Move. > ";
        cin >> input;

        switch (input) {
            case 'w':
                board.moving('u');
                board.print_board();
                break;

            case 'a':
                board.moving('l');
                board.print_board();
                break;

            case 's':
                board.moving('d');
                board.print_board();
                break;

            case 'd':
                board.moving('r');
                board.print_board();
                break;

            case 'r':
                board.reset();
                board.print_board();
                break;

            case 'q':
                cout << "\n<< Quit >>" << endl;
                break;

            default:
                cout << "Please input based in \"WASD\" \n";
        }

        if (board.is_end()) {
            cout << "\n\n<< You WIN!!! >>\n";
            break;
        }

    } while (input != 'q');
}

void test_in_NC(int map[MAX_ROW][MAX_COL], int start_r, int start_c) {
}

int main() {
    int map[MAX_ROW][MAX_COL] = {{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                 {4, 4, 4, 0, 0, 0, 0, 0, 4, 4},
                                 {4, 4, 4, 0, 0, 0, 0, 0, 4, 4},
                                 {4, 4, 4, 0, 0, 3, 3, 0, 4, 4},
                                 {4, 4, 4, 0, 0, 2, 2, 0, 4, 4},
                                 {4, 4, 4, 0, 0, 0, 0, 0, 4, 4},
                                 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                                 {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}};

    test_in_console(map, 6, 5); //Console Test


}

