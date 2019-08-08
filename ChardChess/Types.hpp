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
		Pc, // ��
		item,
		NonSelected
	};

	static const Point sq_size = { 75, 75 };

}