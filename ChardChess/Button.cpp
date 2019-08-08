# pragma once
# include <Siv3D.hpp>
# include "Button.hpp"

void Button::set(Point _pos, Size _size, String _text) {
	pos = _pos;
	size = _size;
	text = _text;
	m_button.set(pos, size);
}

bool Button::update() {

	return m_button.leftClicked;
}

void Button::draw() const {

	RoundRect(m_button, 10).drawShadow({ 1,1 }, 1, 1);
	RoundRect(m_button, 10).draw(m_button.mouseOver ? Palette::Lightslategray : Palette::White).drawFrame(1, 0, Palette::Black);

	FontAsset(L"button")(text).drawCenter(m_button.center, Palette::Black);
}