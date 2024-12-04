# include "entity.h"

static void init(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank initialising: %d\n", tTank->id);
}

static void render(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank Rendering: %d\n", tTank->id);
}

static void update(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank Updating: %d\n", tTank->id);
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    Entity *temp = entityConstructor(pos, vel, functionsRegister(init, render, update));
    *eTank = *temp;

    tTank->id = id;
    return (tTank);
}
