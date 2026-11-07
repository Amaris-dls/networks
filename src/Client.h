#pragma once
#include <SFML/Network.hpp>
#include <thread>
#include <iostream>
#include <atomic>
#include <SFML/Graphics.hpp>

class Client {

    public:
        bool connect();
        void input();
        void run(); 
        std::atomic<bool> running = false;
        std::atomic<bool> connected = false;
    
    private:
        std::unique_ptr<sf::TcpSocket> socket;




};
