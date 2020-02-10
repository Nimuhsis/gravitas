#include "drawable.hpp"

Drawable::Drawable() {}

Drawable::~Drawable() {}

void Drawable::draw( SDL_Renderer *renderer )
{
	SDL_SetRenderDrawColor( renderer, m_color.r, m_color.g, m_color.b, m_color.a );
	SDL_RenderFillRect( renderer, &m_body );
}
