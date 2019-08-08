# include "Player.hpp"
# include "Global.hpp"
# include "EffectString.hpp"

namespace Game {

	void Player::init() {

		b.set(Point(500, 20), Size(200, 50), L"ターン終了");
		if (m_data->now == P1) m_data->logStr.push_back(Format(L"ターン", ++m_data->turn));
		m_data->logStr.push_back(Format(m_data->now == P1 ? L"白" : L"黒", L"のターン"));
		
		if (m_data->now == P1) Create<EffectString>(Window::Center(), L"White Turn");
		else Create<EffectString>(Window::Center(), L"Black Turn");

		m_data->data[m_data->now].sp.addItem();

		m_data->data[m_data->now].cost = ++m_data->data[m_data->now].maxCost;		
		m_data->PlayerDataReset(m_data->now);


	}

	void Player::update() {

		//試合終了チェック
		if (m_data->chkFin()) {
			m_data->changeBaseScene(L"Result");
		}

		// ターン終了
		if (b.update()) {
			m_data->mode = Free;
			m_data->sItem = NonSelected;
			m_data->makeFree();
			m_data->movableCntReset(m_data->now);
			std::swap(m_data->now, m_data->next);
			changeScene(m_data->now);
			return;
		}

		// 選択モード
		if (m_data->mode == Free) {
			// 駒のクリックチェック
			if (m_data->chkBdClk()) return;
			// アイテムのクリックチェック
			if (m_data->chkItmClk()) return;
		}

		// 動作モード
		if (m_data->mode == Selected) {
			switch (m_data->sItem) {
			case Pc: // 選択されたものが駒のとき
				m_data->movePiece();
				break;
			case item:
				m_data->useItem();
				break;
			}

			// クリックされたら選択モードへ戻る
			if (Input::MouseL.clicked) {
				m_data->mode = Free;
				m_data->sItem = NonSelected;
				m_data->makeFree();
			}
		}

		return;

	}

	void Player::draw() const {

		b.draw();

		m_data->drawBoard();
		m_data->drawItems();
		m_data->drawInfo();
		m_data->drawSelectedInfo();
		m_data->drawLog();

		FontAsset(L"LARGE")((m_data->now == P1 ? L"白" : L"黒")).draw(20, 0);

	}

}