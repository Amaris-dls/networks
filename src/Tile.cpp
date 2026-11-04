#include "Tile.h"

Tile::Tile() //Default constructor
{
	size = 50;
	shape = sf::RectangleShape({ (float)size,(float)size });
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(-5.f);
	shape.setOutlineColor(shape.getFillColor());
	coordinates = { 0,0 };
}

Tile::Tile(int size_, sf::Vector2f position_, sf::Vector2i _coordinates) //Constructor with size, position & coordinates
{
	size = size_;
	shape = sf::RectangleShape({ (float)size,(float)size });
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(-floor(size/15));
	shape.setOutlineColor(shape.getFillColor());
	shape.setPosition(position_);
	coordinates = _coordinates;
}

void Tile::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Tile::setHover(bool hover) //Changes outline colour to blue if parameter is true 
{
	if (hover)
	{
		shape.setOutlineColor(sf::Color(0,0,190,230));
	}
	else
	{
		shape.setOutlineColor(shape.getFillColor());
	}
}

void Tile::clicked(const sf::Event::MouseButtonPressed* event, std::shared_ptr<Piece>& held_piece)
{
	if (event->button == sf::Mouse::Button::Left)
	{
		if (piece != nullptr && held_piece == nullptr)
		{
			held_piece = piece;
			piece = nullptr;
			held_piece->getSprite().setPosition(sf::Vector2f(event->position));
			held_piece->setOrigin(coordinates);
		}
	}
}

bool Tile::dropPiece(std::shared_ptr<Piece> _piece)
{
	if (piece == nullptr)
	{
		piece = _piece;
		piece->getSprite().setPosition(this->getCentre());
		piece->setDestination(coordinates);
		return true;
	}
	else
	{
		return false;
	}
}

//Move the piece on this tile to another tile
void Tile::movePiece(Tile& _tile)
{
	if (piece != nullptr)
	{
		piece->setOrigin(coordinates);
		_tile.dropPiece(piece);
		piece = nullptr;
	}
}

sf::Vector2f Tile::getCentre()
{
	sf::FloatRect rectangle = shape.getGlobalBounds();
	sf::Vector2f centre = rectangle.position + (rectangle.size.componentWiseDiv({ 2,2 }));
	return centre;
}