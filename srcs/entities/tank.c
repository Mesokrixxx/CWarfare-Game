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
    int x = eTank->position.x;
    int y = eTank->position.y;

    // Graphics
    RenderingPart *body = initRenderingPart(false, WHITE, ENTITIES);
    appendToRenderingPart(body, newiVec2(x, y), newiVec2(-8, -12));
    appendToRenderingPart(body, newiVec2(x, y), newiVec2(8, -12));
    appendToRenderingPart(body, newiVec2(x, y), newiVec2(-8, 12));
    appendToRenderingPart(body, newiVec2(x, y), newiVec2(8, 12));

    RenderingPart *left_chassis = initRenderingPart(false, BLUE, ENTITIES - 2);
    appendToRenderingPart(left_chassis, newiVec2(x, y), newiVec2(-15, -20));
    appendToRenderingPart(left_chassis, newiVec2(x, y), newiVec2(-8, -20));
    appendToRenderingPart(left_chassis, newiVec2(x, y), newiVec2(-15, 20));
    appendToRenderingPart(left_chassis, newiVec2(x, y), newiVec2(-8, 20));

    RenderingPart *right_chassis = initRenderingPart(false, RED, ENTITIES - 2);
    appendToRenderingPart(right_chassis, newiVec2(x, y), newiVec2(15, -20));
    appendToRenderingPart(right_chassis, newiVec2(x, y), newiVec2(8, -20));
    appendToRenderingPart(right_chassis, newiVec2(x, y), newiVec2(15, 20));
    appendToRenderingPart(right_chassis, newiVec2(x, y), newiVec2(8, 20));

    addPartToEntity(eTank, body);
    addPartToEntity(eTank, left_chassis);
    addPartToEntity(eTank, right_chassis);

    // Events
    addEventToEventHandler(eh, eventConstructor(SDLK_z, &moveUp, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_s, &moveDown, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_q, &moveLeft, vTank));
    addEventToEventHandler(eh, eventConstructor(SDLK_d, &moveRight, vTank));
}

static void render(void *vTank, EventHandler *eh, Game *game) {
    Entity *eTank = (Entity *)vTank;
    drawRenderingParts(eTank->parts, game);
}

static void update(void *vTank, EventHandler *eh, Game *game) {
    Entity *eTank = (Entity *)vTank;
    
    // Update all rendering parts origins based on tank position
    for (uint i = 0; i < eTank->parts->size; i++) {
        RenderingPart *part = (RenderingPart *)eTank->parts->content[i];
        for (uint j = 0; j < part->origin->size; j++) {
            iVec2 *origin = (iVec2 *)part->origin->content[j];
            origin->x = eTank->position.x;
            origin->y = eTank->position.y;
        }
    }
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    Entity *temp = entityConstructor(pos, vel, functionsRegister(init, render, update));
    *eTank = *temp;

    tTank->id = id;
    return (tTank);
}
