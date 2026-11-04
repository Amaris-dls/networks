#include "Piece.h"

Piece::Piece(const sf::Texture& texture, int _player, sf::Vector2f size_target, sf::Vector2f centre) : sprite(texture)
{
	player = _player;
	
	sprite.setOrigin(centre); //Sprite origin is relative to the original sprite size, will update with scale

	if(size_target != sf::Vector2f(0, 0))
	{
		sf::Vector2f current_size = sprite.getGlobalBounds().size;
		sf::Vector2f scale_factor = size_target.componentWiseDiv(current_size);
		sprite.scale(scale_factor);
	}
	
}

Piece::~Piece()
{

}

