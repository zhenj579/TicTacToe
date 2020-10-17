//
// Created by jzhen on 10/17/2020.
//

#include "test.h"

std::shared_ptr<Player> test::tictactoeWinAlgo(Board board, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2) const
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

test::test()
{
    std::shared_ptr<Player> p1;
    p1->setSymbol('O');
    Coordinates c;

    Board b1; // diag

    c.x = 0;
    c.y = 0;
    b1.put(*p1, c);

    c.x = 1;
    c.y = 1;
    b1.put(*p1, c);

    c.x = 2;
    c.y = 2;
    b1.put(*p1, c);

    b1.print();
    assert(tictactoeWinAlgo(b1,p1) == p1);

    std::cout<<std::endl;

    Board b2; //antidiag

    c.x = 0;
    c.y = 2;
    b2.put(*p1, c);

    c.x = 1;
    c.y = 1;
    b2.put(*p1, c);

    c.x = 2;
    c.y = 0;
    b2.put(*p1, c);

    b2.print();
    assert(tictactoeWinAlgo(b2,p1) == p1);

    std::cout<<std::endl;

    Board b3; //horizontal

    c.x = 0;
    c.y = 0;
    b3.put(*p1, c);

    c.x = 0;
    c.y = 1;
    b3.put(*p1, c);

    c.x = 0;
    c.y = 2;
    b3.put(*p1, c);

    b3.print();
    assert(tictactoeWinAlgo(b3,p1) == p1);

    std::cout<<std::endl;

    Board b4; //horizontal

    c.x = 1;
    c.y = 0;
    b4.put(*p1, c);

    c.x = 1;
    c.y = 1;
    b4.put(*p1, c);

    c.x = 1;
    c.y = 2;
    b4.put(*p1, c);

    b4.print();
    assert(tictactoeWinAlgo(b4,p1) == p1);

    std::cout<<std::endl;

    Board b5; //horizontal

    c.x = 2;
    c.y = 0;
    b5.put(*p1, c);

    c.x = 2;
    c.y = 1;
    b5.put(*p1, c);

    c.x = 2;
    c.y = 2;
    b5.put(*p1, c);

    b5.print();
    assert(tictactoeWinAlgo(b5,p1) == p1);

    std::cout<<std::endl;

    Board b6; //vertical

    c.x = 0;
    c.y = 0;
    b6.put(*p1, c);

    c.x = 1;
    c.y = 0;
    b6.put(*p1, c);

    c.x = 2;
    c.y = 0;
    b6.put(*p1, c);

    b6.print();
    assert(tictactoeWinAlgo(b6,p1) == p1);

    Board b7; //vertical

    c.x = 0;
    c.y = 1;
    b7.put(*p1, c);

    c.x = 1;
    c.y = 1;
    b7.put(*p1, c);

    c.x = 2;
    c.y = 1;
    b7.put(*p1, c);

    b7.print();
    assert(tictactoeWinAlgo(b7,p1) == p1);
    std::cout<<std::endl;

    Board b8; //vertical

    c.x = 0;
    c.y = 2;
    b8.put(*p1, c);

    c.x = 1;
    c.y = 2;
    b8.put(*p1, c);

    c.x = 2;
    c.y = 2;
    b8.put(*p1, c);

    b8.print();
    assert(tictactoeWinAlgo(b8,p1) == p1);
    std::cout<<std::endl;

    std::cout<<"all tests passed"<<std::endl;

}