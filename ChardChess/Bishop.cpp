# include "Bishop.hpp"

namespace Game {

	Bishop::Bishop(Turn _owner) {
		owner = _owner;
		name = L"ビショップ";
		if (owner == P1) {
			t = Texture(L"bishop_white.png");
		}
		else {
			t = Texture(L"bishop_black.png");
		}
	}

	Array<Point> Bishop::getMovable(Point pos, const Board& bd) {
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
		return ret;
	}

}