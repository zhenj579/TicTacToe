#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H


class Player {
private:
    char symbol;
public:
    void setSymbol(const char &sym);
    char getSymbol() const;
};


#endif //TICTACTOE_PLAYER_H
