# include "EffectString.hpp"

EffectString::EffectString(Vec2 pos, String str) : Task(), m_pos(pos), m_Alpha(0),m_Str(str),  m_rate(1.0), m_Update(this, &EffectString::Swell) {}

void EffectString::Swell() {

	if (m_rate < 3) m_Alpha += 18;
	else m_Alpha -= 18;
	m_Alpha = Min(m_Alpha, 255);
	m_rate += 0.05;

	if (m_Alpha < 0) this->Destroy();

	else {
		const Mat3x2 mat = Mat3x2::Scale(m_rate, m_pos);
		{
			const Transformer2D transformer(mat, true);
			FontAsset(L"LARGE")(m_Str).drawCenter(m_pos, Color(255, 255, 255, m_Alpha));
		}
	}
}