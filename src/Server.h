#pragma once
#include <SFML/Network.hpp>
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <memory>

public:
	void init();
	void run();
	void listen(sf::TcpSocket& c_socket);
	void send