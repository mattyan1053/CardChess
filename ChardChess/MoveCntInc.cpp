# include "MoveCntInc.hpp"

namespace Game {

	MoveCntInc::MoveCntInc() :Item(0) {

	}

	int MoveCntInc::execute(Sqr& sq, Turn t) {
		auto p = sq.getPiece();
		if (p == nullptr) return -1;
		p->movableNum++;
		return cost;

	}

	void MoveCntInc::draw(Point pos) const {

		Item::draw(pos);
		FontAsset(L"ITEMNAME").draw(itemName, pos + Point(30, 20), Palette::Black);
		Item::drawAlpha(pos);

	}

	Array<Point> MoveCntInc::getTarget(Board &b, Turn t) {

		Array<Point> ret;
		for (int y = 0; y < b.b.size(); y++) {
			for (int x = 0; x < b.b[y].size(); x++) {
				auto p = b.b[y][x].getPiece();
				if (p != nullptr && p->owner == t) ret.push_back(Point(x, y));
			}
		}

		return ret;

	}

}