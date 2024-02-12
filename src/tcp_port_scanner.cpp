#include "tcp_port_scanner.h"
#include <iostream>
using boost::asio::ip::tcp;

std::vector<int> TCPPortScanner::scan() {
  std::vector<int> open_ports;

  boost::asio::io_service io_service;
  for (int port = start_port_; port <= end_port_; ++port) {
    std::cout << "Scanning port " << port
              << std::endl; // Add this line for debugging
    tcp::socket socket(io_service);
    tcp::endpoint endpoint(boost::asio::ip::address::from_string(target_ip_),
                           port);
    boost::system::error_code ec;
    socket.connect(endpoint, ec);
    if (!ec) {
      open_ports.push_back(port);
    }
  }

  return open_ports;
}
