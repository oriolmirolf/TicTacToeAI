// Game.h
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{
    enum class Turn { PLAYER1, PLAYER2 };
    Turn turn;
    int number_of_moves;
    
public:
    Run();
    Play(int mode);
};

#endif