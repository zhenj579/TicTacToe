//
// Created by jzhen on 10/17/2020.
//

#include "client.h"

void client::connect()
{
    try
    {
        const std::string local_host = "127.0.0.1";
        const std::string port_number = "50";
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(local_host, port_number);
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);
        for(;;)
        {
            //read or write here
        }
    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}