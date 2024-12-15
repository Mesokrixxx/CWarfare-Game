#include "graphics.h"

// Check if a point is within bounds
Bool isInBounds(int x, int y) {
    return (x >= 0 && x < MapWidth && y >= 0 && y < MapHeight);
}

// Draw a single pixel at (x, y)
void drawPixel(int x, int y, Game *game, uint Color) {
    if (isInBounds(x, y))
        game->pixels[(y * MapWidth) + x] = Color;
}

// Draw an horizontal line
void drawFastHLine(int x1, int x2, int y, Game *game, uint Color) {
    if (y < 0 || y >= MapHeight) return;
    if (x1 > x2) { int tmp = x1; x1 = x2; x2 = tmp; }
    
    x1 = MAX(0, x1);
    x2 = MIN(MapWidth - 1, x2);
    
    for (int x = x1; x <= x2; x++)
        drawPixel(x, y, game, Color);
}

// Draws a line between 2 points
void drawLine(iVec2 startpos, iVec2 endpos, Game *game, uint Color) {
    int x1 = startpos.x, y1 = startpos.y;
    int x2 = endpos.x, y2 = endpos.y;
    
    // Vertical line
    if (x1 == x2) {
        int ystart = MAX(0, MIN(y1, y2));
        int yend = MIN(MapHeight - 1, MAX(y1, y2));
        for (int y = ystart; y <= yend; y++)
            drawPixel(x1, y, game, Color);
        return;
    }
    
    // Horizontal line
    if (y1 == y2) {
        drawFastHLine(x1, x2, y1, game, Color);
        return;
    }
    
    // Other lines
    int dx = ABS(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -ABS(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;
    
    while (1) {
        drawPixel(x1, y1, game, Color);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

// Draws a triangle outline
void drawTriangle(iVertices vertices, Game *game, uint Color) {
    drawLine(vertices.a, vertices.b, game, Color);
    drawLine(vertices.b, vertices.c, game, Color);
    drawLine(vertices.c, vertices.a, game, Color);
}

// Draws a filled triangle
void drawFilledTriangle(iVertices vertices, Game *game, uint Color) {
    // Sort vertices by y
    if (vertices.a.y > vertices.b.y) { swapiVec2s(&vertices.a, &vertices.b); }
    if (vertices.a.y > vertices.c.y) { swapiVec2s(&vertices.a, &vertices.c); }
    if (vertices.b.y > vertices.c.y) { swapiVec2s(&vertices.b, &vertices.c); }
    
    // Early return if triangle is completely outside screen
    if (vertices.a.y >= MapHeight || vertices.c.y < 0) return;
    
    int total_height = vertices.c.y - vertices.a.y;
    if (total_height == 0) return;

    // First half of the triangle
    int segment_height = vertices.b.y - vertices.a.y;
    for (int y = vertices.a.y; y <= vertices.b.y; y++) {
        if (y < 0) continue;
        if (y >= MapHeight) return;

        float alpha = (float)(y - vertices.a.y) / total_height;
        float beta = segment_height ? (float)(y - vertices.a.y) / segment_height : 1.0f;

        int x1 = vertices.a.x + (int)(alpha * (vertices.c.x - vertices.a.x));
        int x2 = vertices.a.x + (int)(beta * (vertices.b.x - vertices.a.x));

        if (x1 > x2) { swapInt(&x1, &x2); }
        drawFastHLine(x1, x2, y, game, Color);
    }

    // Second half of the triangle
    segment_height = vertices.c.y - vertices.b.y;
    for (int y = vertices.b.y; y <= vertices.c.y; y++) {
        if (y < 0) continue;
        if (y >= MapHeight) return;

        float alpha = (float)(y - vertices.a.y) / total_height;
        float beta = segment_height ? (float)(y - vertices.b.y) / segment_height : 1.0f;

        int x1 = vertices.a.x + (int)(alpha * (vertices.c.x - vertices.a.x));
        int x2 = vertices.b.x + (int)(beta * (vertices.c.x - vertices.b.x));

        if (x1 > x2) { swapInt(&x1, &x2); }
        drawFastHLine(x1, x2, y, game, Color);
    }
}

// Draws a rectangle outline
void drawRect(iVec2 pos, iVec2 size, Game *game, uint Color) {
    drawFastHLine(pos.x, pos.x + size.x, pos.y, game, Color);
    drawFastHLine(pos.x, pos.x + size.x, pos.y + size.y, game, Color);
    drawLine(newiVec2(pos.x, pos.y), newiVec2(pos.x, pos.y + size.y), game, Color);
    drawLine(newiVec2(pos.x + size.x, pos.y), newiVec2(pos.x + size.x, pos.y + size.y), game, Color);
}

// Draws a filled rectangle
void drawFilledRect(iVec2 pos, iVec2 size, Game *game, uint Color) {
    int yStart = MAX(0, pos.y);
    int yEnd = MIN(MapHeight - 1, pos.y + size.y);
    
    for (int y = yStart; y <= yEnd; y++)
        drawFastHLine(pos.x, pos.x + size.x, y, game, Color);
}
