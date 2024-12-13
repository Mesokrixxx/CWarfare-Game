#include "wg_math.h"

// Returns a new Vec2 (Vectors, set of 2 floats)
Vec2 newVec2(float x, float y) { return ((Vec2){ x, y }); }
// Returns a new iVec2 (Vectors, set of 2 ints)
iVec2 newiVec2(int x, int y) { return ((iVec2){ x, y }); }
// Returns a new Vertices (set of 3 Vec2)
Vertices newVertices(Vec2 a, Vec2 b, Vec2 c) { return ((Vertices){ a, b, c }); }
// Returns a new iVertices (set of 3 iVec2)
iVertices newiVertices(iVec2 a, iVec2 b, iVec2 c) { return ((iVertices){ a, b, c }); }
// Returns a new Vec3 (Vectors, set of 3 floats)
Vec3 newVec3(float x, float y, float z) { return ((Vec3){ x, y, z }); };
// Returns a new iVec3 (Vectors, set of 3 ints)
iVec3 newiVec3(int x, int y, int z) { return ((iVec3){ x, y, z }); };
// Returns a new Vec3 from a Vec2 and a float z
Vec3 newVec3fromVec2(Vec2 v, float z) { return ((Vec3){ v.x, v.y, z }); };
// Returns a new iVec3 from a iVec2 and an int z
iVec3 newiVec3fromiVec2(iVec2 v, int z) { return ((iVec3){ v.x, v.y, z }); };

// Interpolates between v1 and v2 using y
int	interpolate(iVec2 v1, iVec2 v2, int y) {
	if (v1.y == v2.y) { return (v1.x); }
	return (v1.x + (y - v1.y) * (v2.x - v1.x) / (v2.y - v1.y));
}

// Swaps values of v1 with v2
void swapiVec2s(iVec2 *v1, iVec2 *v2) {
	iVec2 temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

// Swaps values of x1 with x2
void swapInt(int *x1, int *x2) {
	int temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}
