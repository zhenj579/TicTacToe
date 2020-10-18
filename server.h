#ifndef TICTACTOE_SERVER_H
#define TICTACTOE_SERVER_H

#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

struct server {
    void start();
};


#endif //TICTACTOE_SERVER_H
