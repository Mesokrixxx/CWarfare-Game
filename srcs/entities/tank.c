# include "entity.h"

# include <math.h>

static void init(void *vTank, Game *game) {

}

static void render(void *vTank, Game *game) {
    
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
