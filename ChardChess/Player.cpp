# include "Player.hpp"
# include "Global.hpp"

namespace Game {

	void Player::init() {

		m_data->data[m_data->now].cost = ++m_data->data[m_data->now].maxCost;		
		m_data->PlayerDataReset(m_data->now);

	}

	void Player::update() {

		// �^�[���I���`�F�b�N
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

		// �I�����[�h
		if (m_data->mode == Free) {
			const int N = 9;
			for (int y = 1; y < N; y++) {
				for (int x = 1; x < N; x++) {
					if ((m_data->b).b[y][x].isClicked()) {
						auto pc = m_data->b.b[y][x].getPiece();
						// ��N���b�N���ꂽ�ꍇ
						if (pc) {
							m_data->sSqr = { x, y };
							m_data->mode = Selected;
							m_data->sItem = Pc;
							// �ړ��\�ꏊ��Ԃ�
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

		// ���샂�[�h
		if (m_data->mode == Selected) {
			switch (m_data->sItem) {
			case Pc: // �I�����ꂽ���̂���̂Ƃ�
				const int N = 9;
				for (int y = 1; y < N; y++) {
					for (int x = 1; x < N; x++) {
						if ((m_data->b).b[y][x].isClicked()) {
							if (m_data->b.b[y][x].getHighlight()) {
								auto dest_pc = m_data->b.b[y][x].getPiece();
								auto source_pc = m_data->b.b[m_data->sSqr.y][m_data->sSqr.x].getPiece();
								// ���������̋�łȂ���ΑI�����[�h�֖߂�
								if (source_pc->owner != m_data->now) {
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
								m_data->data[m_data->now].cost -= source_pc->moveCost;
								
								// ��̈ړ�
								m_data->b.b[y][x].setPiece(source_pc);
								m_data->b.b[m_data->sSqr.y][m_data->sSqr.x].setPiece(nullptr);
							}
						}
					}
				}
				break;
			}

			// �Ȃɂ��Ȃ��Ƃ��낪�N���b�N���ꂽ��I�����[�h�֖߂�
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