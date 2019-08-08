# include "Item.hpp"

namespace Game {

	Item::Item(int _id):id(_id) {

		

	}

	bool Item::isClicked(Point pos) {

		return clk = Rect(pos, size).leftClicked;

	}

	void Item::draw(Point pos) const {

		Rect(pos, size).draw(Palette::Lightblue);
		Rect(pos + Point(5, 5), size - Size(10, 10)).draw(Palette::White);
		Circle(pos + Point(30, 30), 20).draw(Palette::Lightgreen);
		FontAsset(L"COST")(cost).drawCenter(pos + Point(30, 30), Palette::White);
		FontAsset(L"ITEMNAME").draw(itemName, pos + Point(80, 10), Palette::Black);

	}

	void Item::drawAlpha(Point pos) const {

		if (clk) {
			Rect(pos, size).draw(Color(0, 0, 255, 50));
		}

	}

}