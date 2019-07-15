# pragma once

namespace Game {

	enum Turn {
		P1,
		P2,
		PlayerNum
	};

	enum Mode {
		Free,
		Selected,
		Moving
	};

	enum SelectedItem {
		Pc, // ‹î
		card,
		NonSelected
	};

	static const Point sq_size = { 75, 75 };

}