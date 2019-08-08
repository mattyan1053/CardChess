# include "MoveMaxCntInc.hpp"
# include "Up1.hpp"

namespace Game {

	MoveMaxCntInc::MoveMaxCntInc() :Item(0) {
		cost = 3;
		itemName = L"�ő�ړ��\�񐔁{�P";
		desc = L"���̎������A�w��̖����R�}�̍ő�ړ��\��\n�����{�P����B";
		logStr = L"�R�}�̍ő�ړ��񐔂��P���₵�܂����B";
	}

	std::pair<int, String> MoveMaxCntInc::execute(Board &b, Point p, Turn t) {
		auto pc = b.b[p.y][p.x].getPiece();
		if (pc == nullptr) return std::make_pair(-1, L"");
		pc->movableNumMax++;
		Create<Up1>(b.b[p.y][p.x].r.center + Point(0, 0));
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