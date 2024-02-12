#include <iostream>
#include "tcp_port_scanner.hpp"

int main() {
    std::string target_ip = "127.0.0.1";
    int start_port = 1;
    int end_port = 8080;

    TCPPortScanner scanner(target_ip, start_port, end_port);
    std::vector<int> open_ports = scanner.scan();

    if (open_ports.empty()) {
        std::cout << "No open ports found." << std::endl;
    } else {
        std::cout << "Open ports:";
        for (int port : open_ports) {
            std::cout << " " << port;
        }
        std::cout << std::endl;
    }

    return 0;
}
