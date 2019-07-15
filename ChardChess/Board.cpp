# include "Board.hpp"
# include "Pawn.hpp"
# include "Rook.hpp"
# include "Knight.hpp"
# include "Bishop.hpp"
# include "Queen.hpp"
# include "King.hpp"

namespace Game {

	Board::Board(Point _pos): pos(_pos) {

		const int N = 10;
		for (int y = 0; y < N; y++) {
			Array<Sqr> tmp;
			for (int x = 0; x < N; x++) {
				tmp.emplace_back(Point(x, y), pos);
			}
			b.push_back(tmp);
		}

		for (int i = 1; i <= 8; i++) {
			b[2][i].setPiece(new Pawn(P1));
			b[7][i].setPiece(new Pawn(P2));
		}
		b[1][1].setPiece(new Rook(P1));
		b[1][2].setPiece(new Knight(P1));
		b[1][3].setPiece(new Bishop(P1));
		b[1][4].setPiece(new Queen(P1));
		b[1][5].setPiece(new King(P1));
		b[1][6].setPiece(new Bishop(P1));
		b[1][7].setPiece(new Knight(P1));
		b[1][8].setPiece(new Rook(P1));

		b[8][1].setPiece(new Rook(P2));
		b[8][2].setPiece(new Knight(P2));
		b[8][3].setPiece(new Bishop(P2));
		b[8][4].setPiece(new Queen(P2));
		b[8][5].setPiece(new King(P2));
		b[8][6].setPiece(new Bishop(P2));
		b[8][7].setPiece(new Knight(P2));
		b[8][8].setPiece(new Rook(P2));

	}

	void Board::draw() const {
		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				b[y][x].draw();
			}
		}

	}

}