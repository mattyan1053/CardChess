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
		item,
		NonSelected
	};

	enum Items {
		moveCntInc,
		moveMaxCntInc,
		itemNum
	};

	static const Point sq_size = { 75, 75 };

}