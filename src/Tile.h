#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Piece.h"


class Tile
{
public:
	Tile();
	Tile(int size, sf::Vector2f position, sf::Vector2i _coordinates);
	void render(sf::RenderWindow& window);
	void setHover(bool hover);
	void setPosition(sf::Vector2i position);
	void clicked(const sf::Event::MouseButtonPressed* event, std::shared_ptr<Piece>& held_piece);
	bool dropPiece(std::shared_ptr<Piece> _piece);
	void movePiece(Tile& _tile);
	sf::Vector2f getCentre();
	int getSize() { return size; }	
	sf::RectangleShape& getShape() { return shape; }
	std::shared_ptr<Piece> getPiece() { return piece; }

private:
	sf::RectangleShape shape;
	bool mouse_hovering;
	int size;
	std::shared_ptr<Piece> piece = nullptr;
	sf::Vector2i coordinates;
};