#ifndef TCP_PORT_SCANNER_HPP
#define TCP_PORT_SCANNER_HPP

#include <boost/asio.hpp>
#include <string>
#include <vector>

class TCPPortScanner {
public:
    TCPPortScanner(const std::string& target_ip, int start_port, int end_port)
        : target_ip_(target_ip), start_port_(start_port), end_port_(end_port) {}

    std::vector<int> scan();

private:
    std::string target_ip_;
    int start_port_;
    int end_port_;
};

#endif  // TCP_PORT_SCANNER_HPP
