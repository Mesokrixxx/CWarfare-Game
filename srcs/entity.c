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
    Entity *entity;
    
    entity = calloc(1, sizeof(struct s_entity));
    entity->position = pos;
    entity->velocity = vel;
    entity->f = f;
    return (entity);
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, Functions *f, int temp) {
    Tank *tank;

    tank = calloc(1, sizeof(struct s_tank));
    tank->base = entityConstructor(pos, vel, f);
    tank->temp;
    return (tank);
}
