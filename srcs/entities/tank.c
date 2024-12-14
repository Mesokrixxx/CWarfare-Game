# include "entity.h"

static void init(void *vTank, Game *game) {
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
}

static void render(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    
    drawRenderingParts(eTank->parts, game);
}

static void update(void *vTank, Game *game) {
    
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    Entity *temp = entityConstructor(pos, vel, functionsRegister(init, render, update));
    *eTank = *temp;

    tTank->id = id;
    return (tTank);
}
