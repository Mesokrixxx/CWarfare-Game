#include "graphics.h"

void drawLine(iVertices vertices, Game *game, uint Color) {
	iVec2 startpos = vertices.a, endpos = vertices.b;
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

void drawTriangle(iVertices vertices, Game *game, uint Color) {
	drawLine(newiVertices(vertices.a, vertices.b, newiVec2(0, 0)), game, Color);
	drawLine(newiVertices(vertices.a, vertices.c, newiVec2(0, 0)), game, Color);
	drawLine(newiVertices(vertices.c, vertices.b, newiVec2(0, 0)), game, Color);
}

void drawFilledTriangle(iVertices vertices, Game *game, uint Color) {
	if (vertices.a.y > vertices.b.y) { swapiVec2s(&vertices.a, &vertices.b); }
	if (vertices.a.y > vertices.c.y) { swapiVec2s(&vertices.a, &vertices.c); }
	if (vertices.b.y > vertices.c.y) { swapiVec2s(&vertices.b, &vertices.c); }

	for (int y = vertices.a.y; y <= vertices.c.y; y++) {
        int x1, x2;

        if (y < vertices.b.y) {
            x1 = interpolate(vertices.a, vertices.b, y);
            x2 = interpolate(vertices.a, vertices.c, y);
        } else {
            x1 = interpolate(vertices.b, vertices.c, y);
            x2 = interpolate(vertices.a, vertices.c, y);
        }

        if (x1 > x2) { swapInt(&x1, &x2); }

		drawLine(newiVertices(newiVec2(x1, y), newiVec2(x2, y), newiVec2(0, 0)), game, Color);
    }
}
