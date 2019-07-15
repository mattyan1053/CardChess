# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class Pawn : public Piece {

	public:

		Pawn(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}