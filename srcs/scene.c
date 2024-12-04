#include "scene.h"

Scene *initScene() {
	Scene *s;

	s = calloc(1, sizeof(struct s_scene));
	s->entities = initDynamicList(sizeof(struct s_entity));
	return (s);
}

void addEntityToScene(Scene *s, void *entity) {
	appendToDList(s->entities, entity);
}

void initSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		e->f->init(e);
	}
}

void updateSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		e->f->update(e);
	}
}

void renderSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		e->f->render(e);
	}
}
