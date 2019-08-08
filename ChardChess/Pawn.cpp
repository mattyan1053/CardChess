# include "Pawn.hpp"

namespace Game {

	Pawn::Pawn(Turn _owner) {
		owner = _owner;
		name = L"É|Å[Éì";
		if (owner == P1) {
			t = Texture(L"pawn_white.png");
		}
		else {
			t = Texture(L"pawn_black.png");
		}
	}

	Array<Point> Pawn::getMovable(Point pos, const Board& bd) {
		Array<Point> ret;
		int diff = (owner == P1 ? 1 : -1);
		if (moveCount == 0 && bd.b[pos.y + diff * 2][pos.x].getPiece() == nullptr) {
			ret.emplace_back(pos.x, pos.y + diff * 2);
		}
		if (bd.b[pos.y + diff][pos.x].getPiece() == nullptr) {
			ret.emplace_back(pos.x, pos.y + diff);
		}
		Piece *pc = bd.b[pos.y + diff][pos.x - 1].getPiece();
		if (pc && pc->owner != owner) {
			ret.emplace_back(pos.x - 1, pos.y + diff);
		}
		pc = bd.b[pos.y + diff][pos.x + 1].getPiece();
		if (pc && pc->owner != owner) {
			ret.emplace_back(pos.x + 1, pos.y + diff);
		}
		return ret;
	}

}