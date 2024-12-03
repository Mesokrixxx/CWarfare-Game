# ifndef WG_GRAPHICS_H
# define WG_GRAPHICS_H

#include "wg_vars.h"
#include "wg_math.h"

void drawLine(iVec2 startpos, iVec2 endpos, Game *game, uint Color);
void drawTriangle(iVertices vertices, Game *game, uint Color);
void drawFilledTriangle(iVertices vertices, Game *game, uint Color);

#endif