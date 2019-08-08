# pragma once
# include <Siv3D.hpp>
# include <rnfs.h>

class EffectBomb : public Task {

private:
	Vec2 m_pos;
	double m_Radius;
	double m_maxRadius;
	int m_Alpha;

	TaskCall m_Update;

public:

	EffectBomb(Vec2 pos, double maxR);

private:
	void Swell();
	void Rupture();

};