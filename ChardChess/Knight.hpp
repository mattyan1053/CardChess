# pragma once
# include "Piece.hpp"
# include "Board.hpp"

namespace Game {

	class Knight : public Piece {

	public:

		Knight(Turn _owner);

		Array<Point> getMovable(Point pos, const Board& b);

	};

}