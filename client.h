//
// Created by jzhen on 10/17/2020.
//

#ifndef TICTACTOE_CLIENT_H
#define TICTACTOE_CLIENT_H

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

struct client {
    void connect();
};


#endif //TICTACTOE_CLIENT_H
