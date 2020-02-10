#include "player.hpp"
#include "object.hpp"

int WIDTH = 640;
int HEIGHT = 480;

void init() {
	/*
	if ( TTF_Init() == -1 ) {
        SDL_Log( "Unable to initialize TTF: %s", TTF_GetError() );
		exit( 1 );
	}
	*/

	if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {
        SDL_Log( "Unable to initialize SDL: %s", SDL_GetError() );
        exit( 1 );
	}
}

int main( /*int argc, char** argv*/ )
{
	init();

	SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_Event event;
	bool running = 1;

	window = SDL_CreateWindow( "Change Color Screen",   // Title
							   SDL_WINDOWPOS_UNDEFINED, // Pos_x
							   SDL_WINDOWPOS_UNDEFINED, // Pos_y
							   WIDTH, HEIGHT,           // Width, Height
							   SDL_WINDOW_SHOWN );      // State

	renderer = SDL_CreateRenderer( window, -1, 0 );

	Player player( 0, HEIGHT - 20 );
	player.setColor( SDL_Color{ 0xff, 0xff, 0xff, 0x7f } );	

	Object platform( WIDTH - 250, HEIGHT - 150 );

	while ( running ) {
        while ( SDL_PollEvent( &event ) != 0 ) {
			if ( event.type == SDL_KEYDOWN ) {
				if ( event.key.keysym.sym == SDLK_ESCAPE ) {
					running = 0;	
				}
			}
			if ( event.type == SDL_QUIT ) {
				running = 0;
			}
			player.handleEvents( event );
		}
        SDL_SetRenderDrawColor( renderer, 0xf, 0xf, 0xf, 0xff );
		SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
        SDL_RenderClear( renderer );

		// -------------------Custom objects render -------------------
		player.update();
		player.draw( renderer );

		platform.draw( renderer );
		// -------------------END-------------------

        SDL_RenderPresent( renderer );
		SDL_Delay( 16 );
	}

	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	SDL_Quit();

	return 0;
}
