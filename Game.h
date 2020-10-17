#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Board.h"
#include "Player.h"

class Game {
private:
    Board board;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
public:
    Game();
    void start();
    std::shared_ptr<Player> findWinner() const;
};


#endif //TICTACTOE_GAME_H
