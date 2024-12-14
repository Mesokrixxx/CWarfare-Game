# include "entity.h"

// Create a new set of functions
Functions *functionsRegister(   void (*init)(void*, Game*),
                                void (*render)(void*, Game*),
                                void (*update)(void*, Game*)) {
    Functions *f;

    f = calloc(1, sizeof(struct s_functions));
    f->init = init;
    f->render = render;
    f->update = update;
    return (f);
}

// Create an entity
Entity *entityConstructor(iVec3 pos, Vec3 vel, Functions *f) {
    Entity *entity = calloc(1, sizeof(struct s_entity));
    
    entity->position = pos;
    entity->velocity = vel;
    entity->f = f;
    entity->parts = initDynamicList(sizeof(struct s_renderingpart));
    return (entity);
}

// Destroy an entity
void destroyEntity(Entity *e) {
    // Free all parts
    for (uint i = 0; i < e->parts->size; i++) {
        destroyRenderingPart((RenderingPart *)e->parts->content[i]);
    }
    freeDList(e->parts);
    free(e->f);
    free(e);
}

// Add a part to an entity
void addPartToEntity(Entity *e, RenderingPart *part) {
    appendToDList(e->parts, part);
}
