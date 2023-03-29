// Board.h
#ifndef BOARD_H
#define BOARD_H

using namespace std;

#define SINGLEPLAYER = 1
#define MULTIPLAYER = 2

class Board
{
    char[9] position;

public:

    void isLegalMove(char square_to_place);

    void makeMove(char square_to_place, int player_turn);

    bool gameOver();

    void printBoard();
};

#endif