# include "Player.hpp"
# include "Global.hpp"

namespace Game {

	void Player::init() {

		m_data->data[m_data->now].cost = ++m_data->data[m_data->now].maxCost;		
		m_data->PlayerDataReset(m_data->now);

	}

	void Player::update() {

		// ターン終了チェック
		if (checkTurnEnd()) {
			m_data->movableCntReset(m_data->now);
			if (m_data->next == P1) {
				m_data->now = P1;
				m_data->next = P2;
			}
			else {
				m_data->now = P2;
				m_data->next = P1;
			}
			changeScene(m_data->now);
		}

		// 選択モード
		if (m_data->mode == Free) {
			const int N = 9;
			for (int y = 1; y < N; y++) {
				for (int x = 1; x < N; x++) {
					if ((m_data->b).b[y][x].isClicked()) {
						auto pc = m_data->b.b[y][x].getPiece();
						// 駒がクリックされた場合
						if (pc) {
							m_data->sSqr = { x, y };
							m_data->mode = Selected;
							m_data->sItem = Pc;
							// 移動可能場所を赤く
							auto list = pc->getMovable({ x, y }, m_data->b);
							for (int i = 0; i < list.size(); i++) {
								(m_data->b).b[list[i].y][list[i].x].setHighlight(true);
							}
							return;
						}
					}
				}
			}
		}

		// 動作モード
		if (m_data->mode == Selected) {
			switch (m_data->sItem) {
			case Pc: // 選択されたものが駒のとき
				const int N = 9;
				for (int y = 1; y < N; y++) {
					for (int x = 1; x < N; x++) {
						if ((m_data->b).b[y][x].isClicked()) {
							if (m_data->b.b[y][x].getHighlight()) {
								auto dest_pc = m_data->b.b[y][x].getPiece();
								auto source_pc = m_data->b.b[m_data->sSqr.y][m_data->sSqr.x].getPiece();
								// 操作駒が自分の駒でなければ選択モードへ戻る
								if (source_pc->owner != m_data->now) {
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
								m_data->data[m_data->now].cost -= source_pc->moveCost;
								
								// 駒の移動
								m_data->b.b[y][x].setPiece(source_pc);
								m_data->b.b[m_data->sSqr.y][m_data->sSqr.x].setPiece(nullptr);
							}
						}
					}
				}
				break;
			}

			// なにもないところがクリックされたら選択モードへ戻る
			if (Input::MouseL.clicked) {
				m_data->mode = Free;
				m_data->sItem = NonSelected;
				m_data->makeFree();
			}
		}

		if (Input::MouseR.clicked) {
			m_data->changeBaseScene(L"Title");
		}

		return;

	}

	void Player::draw() const {

		m_data->drawBoard();
		FontAsset(L"LARGE")((m_data->now == P1 ? L"1P" : L"2P")).draw(0, 0);

	}

	bool Player::checkTurnEnd() {
		if (m_data->data[m_data->now].cost <= 0) return true;
		return false;
	}

}