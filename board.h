//
// Created by angheng on 19. 5. 23.
// liveCoding project/main.cpp project/board.h

#ifndef LIVECODING_BOARD_H
#define LIVECODING_BOARD_H

#define MAX_ROW 10
#define MAX_COL 10


class Player{
public:
    int r, c;

    Player() {
        r = 0, c = 0;
    }
};


class Board {

private:

    int board[MAX_ROW][MAX_COL];
    int player_move = 0, box_move = 0;


    int first_board[MAX_ROW][MAX_COL];
    int first_r = 0, first_c = 0;

    int numBoxs = 0, correctBoxs = 0;

    Player player;


public:

    Board();

    Board(int arr[MAX_ROW][MAX_COL], int r, int c);

    void make_board(int arr[MAX_ROW][MAX_COL]);

    void print_board();


    void moving(char direction);

    bool isPosible(int r_move, int c_move);

    int( *getBoard() )[MAX_COL] {
        return board;
    }

    void setPlayer(int r, int c);

    bool is_end();

    void reset();
};


#endif //LIVECODING_BOARD_H
