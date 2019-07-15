# include "Sqr.hpp"

namespace Game {

	Sqr::Sqr(Point _pos, Point _s_pos) :pos(_pos), s_pos(_s_pos), hl(false), p(nullptr) {
		r = Rect(s_pos.x + (pos.x - 1) * sq_size.x, s_pos.y - pos.y * sq_size.y, sq_size);
	}

	void Sqr::setPiece(Piece *_p) {

		p = _p;

	}

	Piece *Sqr::getPiece() const{
		return p;
	}

	void Sqr::setHighlight(bool flag) {
		hl = flag;
		return;
	}

	void Sqr::draw() const {

		if ((pos.x + pos.y) % 2) {
			r.draw(Palette::White);
		}
		else {
			r.draw(Palette::Darkolivegreen);
		}

		if (p != nullptr) {
			p->draw(r.pos);
		}

		if (hl) {
			r.draw(Color(255, 0, 0, 50));
		}

	}

}