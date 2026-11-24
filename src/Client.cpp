#include <iostream>
#include "Client.h"

Client::Client(std::shared_ptr<Board> _board) : board(_board) {

}

sf::Packet Client::packData(std::string _string, sf::Vector2f _origin, sf::Vector2f _destination) const {
    sf::Packet packet;
    packet << _string << _origin.x << _origin.y << _destination.x << _destination.y;
    return packet;
}

void Client::unpackData(sf::Packet _packet, std::string& _string, sf::Vector2f& _origin, sf::Vector2f& _destination) {
    _packet >> _string >> _origin.y >> _destination.x >> _destination.y;
    
}

bool Client::connect(){
    if(socket == nullptr){
        socket = std::make_unique<sf::TcpSocket>();
    }

   if(socket->connect(*sf::IpAddress::fromString("127.0.0.1"), 53000) == sf::Socket::Status::Done){
        std::cout << "you're connected" <<std::endl;
        connected = true;
        return true;
   }
    else{
        std::cout << "failed to connect to 127.0.0.1::53000" << std::endl;
        return false;
    }
    return false;
}

void Client::input(){
    while(running){
        std::string str;
        std::getline(std::cin, str);
        std::cin.clear();
        sf::Packet packet = packData(str);
        if(connected){
            //socket->send(reinterpret_cast<char*>(str.data()), str.length());
            i_socket->send(packet);
        }
    }
}

void Client::run(){
    running = true;
    std::thread input_thread([&] {input(); });
    input_thread.detach();

    while(running){
        char static_buffer[1028];
        while(connected){
            std::size_t received;
            sf::Packet packet;
            //sf::Socket::Status status = socket->receive(static_buffer, 1028, received);
            sf::Socket::Status status = socket->receive(packet);
            if(status == sf::Socket::Status::Disconnected){
                connected = false;
                std::cout << "Clean disconnection from server" << std::endl;
                socket->disconnect();
                break;
            }
            else{
                if(received < 1028) static_buffer[received] = '\0';
                std::string string;
                sf::Vector2f origin;
                sf::Vector2f destination;
                unpackData(packet, string, origin, destination);
                if (string.length() > 0) {
                    std::cout << string << std::endl;
                }
                if (origin.x >= 0 && destination.x >= 0) {
                    std::lock_guard<std::mutex> lck(board_mutex);
                    board->moveByCoords(origin, destination);
                }
                std::cout << static_buffer << std::endl;
            }
        }
    }
}