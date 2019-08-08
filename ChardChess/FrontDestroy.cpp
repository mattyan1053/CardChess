# include "FrontDestroy.hpp"
# include "EffectBomb.hpp"

namespace Game {

	FrontDestroy::FrontDestroy() :Item(0) {
		cost = 2;
		itemName = L"破壊";
		desc = L"指定の味方コマの前にあるコマを破壊する。";
		logStr = L"破壊しました。";
	}

	std::pair<int, String> FrontDestroy::execute(Board &b, Point p, Turn t) {
		auto pc = b.b[p.y][p.x].getPiece();
		delete pc;
		b.b[p.y][p.x].setPiece(nullptr);
		Create<EffectBomb>(b.b[p.y][p.x].r.center, 40.0);
		return std::make_pair(cost, logStr);

	}

	void FrontDestroy::draw(Point pos) const {

		Item::draw(pos);
		Item::drawAlpha(pos);

	}

	Array<Point> FrontDestroy::getTarget(Board &b, Turn t) {
		int diff = (t == P1 ? 1 : -1);
		Array<Point> ret;
		for (int y = 0; y < b.b.size(); y++) {
			for (int x = 0; x < b.b[y].size(); x++) {
				auto p = b.b[y][x].getPiece();
				if (p != nullptr && p->owner == t) {
					int pos = y + diff;
					if (pos < 1 || pos > 8) continue;
					auto p2 = b.b[pos][x].getPiece();
					if (p2 != nullptr) ret.push_back(Point(x, pos));
				}
			}
		}

		return ret;

	}

}