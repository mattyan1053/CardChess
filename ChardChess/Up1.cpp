# include "Up1.hpp"

Up1::Up1(Vec2 pos) : Task(), m_pos(pos), m_Alpha(0), t(0), m_Update(this, &Up1::Swell) {}

void Up1::Swell() {

	if (t < 20) m_Alpha += 18;
	else m_Alpha -= 18;
	m_Alpha = Min(m_Alpha, 255);
	t += 0.5;

	if (m_Alpha < 0) this->Destroy();

	else FontAsset(L"UP1")(L"1UP").draw(m_pos - Point(0, Min(t, 30.0)), Color(0, 0, 0, m_Alpha));

}