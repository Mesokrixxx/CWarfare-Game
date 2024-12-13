#include "sceneManager.h"

// Create a scene manager
SceneManager *initSceneManager() {
	SceneManager *SM = calloc(1, sizeof(struct s_scenemanager));

	SM->scenes = initDynamicList(sizeof(struct s_scene));
	SM->index = 0;
	return (SM);
}

// Add a scene to a scene manager
void addSceneToSceneManager(SceneManager *sm, Scene *s) {
	appendToDList(sm->scenes, s);
}

// Return the actual scene
Scene *getActualScene(SceneManager *sm) {
	return ((Scene *)(sm->scenes->content[sm->index]));
}
