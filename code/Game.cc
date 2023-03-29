// Game.cc
#include "Game.h"
#include "Board.h"
using namespace std;

#define SINGLEPLAYER = 1
#define MULTIPLAYER = 2


Game::Game()
{
    number_of_moves = 0;
}


void printOptions() 
{
    cout << "Press 1 to play SINGLEPLAYER (vs AI)"  << endl;
    cout << "Press 2 to play MULTIPLAYER"           << endl;
    cout << "Press 3 to EXIT"                       << endl;
}

void printWelcomeScreen() 
{
    // Ascii art obtaiend from: https://ascii.co.uk/art/tictactoe

    cout << "  _   _      _             _              " << endl;
    cout << " | | (_)    | |           | |             " << endl;
    cout << " | |_ _  ___| |_ __ _  ___| |_ ___   ___  " << endl;
    cout << " | __| |/ __| __/ _` |/ __| __/ _ \ / _ \ " << endl;
    cout << " | |_| | (__| || (_| | (__| || (_) |  __/ " << endl;
    cout << "  \__|_|\___|\__\__,_|\___|\__\___/ \___| " << endl;
}

void Game::Run()
{
    printWelcomeScreen()

    while (true) // Keep playing indefinitely until "3" is pressed.
    {
        printOptions();
        int option;
        cin >> option
        switch (option) {
            case 1:
                Game::Play(SINGLEPLAYER);
                break;
            case 2:
                Game::Play(MULTIPLAYER);
                break;
            case 3:
                cout << "Hope you had fun!" << endl;
                return;
            default:
                cout << "Invalid option, choose again" << endl;
        }
    }
}

void printTurn() 
{
    if (turn == PLAYER1) cout << "Player 1 please select square to move [1..9]" << endl;
    if (turn == PLAYER2) cout << "Player 2 please select square to move [1..9]" << endl;
}

void printWinner()
{
    if (turn == PLAYER1) cout << "Player 1 WINS!" << endl;
    if (turn == PLAYER1) cout << "Player 2 WINS!" << endl;
}

void printTie()
{
    cout << "Game ended in a TIE! Well played!" << endl;
}

void Game::Play(int mode)
{   
    Board board;

    if (mode == SINGLEPLAYER) {
        //To define
    }

    if (mode == MULTIPLAYER) {
        
        while (number_of_moves < 9) // Run perpetually until game ends
        {
            board.printBoard();
            printTurn();
            int move;
            cin >> move;
            while (not board.isLegalMove(move))
            {
                cout << "Invalid move, please try again:" << endl;
                cin >> move;
            }

            board.makeMove(move, turn);
            
            if (board.gameOver())
            {
                game_finished = true;
                board.printBoard();
                printWinner();
                return;
            }
            
            // If we reached here, the game ended in a tie!
            printTie()
            return;
        }
    }
}