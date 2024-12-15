# include "entity.h"

static void moveUp(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    eTank->position.y += 1;
}

static void moveDown(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    eTank->position.y -= 1;
}

static void moveLeft(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    eTank->position.x -= 1;
}

static void moveRight(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    eTank->position.x += 1;
}

static void init(void *vTank, EventHandler *eh, Game *game) {
    Entity *eTank = (Entity *)vTank;

    // Events
    addEventToEventHandler(eh, eventConstructor(SDLK_z, &moveUp, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_s, &moveDown, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_q, &moveLeft, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_d, &moveRight, vTank));
}

static void render(void *vTank, EventHandler *eh, Game *game) {
    
}

static void update(void *vTank, EventHandler *eh, Game *game) {

}

Tank *tankConstructor(iVec2 pos, Vec2 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    Entity *temp = entityConstructor(pos, vel, functionsRegister(init, render, update));
    *eTank = *temp;

    tTank->id = id;
    return (tTank);
}
