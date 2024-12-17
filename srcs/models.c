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

// Return 1 if line is empty and 0 if not
int gotoNextLine(char *modelFormat, int *pos)
{
	while (modelFormat[*pos] && modelFormat[*pos] != '\n')
		*pos += 1;
	if (modelFormat[*pos])
	{
		*pos += 1;
		if (modelFormat[*pos] && modelFormat[*pos] != '\n')
			return (1);
		return (0);
	}
	return (1);
}

// Get ID in the model: [ID] and call gotoNextLine
char *getID(char *modelFormat, int *pos)
{
	int temp = 0;

	// Get the len of the ID
	while (modelFormat[temp + *pos] != ']')
		temp++;
	char *id = calloc(temp + 1, sizeof(char));
	temp = 0;
	while (modelFormat[*pos] != ']')
	{
		id[temp] = modelFormat[*pos]; 
		*pos += 1;
		temp++;
	}
	gotoNextLine(modelFormat, pos);
	return (id);
}

uint getColor(char *modelFormat, int *pos)
{
	
}

Model *loadModel(char *path, iVec2 origin) {
    if (!checkModelFile(path)) return (NULL);

    char *modelFormat = getModel(path);
    if (!modelFormat) return (NULL);
    
    Model *model = calloc(1, sizeof(struct s_model));
    
    model->modelParts = initDynamicList(sizeof(struct s_part));
    model->origin = calloc(1, sizeof(iVec2));
    *model->origin = origin;
    
    int pos = 0;
    while (modelFormat[pos])
    {
        if (modelFormat[pos] == '[')
        {
            // Initiate New Part
            Part *newPart = calloc(1, sizeof(struct s_part));
            // Get ID
            newPart->id = getID(modelFormat, &pos);
            // Get Color
			newPart->color = getColor(modelFormat, &pos);
            // Get filled
            // Get layer
            // Get points
        }
		pos++;
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
