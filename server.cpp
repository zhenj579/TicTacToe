#include "server.h"

void server::start()
{
    const std::string local_host = "127.0.0.1";
    try
    {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(boost::asio::ip::make_address(local_host),50));
        for(;;)
        {
            tcp::socket socket(io_context);
            acceptor.accept();
            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer("hello!"), ignored_error);
            // read write here
        }
    }
    catch(std::exception &e)
    {
        std::cerr<< e.what() << std::endl;
    }
}