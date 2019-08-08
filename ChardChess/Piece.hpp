# pragma once
# include <Siv3D.hpp>
# include "Types.hpp"

namespace Game {

	struct Board;

	class Piece {
	public:
		Turn owner;
		bool selected = false;

		String name;

		Texture t;

		int movableNum = 1;
		int movableNumMax = 1;

		int moveCount = 0;

		int moveCost = 1;

		void setTexture(FilePath path);

		void draw(Point pos) const;

		virtual Array<Point> getMovable(Point pos, const Board &b) = 0;

	};

}