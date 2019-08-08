#pragma once
# include <Siv3D.hpp>
# include "Item.hpp"
# include "Board.hpp"

namespace Game {

	struct MoveCntInc : public Item {

		const String itemName = L"�ړ��\�񐔁{�P";
		const String desc = L"���̃^�[�����A�w��̖����R�}�̈ړ��\�񐔂��{�P����B";

		int cost = 1;

		MoveCntInc();

		int execute(Sqr& sq, Turn t) override;

		void draw(Point pos) const override;

		Array<Point> getTarget(Board &b, Turn t) override;

	};

}