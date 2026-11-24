#pragma once
#include <SFML/Network.hpp>
#include <thread>
#include <iostream>
#include <atomic>
#include <SFML/Graphics.hpp>
#include "Board.h"

class Client {

public:
    Client(std::shared_ptr<Board> _board);
    bool connect();
    void input();
    void run();
    std::atomic<bool> running = false;
    std::atomic<bool> connected = false;
    sf::Packet packData(std::string _string = "", sf::Vector2f _origin = {-1, -1}, sf::Vector2f _destination = { -1, -1 }) const;
        void unpackData(sf::Packet _packet, std::string& _string, sf::Vector2f& _origin, sf::Vector2f& _destination);
    
    private:
        std::unique_ptr<sf::TcpSocket> socket;
        std::shared_ptr<Board> board;
        //sf::Packet packet;
       // sf::Socket::Status status = socket->receive(packet);
        //std::string string;
        //sf::Vector2f origin;
        //sf::Vector2f destination;






};
