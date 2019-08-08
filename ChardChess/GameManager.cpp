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

	void CommonData::drawInfo() const {

		FontAsset(L"COST").draw(Format(data[now].cost, L"/", data[now].maxCost), { 150, 30 }, Palette::White);

	}

	void CommonData::drawSelectedInfo() const {

		Rect(800, 30, 400, 150).draw();
		Rect(805, 35, 390, 140).draw(Palette::Black);

		if (mode == Selected) {

			switch (sItem) {

			case Pc:
				{
					auto p = b.b[sSqr.y][sSqr.x].getPiece();
					FontAsset(L"INFOTITLE")(p->name).draw({ 815, 40 }, Palette::White);
					FontAsset(L"INFO")(L"�c��ړ��\��: ", p->movableNum).draw({ 815, 70 }, Palette::White);
					FontAsset(L"INFO")(L"�K�v�R�X�g: ", p->moveCost).draw({ 815, 100 }, Palette::White);
				}
				break;
				
			case item:
				{
					auto item = data[now].sp.getItem();
					FontAsset(L"INFOTITLE")(item->itemName).draw({ 815, 40 }, Palette::White);
					FontAsset(L"INFO")(item->desc).draw({ 815, 70 }, Palette::White);
					FontAsset(L"INFO")(L"�K�v�R�X�g: ", item->cost).draw({815, 145});
				}
				break;

			default:
				break;

			}

		}

	}

	void CommonData::drawLog() const {

		Rect(140, 720, 600, 150).draw();
		Rect(145, 725, 590, 140).draw(Palette::Black);
		const int N = logStr.size();
		for (int i = 0; i < Min(N, 8); i++) {
			FontAsset(L"LOG")(logStr[Max(0, N - 8) + i]).draw({ 155, 735 + 15 * i });
		}

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
						if (source_pc->movableNum <= 0) {
							logStr.push_back(L"���̋�͂���ȏ�ړ��ł��܂���B");
							break;
						}
						// �I����̈ړ��ɕK�v�ȃR�X�g���c���Ă��Ȃ���Ζ߂�
						if (data[now].cost < source_pc->moveCost) {
							logStr.push_back(L"�ړ��ɕK�v�ȃR�X�g������܂���B");
							break;
						}

						String logstr = (now == P1 ? L"��" : L"��") + source_pc->name + L": " + ('a' - 1 + sSqr.x) + ('1' - 1 + sSqr.y) + L"��" + ('a' - 1 + x) + ('1' - 1 + y);

						// �ړ���ɓG�̋����Ώ���
						if (dest_pc != nullptr) {
							logstr += L" ";
							logstr += (now == P1 ? L"��" : L"��") + (dest_pc->name) + L"�����܂���";
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

						// ���O�̒ǉ�
						logStr.push_back(logstr);

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
						if (data[now].cost < data[now].sp.getCost()) {
							logStr.push_back(L"�R�X�g������܂���B");
							continue;
						}
						auto c = data[now].sp.execute(p, now);
						data[now].cost -= c.first;
						logStr.push_back(c.second);
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

	bool CommonData::chkFin() {

		bool kFlag[PlayerNum] = {false, false};
		const int N = 9;
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				auto pc = b.b[y][x].getPiece();
				if (pc && pc->name == L"�L���O") {
					kFlag[pc->owner] = true;
				}
			}
		}

		if (kFlag[P1] == false) {
			*winner = P2;
			return true;
		}
		if (kFlag[P2] == false) {
			*winner = P1;
			return true;
		}

		return false;

	}

	void GameManager::init() {

		manager.get()->changeBaseScene = [&](String state) {changeScene(state); };
		manager.get()->winner = &m_data->winner;

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