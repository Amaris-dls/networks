
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Board.h"
#include "Client.h"
#include "Server.h"

enum GameState {
	MENU,
	HOSTING,
	JOINING,
	PLAYING
};

class Game
{
 public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
	void keyPressed(const sf::Event::KeyPressed* event);
	void keyReleased(const sf::Event::KeyReleased* event);
	void mouseMoved(const sf::Event::MouseMoved* event);

 private:
	sf::RenderWindow& window;

	std::shared_ptr<Board> board;
	std::unique_ptr<Client> client;
	std::unique_ptr<Server> server;

	sf::Font* font = nullptr;
	sf::Text* host_button = nullptr;
    sf::Text* join_button = nullptr;

	GameState game_state;

};

