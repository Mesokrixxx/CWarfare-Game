# include "entity.h"

static void moveUp(void *vTank, Game *game) {
    printf("moveUp\n");
}

static void moveDown(void *vTank, Game *game) {
    printf("moveDown\n");
}

static void moveLeft(void *vTank, Game *game) {
    printf("moveLeft\n");
}

static void moveRight(void *vTank, Game *game) {
    printf("moveRight\n");
}

static void init(void *vTank, EventHandler *eh, Game *game) {
    Entity *eTank = (Entity *)vTank;
    int x = eTank->position.x;
    int y = eTank->position.y;

    RenderingPart *body = initRenderingPart(false, WHITE, ENTITIES);
    appendToRenderingPart(body, newiVec2(x - 8, y - 12));
    appendToRenderingPart(body, newiVec2(x + 8, y - 12));
    appendToRenderingPart(body, newiVec2(x - 8, y + 12));
    appendToRenderingPart(body, newiVec2(x + 8, y + 12));

    RenderingPart *left_chassis = initRenderingPart(false, BLUE, ENTITIES - 2);
    appendToRenderingPart(left_chassis, newiVec2(x - 15, y - 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 8, y - 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 15, y + 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 8, y + 20));

    RenderingPart *right_chassis = initRenderingPart(false, RED, ENTITIES - 2);
    appendToRenderingPart(right_chassis, newiVec2(x + 15, y - 20));
    appendToRenderingPart(right_chassis, newiVec2(x + 8, y - 20));
    appendToRenderingPart(right_chassis, newiVec2(x + 15, y + 20));
    appendToRenderingPart(right_chassis, newiVec2(x + 8, y + 20));

    addPartToEntity(eTank, body);
    addPartToEntity(eTank, left_chassis);
    addPartToEntity(eTank, right_chassis);

    Event *moveUpEvent = eventConstructor(SDLK_w, &moveUp, vTank);
    Event *moveDownEvent = eventConstructor(SDLK_s, &moveDown, vTank);
    Event *moveLeftEvent = eventConstructor(SDLK_a, &moveLeft, vTank);
    Event *moveRightEvent = eventConstructor(SDLK_d, &moveRight, vTank);
    addEventToEventHandler(eh, moveUpEvent);
    addEventToEventHandler(eh, moveDownEvent);
    addEventToEventHandler(eh, moveLeftEvent);
    addEventToEventHandler(eh, moveRightEvent);
}

static void render(void *vTank, EventHandler *eh, Game *game) {
    Entity *eTank = (Entity *)vTank;
    
    drawRenderingParts(eTank->parts, game);
}

static void update(void *vTank, EventHandler *eh, Game *game) {

}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    Entity *temp = entityConstructor(pos, vel, functionsRegister(init, render, update));
    *eTank = *temp;

    tTank->id = id;
    return (tTank);
}
