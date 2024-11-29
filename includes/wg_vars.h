#ifndef WG_VARS_H
# define WG_VARS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>

# define uint unsigned int
# define uchar unsigned char

typedef enum { false, true } Bool;
typedef struct { float	x, y; } Vec2;
typedef struct { int	x, y; } iVec2;

# define defaultWindowWidth 1280
# define defaultWindowHeight 720
# define MapWidth (defaultWindowWidth / 2)
# define MapHeight (defaultWindowHeight / 2)

# define ASSERT(c, ...) if (!c) { fprintf(stderr, __VA_ARGS__ ); }
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define ROUND(x) ((int)((x) + 0.5f))

typedef struct s_game {
	SDL_Window		*window;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	uint			pixels[MapWidth * MapHeight];
	Bool			quit;
}	t_game;

#endif