#pragma once
# include <Siv3D.hpp>
# include "Item.hpp"
# include "Board.hpp"

namespace Game {

	struct MoveCntInc : public Item {

		MoveCntInc();

		std::pair<int, String> execute(Sqr& sq, Turn t) override;

		void draw(Point pos) const override;

		Array<Point> getTarget(Board &b, Turn t) override;

	};

}