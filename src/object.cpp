#include "object.hpp"

Object::Object( int x, int y )
{
	m_body.x = x;
	m_body.y = y;
	m_body.w = 100;
	m_body.h = 10;

	m_color.r = 0xff;
	m_color.g = 0xff;
	m_color.b = 0xff;
	m_color.a = 0xff;
}

Object::~Object() {}
