#include "entity.hpp"

Entity::Entity( int x, int y )
{
	m_vel_x = 5;
	m_grav = 0.5;

	m_body.x = x;
	m_body.y = y;
	m_body.w = 20;
	m_body.h = 20;

	m_color.r = 0xff;
	m_color.g = 0xff;
	m_color.b = 0xff;
	m_color.a = 0xff;
}

Entity::Entity() {}

void Entity::setColor( SDL_Color color )
{
	m_color = color;
}

void Entity::update()
{

}

Entity::~Entity()
{

}
