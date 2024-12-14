#include "wg.h"

static void quit_game(void *content, Game *game) {
    game->quit = true;
}

static void load(SceneManager **SM, EventHandler **EH)
{
	Tank *tank1 = tankConstructor(newiVec3(200, 200, 0), newVec3(0, 0, 0), 1);

	Scene *gameScene = initScene();
	addEntityToScene(gameScene, tank1);

	*SM = initSceneManager();
	addSceneToSceneManager(*SM, gameScene);

    *EH = initEventHandler();
    addEventToEventHandler(*EH, eventConstructor(SDLK_ESCAPE, &quit_game, NULL));
}

static void init(Game *game, SceneManager *SM, EventHandler *EH) {
	Scene *actualScene = getActualScene(SM);
	initSceneContent(actualScene, EH, game);
}

static void update(Game *game, SceneManager *SM, EventHandler *EH) {
	Scene *actualScene = getActualScene(SM);
	updateSceneContent(actualScene, EH, game);
}

static void render(Game *game, SceneManager *SM, EventHandler *EH) {
	Scene *actualScene = getActualScene(SM);
	renderSceneContent(actualScene, EH, game);
}

int main(void) {
	SceneManager	*SM;
    EventHandler    *EH;
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

	load(&SM, &EH);
	init(&game, SM, EH);
	while (!game.quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_KEYDOWN)
				callEvents(EH, ev.key.keysym.sym, &game);
		}

		const uchar *keyState = SDL_GetKeyboardState(NULL);

		if (keyState[SDL_SCANCODE_ESCAPE])
			game.quit = true;

		bzero(game.pixels, sizeof(game.pixels));

		update(&game, SM, EH);
		render(&game, SM, EH);

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