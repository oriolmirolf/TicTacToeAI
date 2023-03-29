// Board.cc
#include "Board.h"

using namespace std;

Board::Board()
{
    // Starting position =
    position = {'-', '-', '-', 
                '-', '-', '-', 
                '-', '-', '-'}; 
}

void Board::isLegalMove(char square_to_place)
{
    return position[square_to_place] == '-';
}

void Board::makeMove(char square_to_place, int player_turn)
{
    char move_marker;
    if (player_turn == PLAYER1)    move_marker = 'X';
    else                                move_marker = 'O'; 
        
    position[square_to_place] = move_marker;
}

bool Board::gameOver() {

    // We need to check all rows, columns and diagonals.

    // Rows:
    for (int i = 0; i < 9; i = i + 3)
        if (position[i] != '-' and (position[i] == position[i + 1]) == position[i + 2]) return true;

    // Columns:
        for (int i = 0; i < 3; i = i + 1)
        if (position[i] != '-' and (position[i] == position[i + 3]) == position[i + 6]) return true;

    //Diagonals:
        if ((position[0] != '-' and (position[0] == position[4]) == position[8])
            or
            (position[2] != '-' and (position[2] == position[4]) == position[6])) return true;
}

void Board::printBoard() {
    for (int i = 0; i < 9; ++i) {
        // if we're in positions 3 or 6 print new lines
        if (i == 3 or i == 6) cout << endl << "- - -" << endl;

        cout << position[i];

        if (i != 2 and i != 5 and i != 8) cout << '|';
    }
}