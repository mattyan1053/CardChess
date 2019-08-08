# pragma once
# include <Siv3D.hpp>

/// <summary>
/// ボタン用クラス
/// </summary>
class Button {

private:

	/// <summary>
	/// ボタンの矩形
	/// </summary>
	Rect m_button;

public:

	/// <summary>
	/// ボタンの位置
	/// </summary>
	Point pos;

	/// <summary>
	/// ボタンサイズ
	/// </summary>
	Size size;

	/// <summary>
	/// ボタンのテキスト
	/// </summary>
	String text;

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Button() = default;

	/// <summary>
	/// ボタン設定
	/// </summary>
	/// <param name="_pos">
	/// ボタンの位置
	/// </param>
	/// <param name="_size">
	/// ボタンサイズ
	/// </param>
	/// <param name="_text">
	/// ボタンのテキスト
	/// </param>
	void set(Point _pos, Size _size, String _text);

	/// <summary>
	/// ボタンの更新
	/// </summary>
	/// <returns>
	/// ボタンが押されていたら true 、押されていなければ false を返す
	/// </returns>
	bool update();

	/// <summary>
	/// ボタンの描画
	/// </summary>
	void draw() const;

};