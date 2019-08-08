#pragma once
# include <Siv3D.hpp>
# include "Item.hpp"
# include "Board.hpp"

namespace Game {

	struct MoveCntInc : public Item {

		const String itemName = L"移動可能回数＋１";
		const String desc = L"このターン中、指定の味方コマの移動可能回数を＋１する。";

		int cost = 1;

		MoveCntInc();

		int execute(Sqr& sq, Turn t) override;

		void draw(Point pos) const override;

		Array<Point> getTarget(Board &b, Turn t) override;

	};

}