# pragma once
# include <Siv3D.hpp>
# include "Sqr.hpp"

namespace Game {

	struct Board {

		Point pos;

		Array<Array<Sqr>> b;

		Board(Point _pos);

		void draw() const;

	};

}