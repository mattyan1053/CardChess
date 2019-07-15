# include "Knight.hpp"

namespace Game {

	Knight::Knight(Turn _owner) {
		owner = _owner;
		if (owner == P1) {
			t = Texture(L"knight_white.png");
		}
		else {
			t = Texture(L"knight_black.png");
		}
	}

	Array<Point> Knight::getMovable(Point pos, const Board& bd) {
		Array<Point> ret;
		Piece *pc;
		if (pos.x + 1 <= 8 && pos.y + 2 <= 8 && pos.x >= 1 && pos.y >= 1) {
			pc = bd.b[pos.y + 2][pos.x + 1].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x + 1, pos.y + 2);
			}
		}
		if (pos.x + 2 <= 8 && pos.y + 1 <= 8 && pos.x >= 1 && pos.y >= 1) {
			pc = bd.b[pos.y + 1][pos.x + 2].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x + 2, pos.y + 1);
			}
		}
		if (pos.x + 2 <= 8 && pos.y <= 8 && pos.x >= 1 && pos.y - 1 >= 1) {
			pc = bd.b[pos.y - 1][pos.x + 2].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x + 2, pos.y - 1);
			}
		}
		if (pos.x + 1 <= 8 && pos.y <= 8 && pos.x >= 1 && pos.y - 2 >= 1) {
			pc = bd.b[pos.y - 2][pos.x + 1].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x + 1, pos.y - 2);
			}
		}
		if (pos.x <= 8 && pos.y <= 8 && pos.x - 1 >= 1 && pos.y - 2 >= 1) {
			pc = bd.b[pos.y - 2][pos.x - 1].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x - 1, pos.y - 2);
			}
		}
		if (pos.x <= 8 && pos.y <= 8 && pos.x - 2 >= 1 && pos.y - 1 >= 1) {
			pc = bd.b[pos.y - 1][pos.x - 2].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x - 2, pos.y - 1);
			}
		}
		if (pos.x <= 8 && pos.y + 1 <= 8 && pos.x - 2 >= 1 && pos.y >= 1) {
			pc = bd.b[pos.y + 1][pos.x - 2].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x - 2, pos.y + 1);
			}
		}
		if (pos.x <= 8 && pos.y + 2 <= 8 && pos.x - 1 >= 1 && pos.y >= 1) {
			pc = bd.b[pos.y + 2][pos.x - 1].getPiece();
			if (!pc || pc->owner != owner) {
				ret.emplace_back(pos.x - 1, pos.y + 2);
			}
		}
		return ret;
	}

}