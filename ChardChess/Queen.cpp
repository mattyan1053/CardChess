# include "Queen.hpp"

namespace Game {

	Queen::Queen(Turn _owner) {
		owner = _owner;
		name = L"ÉNÉCÅ[Éì";
		if (owner == P1) {
			t = Texture(L"/1015");
		}
		else {
			t = Texture(L"/1025");
		}
	}

	Array<Point> Queen::getMovable(Point pos, const Board& bd) {
		Array<Point> ret;
		Piece *pc;
		const int N = 9;
		for (int i = 1; pos.x + i < N && pos.y + i < N; i++) {
			pc = bd.b[pos.y + i][pos.x + i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x + i, pos.y + i);
					break;
				}
			}
			ret.emplace_back(pos.x + i, pos.y + i);
		}
		for (int i = 1; pos.x + i < N && pos.y - i >= 1; i++) {
			pc = bd.b[pos.y - i][pos.x + i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x + i, pos.y - i);
					break;
				}
			}
			ret.emplace_back(pos.x + i, pos.y - i);
		}
		for (int i = 1; pos.x - i >= 1 && pos.y + i < N; i++) {
			pc = bd.b[pos.y + i][pos.x - i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x - i, pos.y + i);
					break;
				}
			}
			ret.emplace_back(pos.x - i, pos.y + i);
		}
		for (int i = 1; pos.x - i >= 1 && pos.y - i >= 1; i++) {
			pc = bd.b[pos.y - i][pos.x - i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x - i, pos.y - i);
					break;
				}
			}
			ret.emplace_back(pos.x - i, pos.y - i);
		}
		for (int i = pos.y + 1; i < N; i++) {
			pc = bd.b[i][pos.x].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x, i);
					break;
				}
			}
			ret.emplace_back(pos.x, i);
		}
		for (int i = pos.y - 1; i >= 1; i--) {
			pc = bd.b[i][pos.x].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(pos.x, i);
					break;
				}
			}
			ret.emplace_back(pos.x, i);
		}
		for (int i = pos.x + 1; i < N; i++) {
			pc = bd.b[pos.y][i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(i, pos.y);
					break;
				}
			}
			ret.emplace_back(i, pos.y);
		}
		for (int i = pos.x - 1; i >= 1; i--) {
			pc = bd.b[pos.y][i].getPiece();
			if (pc) {
				if (pc->owner == owner) break;
				else {
					ret.emplace_back(i, pos.y);
					break;
				}
			}
			ret.emplace_back(i, pos.y);
		}
		return ret;
	}

}