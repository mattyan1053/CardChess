# pragma once
# include <Siv3D.hpp>
# include "Board.hpp"

namespace Game {

	struct Item {

		int cost = 1;

		String itemName;
		String desc;

		String logStr;

		const int id;
		bool clk = false;

		const Size size = {340, 100};

		Item(int _id);

		virtual std::pair<int, String> execute(Sqr &b, Turn t) = 0;

		virtual void draw(Point pos) const;
		void drawAlpha(Point pos) const;

		bool isClicked(Point pos);
		virtual Array<Point> getTarget(Board &b, Turn t) = 0;

	};

}