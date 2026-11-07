
#include "Game.h"
#include "Tile.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
}

Game::~Game()
{
    delete join_game;
    delete host_game;
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

    host_game = new sf::Text(*font, "Host Game", 30);
    host_game->setFillColor(sf::Color::White);
    host_game->setPosition({900, 70});

    join_game = new sf::Text(*font, "Join Game", 30);
    join_game->setFillColor(sf::Color::White);
    join_game->setPosition({900, 200});

    return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    board->render(); 
    window.draw(*host_game);
    window.draw(*join_game);  
}

void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
    board->mouseButtonPressed(event);
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




