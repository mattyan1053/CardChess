# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class King : public Piece {

	public:

		King(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}