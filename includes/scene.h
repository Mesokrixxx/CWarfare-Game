#ifndef WG_SCENE_H
# define WG_SCENE_H

# include "entity.h"
# include "dynamicList.h"

typedef struct s_scene {
	DList *entities;
} Scene;

Scene *initScene();
void addEntityToScene(Scene *s, void *entity);

void initSceneContent(Scene *s);
void updateSceneContent(Scene *s);
void renderSceneContent(Scene *s);

#endif