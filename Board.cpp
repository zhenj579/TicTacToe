#include "Board.h"

void Board::print() const
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void Board::put(const Player &player, const Coordinates &coordinates)
{
    if(canPut(coordinates))
    {
        board[coordinates.x][coordinates.y] = player.getSymbol();
        moveHistory.push(std::make_pair(player, coordinates));
    }
}

bool Board::canPut(const Coordinates &coordinates) const
{
    return coordinates.x >= 0 && coordinates.x < 3 && coordinates.y >= 0 && coordinates.y < 3 && board[coordinates.x][coordinates.y] == '-' ;
}

std::vector<std::vector<char>> Board::get() const
{
    return board;
}

bool Board::filled() const
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == '-') return false;
        }
    }
    return true;
}

void Board::printMoveHistory()
{
    std::pair<Player, Coordinates> move;
    while(!moveHistory.empty())
    {
        move = moveHistory.front();
        moveHistory.pop();
        std::cout<<"Symbol: "<<move.first.getSymbol()<<" Coordinates: "<<move.second.x<<","<<move.second.y<<std::endl;
    }
}