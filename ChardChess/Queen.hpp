# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class Queen : public Piece {

	public:

		Queen(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}