#include "wg.h"

static void load(SceneManager **SM)
{
	Tank			*tank1 = tankConstructor(newiVec3(0, 0, 0), newVec3(0, 0, 0), 1);
	Tank			*tank2 = tankConstructor(newiVec3(0, 0, 0), newVec3(0, 0, 0), 2);

	Scene			*gameScene = initScene();
	addEntityToScene(gameScene, tank1);
	addEntityToScene(gameScene, tank2);

	*SM = initSceneManager();
	addSceneToSceneManager(*SM, gameScene);
}

static void init(Game *game, SceneManager *SM) {
	Scene *actualScene = getActualScene(SM);
	initSceneContent(actualScene);
}

static void update(Game *game, SceneManager *SM) {
	Scene *actualScene = getActualScene(SM);
	updateSceneContent(actualScene);
}

static void render(Game *game, SceneManager *SM) {
	Scene *actualScene = getActualScene(SM);
	renderSceneContent(actualScene);
}

int main(void) {
	SceneManager	*SM;
	Game 			game;
	
	bzero(&game, sizeof(game));
	bzero(&SM, sizeof(SM));
	ASSERT(!SDL_Init(SDL_INIT_VIDEO),
		"Failed to init SDL video: %s\n",
		SDL_GetError());

	game.window = SDL_CreateWindow(
					"C SNAKE",
					SDL_WINDOWPOS_CENTERED_DISPLAY(1), SDL_WINDOWPOS_CENTERED_DISPLAY(1),
					defaultWindowWidth, defaultWindowHeight,
					SDL_WINDOW_ALLOW_HIGHDPI);
	ASSERT(game.window, "Failed to create SDL window: %s\n", SDL_GetError());

	game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_PRESENTVSYNC);
	ASSERT(game.renderer, "Failed to create SDL renderer: %s\n", SDL_GetError());

	game.texture = SDL_CreateTexture(
						game.renderer,
						SDL_PIXELFORMAT_ABGR8888,
						SDL_TEXTUREACCESS_STREAMING,
						MapWidth, MapHeight);
	ASSERT(game.texture, "Failed to create SDL texture: %s\n", SDL_GetError());

	load(&SM);
	init(&game, SM);
	while (!game.quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					game.quit = true;
					break ;
			}
		}

		const uchar *keyState = SDL_GetKeyboardState(NULL);

		if (keyState[SDL_SCANCODE_ESCAPE])
			game.quit = true;

		bzero(game.pixels, sizeof(game.pixels));

		update(&game, SM);
		render(&game, SM);

		SDL_UpdateTexture(game.texture, NULL, game.pixels, MapWidth * 4);
		SDL_RenderCopyEx(
			game.renderer,
			game.texture,
			NULL, NULL,
			0.0,
			NULL,
			SDL_FLIP_VERTICAL);
		SDL_RenderPresent(game.renderer);
	}

	SDL_DestroyTexture(game.texture);
	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	return (0);
}