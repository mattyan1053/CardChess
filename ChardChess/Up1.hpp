# pragma once
# include <Siv3D.hpp>
# include <rnfs.h>

class Up1 : public Task {

private:
	Vec2 m_pos;
	int m_Alpha;

	double t;

	TaskCall m_Update;

public:

	Up1(Vec2 pos);

private:
	void Swell();

};