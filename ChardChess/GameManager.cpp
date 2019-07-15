# pragma once
# include "GameManager.hpp"
# include "Player.hpp"

namespace Game {

	void CommonData::drawBoard() const {

		b.draw();

	}

	void CommonData::makeFree() {
		const int N = 10;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				b.b[i][j].setHighlight(false);
			}
		}

		mode = Free;

	}

	void CommonData::PlayerDataReset(Turn t) {
		data[t].cost = data[t].maxCost;
	}

	void CommonData::movableCntReset(Turn t) {
		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				auto pc = b.b[y][x].getPiece();
				if (pc && pc->owner == t) {
					pc->movableNum = pc->movableNumMax;
				}
			}
		}
	}

	void GameManager::init() {

		manager.get()->changeBaseScene = [&](String state) {changeScene(state); };

		manager.add<Player>(P1);
		manager.add<Player>(P2);

	}

	void GameManager::update() {

		manager.update();

	}

	void GameManager::draw() const {

		manager.draw();

	}

}