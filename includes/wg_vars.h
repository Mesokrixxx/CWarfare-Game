#ifndef WG_VARS_H
# define WG_VARS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>

typedef enum { false, true } Bool;

# define uint unsigned int
# define uchar unsigned char

# define defaultWindowWidth 1280
# define defaultWindowHeight 720
# define MapWidth (defaultWindowWidth / 2)
# define MapHeight MapWidth

# define ASSERT(c, ...) if (!c) { fprintf(stderr, __VA_ARGS__ ); }

typedef struct s_game {
	SDL_Window		*window;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	uint			pixels[MapWidth * MapHeight];
	Bool			quit;
}	Game;

#endif