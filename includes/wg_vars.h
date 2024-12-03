#ifndef WG_VARS_H
# define WG_VARS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <SDL2/SDL.h>

# define uint unsigned int
# define uchar unsigned char

typedef enum { false, true } Bool;
typedef struct { float	x, y; } Vec2;
typedef struct { int	x, y; } iVec2;
typedef struct { float	x, y, z; } Vec3;
typedef struct { int	x, y, z; } iVec3;
typedef struct { Vec2	a, b, c; } Vertices;
typedef struct { iVec2	a, b, c; } iVertices;

# define defaultWindowWidth 1280
# define defaultWindowHeight 720
# define MapWidth (defaultWindowWidth / 2)
# define MapHeight MapWidth

# define BLUE 0xFF0000
# define GREEN 0x00FF00
# define DGREEN 0x006400
# define RED 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0x800080
# define YELLOW 0x00FFFF
# define CYAN 0xFFFF00
# define PINK 0xFF00FF

# define ASSERT(c, ...) if (!c) { fprintf(stderr, __VA_ARGS__ ); }
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define ROUND(x) ((int)((x) + 0.5f))

typedef struct s_game {
	SDL_Window		*window;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	uint			pixels[MapWidth * MapHeight];
	Bool			quit;
}	Game;

#endif