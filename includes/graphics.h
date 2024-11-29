# ifndef WG_GRAPHICS_H
# define WG_GRAPHICS_H

#include "wg_vars.h"

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

void drawLine(iVec2 startpos, iVec2 endpos, t_game *game, uint Color);
void drawRect(iVec2 bleft, iVec2 bright, iVec2 tleft, iVec2 tright, t_game *game, uint Color);
void drawFilledRect(iVec2 bleft, iVec2 bright, iVec2 tleft, iVec2 tright, t_game *game, uint Color);

#endif