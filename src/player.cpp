#include "player.hpp"

Player::Player( int x, int y )
{ 
	m_vel_x = 5;
	m_grav = 0.5;

	m_move[0] = m_move[1] = false;

	m_body.x = x;
	m_body.y = y;
	m_body.w = 20;
	m_body.h = 20;

	m_color.r = 0xff;
	m_color.g = 0xff;
	m_color.b = 0xff;
	m_color.a = 0xff;
}

Player::~Player()
{
}

void Player::handleEvents( SDL_Event &event )
{
	if ( event.type == SDL_KEYDOWN ) {
		switch ( event.key.keysym.sym ) {
			case SDLK_SPACE:
				if ( !m_jump ) {
					m_jump = true;
					m_vel_y = 15.f;
				}
				break;
			case SDLK_a:
			case SDLK_LEFT:
				m_move[0] = true;
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				m_move[1] = true;
				break;
			default: break;
		}				 
	}


	if ( event.type == SDL_KEYUP ) {
		switch ( event.key.keysym.sym ) {
			case SDLK_a:
			case SDLK_LEFT:
				m_move[0] = false;
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				m_move[1] = false;
				break;
			default: break;
		}				 
	}			
}

void Player::update()
{
	if ( m_move[0] && m_body.x - m_vel_x > 0 ) {
		m_body.x -= m_vel_x;
	}

	if ( m_move[1] && m_body.x + m_vel_x < 640 - m_body.w ) {
		m_body.x += m_vel_x;
	}

	if ( m_jump ) {
		m_body.y -= m_vel_y;
		m_vel_y -= m_grav;
	}

	if ( m_body.y > 480 - 20 ) {
		m_jump = false;
		m_body.y = 480 - 20;
	}
}
