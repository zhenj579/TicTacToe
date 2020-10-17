//
// Created by jzhen on 10/17/2020.
//

#ifndef TICTACTOE_TEST_H
#define TICTACTOE_TEST_H

#include "Game.h"
#include <cassert>

struct test
{
    test();
    Player *tictactoeWinAlgo(Board b, Player *player1, Player *player2 = nullptr) const;
};


#endif //TICTACTOE_TEST_H
