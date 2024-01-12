#include <boost/asio.hpp>
#include <iostream>
#include <boost/array.hpp>


using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Server endpoint representation (localhost at port 1234)
        tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);

        // Creating and opening the socket
        tcp::socket socket(io_context);
        socket.connect(endpoint);

        for (;;) {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            // Reading from socket
            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof) {
                break; // Connection closed cleanly by peer
            } else if (error) {
                throw boost::system::system_error(error); // Some other error
            }

            std::cout.write(buf.data(), len);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
