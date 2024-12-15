# ifndef WG_GRAPHICS_H
# define WG_GRAPHICS_H

# include "wg_vars.h"
# include "wg_math.h"
# include "dynamicList.h"

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

Bool isInBounds(int x, int y);
void drawPixel(int x, int y, Game *game, uint Color);
void drawLine(iVec2 startpos, iVec2 endpos, Game *game, uint Color);
void drawFastHLine(int x1, int x2, int y, Game *game, uint Color);
void drawTriangle(iVertices vertices, Game *game, uint Color);
void drawFilledTriangle(iVertices vertices, Game *game, uint Color);
void drawRect(iVec2 pos, iVec2 size, Game *game, uint Color);
void drawFilledRect(iVec2 pos, iVec2 size, Game *game, uint Color);

#endif