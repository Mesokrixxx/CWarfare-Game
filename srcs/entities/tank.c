# include "entity.h"

static void init(void *vTank, Game *game) {
    Entity *eTank = (Entity *)vTank;
    int x = eTank->position.x;
    int y = eTank->position.y;

    RenderingPart *body = initRenderingPart(false, WHITE);
    appendToRenderingPart(body, newiVec2(x - 8, y - 12));
    appendToRenderingPart(body, newiVec2(x + 8, y - 12));
    appendToRenderingPart(body, newiVec2(x - 8, y + 12));
    appendToRenderingPart(body, newiVec2(x + 8, y + 12));

    RenderingPart *left_chassis = initRenderingPart(false, BLUE);
    appendToRenderingPart(left_chassis, newiVec2(x - 15, y - 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 8, y - 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 15, y + 20));
    appendToRenderingPart(left_chassis, newiVec2(x - 8, y + 20));

    RenderingPart *right_chassis = initRenderingPart(false, RED);
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
    
    for (int i = 0; i < ((Entity *)vTank)->parts->size; i++)
        drawRenderingPart((RenderingPart *)((Entity *)vTank)->parts->content[i], game);
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
