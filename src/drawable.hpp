#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SDL2/SDL.h>

/*! \class Drawable
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Drawable
{
public:
	Drawable();
	virtual ~Drawable();

	void draw( SDL_Renderer *renderer );

protected:
	SDL_Rect m_body;
	SDL_Color m_color;
};

#endif //DRAWABLE_HPP
