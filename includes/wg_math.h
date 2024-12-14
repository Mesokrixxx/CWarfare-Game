#ifndef WG_MATH_H
# define WG_MATH_H

# include "wg_vars.h"

# define MAX(x, y) ((x) > (y) ? (x) : (y))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define ROUND(x) ((int)((x) + 0.5f))

typedef struct { float	x, y; } Vec2;
typedef struct { int	x, y; } iVec2;
typedef struct { float	x, y, z; } Vec3;
typedef struct { int	x, y, z; } iVec3;
typedef struct { Vec2	a, b, c; } Vertices;
typedef struct { iVec2	a, b, c; } iVertices;

Vec2 newVec2(float x, float y);
iVec2 newiVec2(int x, int y);
iVec2 addIVec2(iVec2 v1, iVec2 v2);
Vec3 newVec3(float x, float y, float z);
iVec3 newiVec3(int x, int y, int z);
Vec3 newVec3fromVec2(Vec2 v, float z);
iVec3 newiVec3fromiVec2(iVec2 v, int z);

Vertices newVertices(Vec2 a, Vec2 b, Vec2 c);
iVertices newiVertices(iVec2 a, iVec2 b, iVec2 c);

int interpolate(iVec2 v1, iVec2 v2, int y);
void swapiVec2s(iVec2 *v1, iVec2 *v2);
void swapInt(int *x1, int *x2);

#endif