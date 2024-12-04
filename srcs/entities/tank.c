# include "entity.h"

static void init(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank initialising: %d\n", 0);
}

static void render(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank Rendering: %d\n", 0);
}

static void update(void *vTank) {
    Tank *tTank = (Tank *)vTank;
    printf("Tank Updating: %d\n", 0);
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tTank = calloc(1, sizeof(struct s_tank));
    Entity *eTank = (Entity *)tTank;

    eTank = entityConstructor(pos, vel, functionsRegister(&init, &render, &update));
    tTank->id = id;
    return (tTank);
}
