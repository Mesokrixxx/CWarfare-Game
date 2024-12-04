#ifndef WG_SCENE_MANAGER_H
# define WG_SCENE_MANAGER_H

# include "scene.h"
# include "dynamicList.h"

typedef struct s_scenemanager {
	DList *scenes;
	int index;
} SceneManager;

SceneManager *initSceneManager();
void addSceneToSceneManager(SceneManager *sm, Scene *s);

Scene *getActualScene(SceneManager *sm);

#endif