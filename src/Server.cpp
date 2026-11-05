#include <iostream>
#include "Server.h"

void Server::init() {

	if (listener == nullptr) {
		listener = std::make_unique<sf::TcpListener>();
	}
	if (listener->listen(53000) != sf::Socket::Status::Done) {
		std::cout << "couldnt bind listener to port 53" << std::endl;
	}
}

void Server::run() {
	while (running) {
		sf::TcpSocket& c_sock = *connections.emplace_back(std::make_unique<sf::TpSocket>());
		if (listener->accept(c_sock) != sf::Socket::Status::Done) {
			connections.pop_back();
			std::cout << "connection failed on server side" << std::endl;
		}
	}
}