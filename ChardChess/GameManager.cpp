# pragma once
# include "GameManager.hpp"
# include "Player.hpp"

namespace Game {

	void CommonData::drawBoard() const {

		b.draw();

	}

	void CommonData::drawItems() const {

		data[now].sp.draw(now);

	}

	bool CommonData::chkBdClk() {

		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				if (b.b[y][x].isClicked()) {
					auto pc = b.b[y][x].getPiece();
					// 駒がクリックされた場合
					if (pc) {
						sSqr = { x, y };
						mode = Selected;
						sItem = Pc;
						// 移動可能場所を赤く
						auto list = pc->getMovable({ x, y }, b);
						for (int i = 0; i < list.size(); i++) {
							b.b[list[i].y][list[i].x].setHighlight(true);
						}
						return true;
					}
				}
			}
		}
		return false;
	}

	bool CommonData::chkItmClk() {

		auto &sp = data[now].sp;
		auto id = sp.chkClk();
		if (id == -1) return false;
		mode = Selected;
		sItem = item;
		auto &items = sp.items;
		auto list = items[id]->getTarget(b, now);
		for (int i = 0; i < list.size(); i++) {
			b.b[list[i].y][list[i].x].setHighlight(true);
		}
		return true;

	}

	void CommonData::makeFree() {
		int N = 10;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				b.b[i][j].setHighlight(false);
			}
		}
		N = data[now].sp.items.size();
		for (int i = 0; i < N; i++) {
			data[now].sp.items[i]->clk = false;
		}
		mode = Free;

	}

	void CommonData::movePiece() {
		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				if (b.b[y][x].isClicked()) {
					if (b.b[y][x].getHighlight()) {
						auto dest_pc = b.b[y][x].getPiece();
						auto source_pc = b.b[sSqr.y][sSqr.x].getPiece();
						// 操作駒が自分の駒でなければ選択モードへ戻る
						if (source_pc->owner != now) {
							break;
						}
						// 選択駒の残り移動回数が０であれば選択モードへ戻る
						if (source_pc->movableNum <= 0) break;
						// 移動先に敵の駒があれば消去
						if (dest_pc != nullptr) {
							delete dest_pc;
						}
						// 移動させる駒の総移動回数を＋１
						source_pc->moveCount++;
						// 移動させる駒の残り移動回数－１
						source_pc->movableNum--;

						// コスト計算
						data[now].cost -= source_pc->moveCost;

						// 駒の移動
						b.b[y][x].setPiece(source_pc);
						b.b[sSqr.y][sSqr.x].setPiece(nullptr);
					}
				}
			}
		}
	}

	void CommonData::useItem() {

		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				if (b.b[y][x].isClicked()) {
					if (b.b[y][x].getHighlight()) {
						auto p = b.b[y][x];
						auto c = data[now].sp.execute(p, now);
						data[now].cost -= c;
					}
				}
			}
		}

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