# pragma once
# include <Siv3D.hpp>
# include <rnfs.h>

class EffectString : public Task {

private:
	Vec2 m_pos;
	int m_Alpha;

	String m_Str;

	double m_rate;

	TaskCall m_Update;

public:

	EffectString(Vec2 pos, String str);

private:
	void Swell();

};