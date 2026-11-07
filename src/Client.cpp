#include <iostream>
#include "Client.h"

void Client::connect(){
    if(socket == nullptr){
        socket = std::make_unique<sf::TcpSocket>();
    }
    sf::IpAddress* address = new sf::IpAddress("127.0.0.1");
    if(socket->connect(*address, 53000) == sf::Socket::Status::Done){
        std::cout << "you're connected" <<std::endl;
        connected = true;
    }
    else{
        std::cout << "failed to connect to 127.0.0.1::53000" << std::endl;
    }
}