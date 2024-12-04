# include "entity.h"

static void init(void *vTank) {
    printf("Tank initialising: %d\n", ((Tank *)vTank)->id);
}

static void render(void *vTank) {
    printf("Tank Rendering: %d\n", ((Tank *)vTank)->id);
}

static void update(void *vTank) {
    printf("Tank Updating: %d\n", ((Tank *)vTank)->id);
}

Tank *tankConstructor(iVec3 pos, Vec3 vel, int id) {
    Tank *tank;

    tank = calloc(1, sizeof(struct s_tank));
    tank->base = entityConstructor(pos, vel, functionsRegister(init, render, update));
    tank->id = id;
    return (tank);
}
