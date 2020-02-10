#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "drawable.hpp"

/*! \class Entity
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Entity : public Drawable
{
public:
	Entity( int x, int y );
	Entity();
	virtual ~Entity();

	void setColor( SDL_Color color );

	virtual void update();

protected:
	int m_vel_x;
	float m_vel_y;
	float m_grav;
};

#endif //ENTITY_HPP
