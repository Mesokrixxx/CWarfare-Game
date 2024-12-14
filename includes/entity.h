#ifndef WG_ENTITY_H
# define WG_ENTITY_H 

# include "wg_vars.h"
# include "graphics.h"
# include "wg_math.h"
# include "dynamicList.h"
# include "eventHandler.h"

typedef struct s_functions{
    void    (*init)(void*, EventHandler*, Game*);
    void    (*render)(void*, EventHandler*, Game*);
    void    (*update)(void*, EventHandler*, Game*);
}   Functions;

Functions *functionsRegister(   void (*init)(void*, EventHandler*, Game*),
                                void (*render)(void*, EventHandler*, Game*),
                                void (*update)(void*, EventHandler*, Game*));

typedef struct s_entity {
    iVec3       position;
    Vec3        velocity;
    Functions   *f;
    DList       *parts;
}   Entity;

Entity *entityConstructor(iVec3 pos, Vec3 vel, Functions *f);
void destroyEntity(Entity *e);
void addPartToEntity(Entity *e, RenderingPart *part);

typedef struct s_tank {
    Entity  base;
    int     id;
}   Tank;

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id);

#endif
