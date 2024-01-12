#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Listening for any new incomming connection at port 1234 with IPv4 protocol
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1234));

        std::cout << "Server is running...\n";

        while (true) {
            // Creating a socket
            tcp::socket socket(io_context);

            // Waiting and accepting the incomming connection
            acceptor.accept(socket);

            std::string message = "Hello from Server!";
            boost::system::error_code ignored_error;

            // Writing the message for the client
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
