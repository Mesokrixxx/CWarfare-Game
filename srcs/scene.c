#include "scene.h"

// Create a scene
Scene *initScene() {
	Scene *s = calloc(1, sizeof(struct s_scene));

	s->entities = initDynamicList(sizeof(struct s_entity));
	return (s);
}

// Add an entity to a scene
void addEntityToScene(Scene *s, Entity *entity) {
	appendToDList(s->entities, entity);
}

// Initialize the content of a scene
void initSceneContent(Scene *s, EventHandler *eh, Game *game) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = ((Entity *)s->entities->content[i]);
		if (e->f->init)
			e->f->init(e, eh, game);
        if (e->parts->size > 0)
            sortPartsOfEntity(e->parts);
    }
}

// Update the content of a scene
void updateSceneContent(Scene *s, EventHandler *eh, Game *game) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		if (e->f->update)
			e->f->update(e, eh, game);
	}
}

// Render the content of a scene
void renderSceneContent(Scene *s, EventHandler *eh, Game *game) {
	for (int i = 0; i < s->entities->size; i++)
	{
		Entity *e = (Entity *)s->entities->content[i];
		if (e->f->render)
			e->f->render(e, eh, game);
	}
}
