# include "Player.hpp"
# include "Global.hpp"

namespace Game {

	void Player::init() {

		b.set(Point(500, 20), Size(200, 50), L"�^�[���I��");
		if (m_data->now == P1) m_data->logStr.push_back(Format(L"�^�[��", ++m_data->turn));
		m_data->logStr.push_back(Format(m_data->now == P1 ? L"��" : L"��", L"�̃^�[��"));

		m_data->data[m_data->now].cost = ++m_data->data[m_data->now].maxCost;		
		m_data->PlayerDataReset(m_data->now);

	}

	void Player::update() {

		//�����I���`�F�b�N
		if (m_data->chkFin()) {
			m_data->changeBaseScene(L"Result");
		}

		// �^�[���I��
		if (b.update()) {
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
			return;
		}

		// �I�����[�h
		if (m_data->mode == Free) {
			// ��̃N���b�N�`�F�b�N
			if (m_data->chkBdClk()) return;
			// �A�C�e���̃N���b�N�`�F�b�N
			if (m_data->chkItmClk()) return;
		}

		// ���샂�[�h
		if (m_data->mode == Selected) {
			switch (m_data->sItem) {
			case Pc: // �I�����ꂽ���̂���̂Ƃ�
				m_data->movePiece();
				break;
			case item:
				m_data->useItem();
				break;
			}

			// �N���b�N���ꂽ��I�����[�h�֖߂�
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

		FontAsset(L"LARGE")((m_data->now == P1 ? L"��" : L"��")).draw(20, 0);

	}

}