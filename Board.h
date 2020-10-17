#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "Player.h"
#include <iostream>
#include <memory>
#include <vector>
#include <queue>

struct Coordinates
{
    int x;
    int y;
};

class Board {
private:
    std::vector<std::vector<char>> board = { {'-', '-', '-'},
                                             {'-', '-', '-'},
                                             {'-', '-', '-'} };
    std::queue<std::pair<Player , Coordinates>> moveHistory;
public:
    void print() const;
    bool canPut(const Coordinates &coordinates) const;
    void put(const Player &player, const Coordinates &coordinates);
    std::vector<std::vector<char>> get() const;
    bool filled() const;
    void printMoveHistory();

};


#endif //TICTACTOE_BOARD_H
