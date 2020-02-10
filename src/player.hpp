#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

/*! \class Player
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Player : public Entity
{
public:
	Player( int x, int y );

	void handleEvents( SDL_Event &event );

	void update();

	virtual ~Player();

protected:
	bool m_jump;
	bool m_move[2];
};

#endif // PLAYER_HPP
