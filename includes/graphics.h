# ifndef WG_GRAPHICS_H
# define WG_GRAPHICS_H

#include "wg_vars.h"
#include "wg_math.h"

void drawLine(iVec2 startpos, iVec2 endpos, t_game *game, uint Color);
void drawTriangle(iVertices vertices, t_game *game, uint Color);
void drawFilledTriangle(iVertices vertices, t_game *game, uint Color);

#endif