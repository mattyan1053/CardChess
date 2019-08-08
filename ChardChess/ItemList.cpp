# include "ItemList.hpp"
# include "MoveCntInc.hpp"
# include "MoveMaxCntInc.hpp"

namespace Game {

	ItemList::ItemList() {

	}

	void ItemList::update() {



	}

	int ItemList::chkClk() {
		int ret = -1;
		for (int i = 0; i < items.size(); i++) {
			if (items[i]->isClicked(pos + innerPos + Point(0, 60) * i)) {
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
			items[i]->draw(pos + innerPos + Point(0, 60) * i);
		}

	}
	
	void ItemList::addItem() {
		if (items.size() > 7) return;
		auto r = Random<int>(itemNum - 1);
		switch (r) {
		case moveCntInc:
			items.push_back(new MoveCntInc());
			break;
		case moveMaxCntInc:
			items.push_back(new MoveMaxCntInc());
		default:
			break;
		}

	}

	std::pair<int, String> ItemList::execute(Board b, Point p, Turn t) {

		auto ret = items[selected]->execute(b, p, t);
		delete items[selected];
		items.erase(items.begin() + selected);
		selected = -1;
		return ret;

	}

	Item* ItemList::getItem() const {
		if (selected == -1) return nullptr;
		return items[selected];

	}

}