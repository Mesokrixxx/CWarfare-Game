# include "models.h"

int checkModelFile(char *path)
{
    // TODO
    return (1);
}

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
    if (!checkModelFile(path)) return (NULL);

    char *modelFormat = getModel(path);
    if (!modelFormat) return (NULL);
    
    Model *model = calloc(1, sizeof(struct s_model));
    
    model->modelParts = initDynamicList(sizeof(struct s_part));
    model->origin = calloc(1, sizeof(iVec2));
    *model->origin = origin;
    
    int i = 0;
    while (modelFormat[i])
    {
        if (modelFormat[i] == '[')
        {
            // Initiate New Part
            Part *newPart = calloc(1, sizeof(struct s_part));
            // Get ID
            int temp = 0;
            while (modelFormat[temp + i] != ']')
                temp++;
            char *id = calloc(temp + 1, sizeof(char));
            temp = 0;
            while (modelFormat[i] != ']')
            {
                id[temp] = modelFormat[i]; 
                i++;
                temp++;
            }
            newPart->id = id;
            // Get Color
            // Get filled
            // Get layer
            // Get points
        }        
    }

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
