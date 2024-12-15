# include "models.h"

char *getModel(char *path) {
    int fd = open(path, O_RDONLY);
    if (fd > 0)
    {
        char *buffer = malloc(4096);
        read(fd, buffer, 4096);
        char *modelFormat = malloc(strlen(buffer) + 1);
        strcpy(modelFormat, buffer);
        free(buffer);
        close(fd);
        return (modelFormat);
    }
    return (NULL);
}

Model *loadModel(char *path, iVec2 origin) {
    char *modelFormat = getModel(path);
    if (!modelFormat) return (NULL);
    
    Model *model = calloc(1, sizeof(struct s_model));
    
    model->modelParts = initDynamicList(sizeof(struct s_part));
    model->origin = calloc(1, sizeof(iVec2));
    *model->origin = origin;
    
    free(modelFormat);
    return (model);
}

void applyModelToContent(void *e, Model *m) {
    if (!m || !e) return ;
}

void freeModel(Model *m) {
    free(m->origin);
    freeDList(m->modelParts);
    free(m);
}
