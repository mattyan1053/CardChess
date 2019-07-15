# include "Piece.hpp"

namespace Game {

	void Piece::setTexture(FilePath path) {
		t = Texture(path);
	}

	void Piece::draw(Point pos) const {
		t.resize(sq_size).draw(pos);
	}

}