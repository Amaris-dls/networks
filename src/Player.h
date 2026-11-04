#pragma once
#include <memory>
#include "Piece.h"

class Player
{
	public:
		Player(int id, std::vector<std::shared_ptr<Piece>> _pieces = {});
		~Player();
		int getID() { return player_id; }
		void addPiece(std::shared_ptr<Piece> _piece);
		void addPieces(std::vector<std::shared_ptr<Piece>> _pieces);
		bool removePiece(std::shared_ptr<Piece> _piece);
		std::vector<std::shared_ptr<Piece>>& getPieces() { return pieces; }

	private:
		int player_id;
		std::vector<std::shared_ptr<Piece>> pieces;
};