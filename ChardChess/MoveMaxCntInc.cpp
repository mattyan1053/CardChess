# include "MoveMaxCntInc.hpp"

namespace Game {

	MoveMaxCntInc::MoveMaxCntInc() :Item(0) {
		cost = 3;
		itemName = L"最大移動可能回数＋１";
		desc = L"この試合中、指定の味方コマの最大移動可能回数\nを＋１する。";
		logStr = L"コマの最大移動回数を１増やしました。";
	}

	std::pair<int, String> MoveMaxCntInc::execute(Board b, Point p, Turn t) {
		auto pc = b.b[p.y][p.x].getPiece();
		if (pc == nullptr) return std::make_pair(-1, L"");
		pc->movableNumMax++;
		return std::make_pair(cost, logStr);

	}

	void MoveMaxCntInc::draw(Point pos) const {

		Item::draw(pos);
		Item::drawAlpha(pos);

	}

	Array<Point> MoveMaxCntInc::getTarget(Board &b, Turn t) {

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