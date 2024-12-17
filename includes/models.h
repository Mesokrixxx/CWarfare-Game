#ifndef MODELS_H
# define MODELS_H

# include "wg_vars.h"
# include "wg_math.h"
# include "dynamicList.h"
# include "graphics.h"

typedef struct s_part {
    char *id;
    uint color;
    Bool filled;
    Layer layer;
    DList points;
} Part;

typedef struct s_model {
    DList *modelParts;
    iVec2 *origin;
} Model;

Model *loadModel(char *path, iVec2 origin);
void applyModelToContent(void *c, Model *m);
void freeModel(Model *m);

#endif