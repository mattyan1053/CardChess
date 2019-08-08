# include "King.hpp"

namespace Game {

	King::King(Turn _owner) {
		owner = _owner;
		name = L"ƒLƒ“ƒO";
		if (owner == P1) {
			t = Texture(L"/1012");
		}
		else {
			t = Texture(L"/1022");
		}
	}

	Array<Point> King::getMovable(Point pos, const Board& bd) {
		Array<Point> ret;
		Piece *pc;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;
				pc = bd.b[pos.y + i][pos.x + j].getPiece();
				if (pc) {
					if (pc->owner == owner) continue;
					else {
						ret.emplace_back(pos.x + j, pos.y + i);
						break;
					}
				}
				ret.emplace_back(pos.x + j, pos.y + i);
			}
		}
		return ret;
	}

}