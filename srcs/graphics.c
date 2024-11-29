#include "graphics.h"

void drawLine(iVec2 startpos, iVec2 endpos, t_game *game, uint Color) {
	float dx = endpos.x - startpos.x, dy = endpos.y - startpos.y;

	int steps = (ABS(dx) > ABS(dy) ? ABS(dx) : ABS(dy));
	if (!steps) {
		game->pixels[(startpos.y * MapWidth) + startpos.x] = Color;
		return ;
	}

	float x_inc = dx / steps, y_inc = dy / steps;
	float x = startpos.x, y = startpos.y;
	for (int i = 0; i <= steps; i++) {
		int xi = ROUND(x), yi = ROUND(y);

		if ((xi >= 0 && xi < MapWidth) && (yi >= 0 && yi < MapHeight))
			game->pixels[(yi * MapWidth) + xi] = Color;

		x += x_inc;
		y += y_inc;
	}
}

void drawRect(iVec2 bleft, iVec2 bright, iVec2 tleft, iVec2 tright, t_game *game, uint Color) {
	drawLine(bleft, bright, game, Color);
	drawLine(bright, tright, game, Color);
	drawLine(tright, tleft, game, Color);
	drawLine(tleft, bleft, game, Color);
}

void drawFilledRect(iVec2 bleft, iVec2 bright, iVec2 tleft, iVec2 tright, t_game *game, uint Color) {
	while () {
		
	}
}
