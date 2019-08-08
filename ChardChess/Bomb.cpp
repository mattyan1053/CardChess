# include "Bomb.hpp"
# include "EffectBomb.hpp"

namespace Game {

	Bomb::Bomb() :Item(0) {
		cost = 4;
		itemName = L"自爆";
		desc = L"指定の味方コマを破壊する。周り8マスのコマも破壊する。";
		logStr = L"自爆しました。";
	}

	std::pair<int, String> Bomb::execute(Board &b, Point p, Turn t) {
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				int x = p.x + j, y = p.y + i;
				if (x < 1 || x > 8) continue;
				if (y < 1 || y > 8) continue;
				auto pc = b.b[y][x].getPiece();
				if (pc != nullptr) {
					delete pc;
					b.b[y][x].setPiece(nullptr);
				}
			}
		}
		Create<EffectBomb>(b.b[p.y][p.x].r.center, 100.0);
		return std::make_pair(cost, logStr);

	}

	void Bomb::draw(Point pos) const {

		Item::draw(pos);
		Item::drawAlpha(pos);

	}

	Array<Point> Bomb::getTarget(Board &b, Turn t) {

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