# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class Rook : public Piece {

	public:

		Rook(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}