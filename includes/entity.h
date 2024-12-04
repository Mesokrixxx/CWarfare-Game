#ifndef WG_ENTITY_H
# define WG_ENTITY_H 

# include "wg_vars.h"
# include "graphics.h"
# include "wg_math.h"

typedef struct s_functions{
    void    (*init)(void*);
    void    (*render)(void*);
    void    (*update)(void*);
}   Functions;

Functions *functionsRegister(   void (*init)(void*),
                                void (*render)(void*),
                                void (*update)(void*));

typedef struct s_entity {
    iVec3       position;
    Vec3        velocity;
    Functions   *f;
}   Entity;

Entity *entityConstructor(iVec3 pos, Vec3 vel, Functions *f);

typedef struct s_tank {
    Entity  base;
    int     id;
}   Tank;

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id);

#endif
