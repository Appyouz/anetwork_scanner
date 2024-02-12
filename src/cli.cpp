#include <iostream>
#include <string>
#include <vector>
// #include <cxxopts.hpp>
// #include "../external/cxxopts/include/cxxopts.hpp"
#include "../external/cxxopts-3.1.1/include/cxxopts.hpp"
#include "tcp_port_scanner.h"
#include <sstream>
#include <utility>

int main(int argc, char *argv[]) {
  cxxopts::Options options("network-scanner", "A simple network scanner");

  options.add_options()("t,target", "Target IP address",
                        cxxopts::value<std::string>())(
      "p,port-range", "Port range (start-end)",
      cxxopts::value<std::string>())("h,help", "Print usage");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (!result.count("target") || !result.count("port-range")) {
    std::cerr << "Error: Target IP address and port range are required."
              << std::endl;
    return 1;
  }

  std::string target_ip = result["target"].as<std::string>();
  std::string port_range_str = result["port-range"].as<std::string>();

  // Parse port range
  std::istringstream iss(port_range_str);
  int start_port, end_port;
  char dash;
  if (!(iss >> start_port >> dash >> end_port && dash == '-')) {
    std::cerr << "Error: Invalid port range format. Please use start-end "
                 "format (e.g., 1-1024)."
              << std::endl;
    return 1;
  }

  // Perform scan using TCPPortScanner
  TCPPortScanner scanner(target_ip, start_port, end_port);
  std::vector<int> open_ports = scanner.scan();

  // Display results
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
