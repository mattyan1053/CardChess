# include "Item.hpp"

namespace Game {

	Item::Item(int _id):id(_id) {

		

	}

	bool Item::isClicked(Point pos) {

		return clk = Rect(pos, size).leftClicked;

	}

	void Item::draw(Point pos) const {

		Rect(pos, size).draw(Palette::Blue);
		Rect(pos + Point(5, 5), size - Size(10, 10)).draw(Palette::White);

	}

	void Item::drawAlpha(Point pos) const {

		if (clk) {
			Rect(pos, size).draw(Color(0, 0, 255, 50));
		}

	}

}