#ifndef WG_SCENE_H
# define WG_SCENE_H

# include "entity.h"
# include "dynamicList.h"

typedef struct s_scene {
	DList *entities;
} Scene;

Scene *initScene();
void addEntityToScene(Scene *s, Entity *entity);

void initSceneContent(Scene *s, Game *game);
void updateSceneContent(Scene *s, Game *game);
void renderSceneContent(Scene *s, Game *game);

#endif