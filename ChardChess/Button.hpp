# pragma once
# include <Siv3D.hpp>

/// <summary>
/// �{�^���p�N���X
/// </summary>
class Button {

private:

	/// <summary>
	/// �{�^���̋�`
	/// </summary>
	Rect m_button;

public:

	/// <summary>
	/// �{�^���̈ʒu
	/// </summary>
	Point pos;

	/// <summary>
	/// �{�^���T�C�Y
	/// </summary>
	Size size;

	/// <summary>
	/// �{�^���̃e�L�X�g
	/// </summary>
	String text;

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Button() = default;

	/// <summary>
	/// �{�^���ݒ�
	/// </summary>
	/// <param name="_pos">
	/// �{�^���̈ʒu
	/// </param>
	/// <param name="_size">
	/// �{�^���T�C�Y
	/// </param>
	/// <param name="_text">
	/// �{�^���̃e�L�X�g
	/// </param>
	void set(Point _pos, Size _size, String _text);

	/// <summary>
	/// �{�^���̍X�V
	/// </summary>
	/// <returns>
	/// �{�^����������Ă����� true �A������Ă��Ȃ���� false ��Ԃ�
	/// </returns>
	bool update();

	/// <summary>
	/// �{�^���̕`��
	/// </summary>
	void draw() const;

};