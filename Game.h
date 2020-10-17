#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board board;
    Player *player1;
    Player *player2;
public:
    Game();
    void start();
    Player *findWinner() const;
};


#endif //TICTACTOE_GAME_H
