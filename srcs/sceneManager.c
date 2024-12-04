#include "sceneManager.h"

SceneManager *initSceneManager() {
	SceneManager *SM;

	SM = calloc(1, sizeof(struct s_scenemanager));
	SM->scenes = initDynamicList(sizeof(struct s_scene));
	return (SM);
}

void addSceneToSceneManager(SceneManager *sm, Scene *s) {
	appendToDList(sm->scenes, s);
}

Scene *getActualScene(SceneManager *sm) {
	return ((Scene *)sm->scenes->content[sm->index]);
}