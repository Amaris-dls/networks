#include "Player.h"

Player::Player(int id, std::vector<std::shared_ptr<Piece>> _pieces)
	: player_id(id), pieces(_pieces)
{
	
}

Player::~Player(){}

void Player::addPiece(std::shared_ptr<Piece> _piece)
{
	pieces.push_back(_piece);
}

void Player::addPieces(std::vector<std::shared_ptr<Piece>> _pieces)
{
	if (!_pieces.empty())
	{
		pieces.reserve(pieces.size() + _pieces.size());
		pieces.insert(pieces.end(), _pieces.begin(), _pieces.end());
	}
}

bool Player::removePiece(std::shared_ptr<Piece> delete_piece)
{
	std::vector<std::shared_ptr<Piece>>::iterator it = pieces.begin();
	bool found = false;
	for (; it != pieces.end(); it++)
	{
		if (it->get() == delete_piece.get())
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		pieces.erase(it);
		return true;
	}	

	return false;
}

