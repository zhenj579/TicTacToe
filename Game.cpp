#include "Game.h"
#include <cassert>

Game::Game() : player1(new Player()), player2(new Player()) { }
void Game::start()
{
    std::cout<<"starting game!"<<std::endl;
    std::cout<<"Player 1, which symbol do you want to be? "<<std::endl;
    std::cout<<"Enter O or X"<<std::endl;
    char player1Symbol;
    std::cin>>player1Symbol;
    player1Symbol = toupper(player1Symbol);
    player1->setSymbol(player1Symbol);
    char player2Symbol = player1Symbol == 'O'? 'X' : 'O';
    std::cout<<"Player 2, you are: "<<player2Symbol<<std::endl;
    player2->setSymbol(player2Symbol);
    int counter = 1; // 1 = player 1's move, 2 = player 2's move
    Player *winner = nullptr;
    while(winner == nullptr && !board.filled())
    {
        board.print();
        std::cout<<"Player "<<counter<<", what row do you want to place your symbol? "<<std::endl;
        int r;
        std::cin>>r;
        std::cout<<"Player "<<counter<<", what col do you want to place your symbol? "<<std::endl;
        int c;
        std::cin>>c;
        Coordinates coord{r,c};
        assert(coord.x == r && coord.y == c);
        if(counter == 1)
        {
            if(board.canPut(coord))
            {
                board.put(player1, coord);
                winner = findWinner();
                counter++;
            }
            else
            {
                std::cout<<"invalid row and/or col, try again"<<std::endl;
            }
        }
        else
        {
            if(board.canPut(coord))
            {
                board.put(player2, coord);
                winner = findWinner();
                counter--;
            }
            else
            {
                std::cout<<"invalid row and/or col, try again"<<std::endl;
            }
        }
    }
    board.print();
    std::cout<<"Game Over!"<<std::endl;
    std::cout<<winner->getSymbol()<<" has won the game!"<<std::endl;
    std::cout<<"Here is the move history!"<<std::endl;
    board.printMoveHistory();
}

Player* Game::findWinner() const
{
    char winningSymbol;
    if(board.get()[0][0] != '-' and board.get()[0][0] == board.get()[1][1] and board.get()[1][1] == board.get()[2][2]) // diagonal
    {
        winningSymbol = board.get()[0][0];
        return player1->getSymbol() == winningSymbol ? player1 : player2;
    }
    if(board.get()[0][2] != '-' and board.get()[0][2] == board.get()[1][1] and board.get()[1][1] == board.get()[2][0]) // anti-diagonal
    {
        winningSymbol = board.get()[0][2];
        return player1->getSymbol() == winningSymbol ? player1 : player2;
    }
    for(int i = 0; i < board.get().size(); i++) // verticals
    {
        if(board.get()[0][i] != '-' and board.get()[0][i] == board.get()[1][i] and board.get()[1][i] == board.get()[2][i])
        {
            winningSymbol = board.get()[0][i];
            return player1->getSymbol() == winningSymbol ? player1 : player2;
        }
    }

    for(int i = 0; i < board.get().size(); i++) // horizontals
    {
        if(board.get()[i][0] != '-' and board.get()[i][0] == board.get()[i][1] and board.get()[i][1] == board.get()[i][2])
        {
            winningSymbol = board.get()[i][0];
            return player1->getSymbol() == winningSymbol ? player1 : player2;
        }
    }
    return nullptr;
}

