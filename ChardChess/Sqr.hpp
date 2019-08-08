# pragma once
# include <Siv3D.hpp>
# include "Piece.hpp"
# include "Types.hpp"
namespace Game {

	class Piece;

	class Sqr {
	private:

		Point pos;
		Point s_pos;
		bool hl; // ハイライト

		Piece *p;

	
	public:
		Rect r;

		Sqr(Point _pos, Point _s_pos);

		void setPiece(Piece *_p);

		Piece *getPiece() const;

		void setHighlight(bool flag);

		bool getHighlight() {
			return hl;
		}

		bool isClicked() {
			return r.leftClicked;
		}

		void draw() const;

	};

}