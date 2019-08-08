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
					// ��N���b�N���ꂽ�ꍇ
					if (pc) {
						sSqr = { x, y };
						mode = Selected;
						sItem = Pc;
						// �ړ��\�ꏊ��Ԃ�
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
						// ���������̋�łȂ���ΑI�����[�h�֖߂�
						if (source_pc->owner != now) {
							break;
						}
						// �I����̎c��ړ��񐔂��O�ł���ΑI�����[�h�֖߂�
						if (source_pc->movableNum <= 0) break;
						// �ړ���ɓG�̋����Ώ���
						if (dest_pc != nullptr) {
							delete dest_pc;
						}
						// �ړ��������̑��ړ��񐔂��{�P
						source_pc->moveCount++;
						// �ړ��������̎c��ړ��񐔁|�P
						source_pc->movableNum--;

						// �R�X�g�v�Z
						data[now].cost -= source_pc->moveCost;

						// ��̈ړ�
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