#pragma once
# include <Siv3D.hpp>
# include "Item.hpp"
# include "Board.hpp"

namespace Game {

	struct Bomb : public Item {

		Bomb();

		std::pair<int, String> execute(Board &b, Point p, Turn t) override;

		void draw(Point pos) const override;

		Array<Point> getTarget(Board &b, Turn t) override;

	};

}