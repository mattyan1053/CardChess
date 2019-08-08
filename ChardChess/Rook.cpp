# include "Rook.hpp"

namespace Game {

	Rook::Rook(Turn _owner) {
		owner = _owner;
		name = L"ÉãÅ[ÉN";
		if (owner == P1) {
			t = Texture(L"rook_white.png");
		}
		else {
			t = Texture(L"rook_black.png");
		}
	}

	Array<Point> Rook::getMovable(Point pos, const Board& bd) {
		Array<Point> ret;
		Piece *pc;
		const int N = 9;
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