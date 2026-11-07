
#include "Game.h"
#include "Tile.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
}

Game::~Game()
{
    delete join_button;
    delete host_button;
    delete font;
}

bool Game::init()
{
    board = std::make_shared<Board>(window);
    board->init();

    font = new sf::Font();
    if (!font->openFromFile("Data/Fonts/OpenSans-Bold.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        delete font;
        font = nullptr;
        return false;
    }

    host_button = new sf::Text(*font, "Host Game", 30);
    host_button->setFillColor(sf::Color::White);
    host_button->setPosition({900, 70});

    join_button = new sf::Text(*font, "Join Game", 30);
    join_button->setFillColor(sf::Color::White);
    join_button->setPosition({900, 200});

    game_state = MENU;

    return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    board->render(); 
    window.draw(*host_button);
    window.draw(*join_button);  
}

void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
    board->mouseButtonPressed(event);
    if(game_state == MENU){
        if(host_button->getGlobalBounds().contains(sf::Vector2f(event->position))){
            game_state = HOSTING;
            std::cout << "Creating server, hosting" << std::endl;
            server = std::make_unique<Server>();
            server->init();
            std::thread server_thread([&]() {
                server->run();
            });
           server_thread.detach();
        }
    }
    else if(join_button->getGlobalBounds().contains(sf::Vector2f(event->position))){
        game_state = JOINING;
        std::cout << "Connecting to server" << std::endl;
        client = std::make_unique<Client>();
        client->connect();
        std::thread client_thread([&]() {
            client->run();
        });
        client_thread.detach();
    }
}

void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
    board->mouseButtonReleased(event);    
}

void Game::keyPressed(const sf::Event::KeyPressed* event)
{

}

void Game::keyReleased(const sf::Event::KeyReleased* event)
{

}

void Game::mouseMoved(const sf::Event::MouseMoved* event)
{
    board->mouseMoved(event);
}




