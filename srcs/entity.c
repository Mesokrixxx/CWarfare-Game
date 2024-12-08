# include "entity.h"

Functions *functionsRegister(   void (*init)(void*),
                                void (*render)(void*),
                                void (*update)(void*)) {
    Functions *f;

    f = calloc(1, sizeof(struct s_functions));
    f->init = init;
    f->render = render;
    f->update = update;
    return (f);
}

Entity *entityConstructor(iVec3 pos, Vec3 vel, Functions *f) {
    Entity *entity = calloc(1, sizeof(struct s_entity));
    
    entity->position = pos;
    entity->velocity = vel;
    entity->f = f;
    return (entity);
}
