#pragma once

#include <SFML/Graphics.hpp>

class Piece
{
	public:
		Piece(const sf::Texture& texture, int _player, sf::Vector2f size_target = { 0,0 }, sf::Vector2f centre = { 0,0 });
		~Piece();
		int getPlayerID() { return player; }
		sf::Sprite& getSprite() { return sprite; }
		sf::Vector2i getOrigin() { return origin; }
		sf::Vector2i getDestination() { return destination; }
		void setOrigin(sf::Vector2i _origin) { origin = _origin; }
		void setDestination(sf::Vector2i _destination) { destination = _destination; }

	private:
		int player;
		sf::Sprite sprite;
		sf::Vector2i origin = { -1,-1 };
		sf::Vector2i destination = { -1,-1 };
};