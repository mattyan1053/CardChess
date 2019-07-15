# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class Bishop : public Piece {

	public:

		Bishop(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}