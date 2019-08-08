# pragma once
# include <Siv3D.hpp>
# include "Item.hpp"
# include "Types.hpp"

namespace Game {

	struct ItemList {

		int selected = -1;

		const Point pos = { 800, 200 };
		const Point innerPos = { 10, 70 };
		const Size size = { 360, 640 };
		const Size innnerSize = { 340, 500 };

		Array<Item*> items;

		ItemList();

		void update();

		int chkClk();

		void draw(Turn t) const;
		void drawItems() const;

		void addItem();

		int execute(Sqr& sq, Turn t);

	};

}