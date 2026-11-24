#pragma once
#include <SFML/Network.hpp>
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <memory>
#include "Board.h"

class Server {
public:
	Server(std::shared_ptr<Board> _board);
	void init();
	void run();
	void listen(sf::TcpSocket& c_socket);
	void send(std::string buffer, sf::TcpSocket& c_socket);
	void input();
	void relay(std::string buffer, sf::TcpSocket& c_socket);
	sf::Packet packData(std::string _string = "", sf::Vector2f _origin = { -1, -1 }, sf::Vector2f _destination = { -1, -1 }) const;
	void unpackData(sf::Packet _packet, std::string& _string, sf::Vector2f& _origin, sf::Vector2f& _destination);

	
private:
	std::vector<std::thread> workers;
	std::vector<std::unique_ptr<sf::TcpSocket>> connections;
	std::unique_ptr<sf::TcpListener> listener;
	bool running = true;
	std::mutex mutex;
	std::shared_ptr<Board> _board;
};