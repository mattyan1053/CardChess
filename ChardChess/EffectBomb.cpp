# include "EffectBomb.hpp"

EffectBomb::EffectBomb(Vec2 pos, double maxR) : Task(), m_pos(pos), m_Radius(0.0), m_maxRadius(maxR),  m_Alpha(126), m_Update(this, &EffectBomb::Swell) {}

void EffectBomb::Swell() {

	m_Radius += 4.0;

	if (m_maxRadius <= m_Radius) m_Update.SetCall(&EffectBomb::Rupture);

	Circle(m_pos, m_Radius).draw(Color(255, 165, 0, m_Alpha));

}

void EffectBomb::Rupture() {

	m_Alpha -= 18;
	if (m_Alpha <= 0) this->Destroy();

	else Circle(m_pos, m_Radius).drawFrame(4.0, 4.0, Color(255, 165, 0, m_Alpha));

}