# include "entity.h"

void tankInit(void *vTank) {
    printf("Tank initialising\n");
}

void tankRender(void *vTank) {
    printf("Tank Rendering\n");
}

void tankUpdate(void *vTank) {
    printf("Tank Updating\n");
}

void tankLoad(Tank *tank, iVec3 pos, Vec3 vel, int temp)
{
    Functions *f = functionsRegister(tankInit, tankRender, tankUpdate);
    tank = tankConstructor(pos, vel, f, temp);
}
