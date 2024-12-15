# include "entity.h"

// Create a new set of functions
Functions *functionsRegister(   void (*init)(void*, EventHandler*, Game*),
                                void (*render)(void*, EventHandler*, Game*),
                                void (*update)(void*, EventHandler*, Game*)) {
    Functions *f;

    f = calloc(1, sizeof(struct s_functions));
    f->init = init;
    f->render = render;
    f->update = update;
    return (f);
}

// Create an entity
Entity *entityConstructor(iVec2 pos, Vec2 vel, Functions *f) {
    Entity *entity = calloc(1, sizeof(struct s_entity));
    
    entity->position = pos;
    entity->velocity = vel;
    entity->f = f;
    return (entity);
}

// Destroy an entity
void destroyEntity(Entity *e) {
    free(e->f);
    free(e);
}
