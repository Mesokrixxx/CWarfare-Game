# ifndef WG_GRAPHICS_H
# define WG_GRAPHICS_H

# include "wg_vars.h"
# include "wg_math.h"

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

typedef struct s_part {
    DList *vertices;
    void (*drawMethod)(iVertices, Game*, uint);
} Part;

void drawLine(iVertices vertices, Game *game, uint Color);
void drawTriangle(iVertices vertices, Game *game, uint Color);
void drawFilledTriangle(iVertices vertices, Game *game, uint Color);

#endif