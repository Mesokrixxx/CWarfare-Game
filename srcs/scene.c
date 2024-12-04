#include "scene.h"

Scene *initScene() {
	Scene *s = calloc(1, sizeof(struct s_scene));

	s->entities = initDynamicList(sizeof(struct s_entity));
	return (s);
}

void addEntityToScene(Scene *s, Entity *entity) {
	appendToDList(s->entities, entity);
}

void initSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = ((Entity *)s->entities->content[i]);
		if (e->f->init)
			e->f->init(e);
	}
}

void updateSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		if (e->f->update)
			e->f->update(e);
	}
}

void renderSceneContent(Scene *s) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		if (e->f->render)
			e->f->render(e);
	}
}
