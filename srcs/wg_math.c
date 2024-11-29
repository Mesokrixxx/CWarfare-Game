#include "wg_math.h"

Vec2 newVec2(float x, float y) { return ((Vec2){ x, y }); }
iVec2 newiVec2(int x, int y) { return ((iVec2){ x, y }); }
Vertices newVertices(Vec2 a, Vec2 b, Vec2 c) { return ((Vertices){ a, b, c }); }
iVertices newiVertices(iVec2 a, iVec2 b, iVec2 c) { return ((iVertices){ a, b, c }); }

int	interpolate(iVec2 v1, iVec2 v2, int y) {
	if (v1.y == v2.y) { return (v1.x); }
	return (v1.x + (y - v1.y) * (v2.x - v1.x) / (v2.y - v1.y));
}

void swapiVec2s(iVec2 *v1, iVec2 *v2) {
	iVec2 temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void swapInt(int *x1, int *x2) {
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}
