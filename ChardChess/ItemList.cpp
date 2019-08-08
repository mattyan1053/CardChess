# include "ItemList.hpp"
# include "MoveCntInc.hpp"

namespace Game {

	ItemList::ItemList() {

		items.push_back(new MoveCntInc());

	}

	void ItemList::update() {



	}

	int ItemList::chkClk() {
		int ret = -1;
		for (int i = 0; i < items.size(); i++) {
			if (items[i]->isClicked(pos + innerPos + Point(0, 100) * i)) {
				ret = i;
			}
		}
		return selected = ret;
	}

	void ItemList::draw(Turn t) const{

		RoundRect(pos, size, 30).draw(t == P1 ? Palette::White : Palette::Black);
		Rect(pos + innerPos, innnerSize).draw(Palette::Gray);
		Line(pos + Point(130, 33), pos + Point(230, 33)).draw(5, Palette::Darkgray);
		Circle(pos + Point(97.5, 35), 2.5).draw(Palette::Darkgray);
		Circle(pos + Point(size.x / 2, size.y - 35), 20).drawFrame(1, 0, Palette::Darkgray);

		drawItems();

	}

	void ItemList::drawItems() const {

		for (int i = 0; i < items.size(); i++) {
			items[i]->draw(pos + innerPos + Point(0, 100) * i);
		}

	}
	
	void ItemList::addItem() {



	}

	int ItemList::execute(Sqr& sq, Turn t) {
		auto ret = items[selected]->execute(sq, t);
		selected = -1;
		return ret;

	}

}