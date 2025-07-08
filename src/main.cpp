#include "window.hpp"
#include "SpriteAnimations.hpp"
#include "AssetManager.hpp"

int main(int argc, char* argv[]) {
	VFS::init();

	WindowContext win("Sprite Foundry", { 1280,720 }, SDL_WINDOW_RESIZABLE);
	auto& assets = AssetManager::get();
	assets.init(win.renderer);

	assets.registerAsset<Texture>("logo", VFS::resolve("SpriteFoundry_logo.png").path.string());
	
	//auto logo = assets.use<Texture>("logo");

	while (win.appState) {
		win.startFrame();

		SDL_SetRenderDrawColor(win.renderer, 40, 40, 40, 255);
		SDL_RenderClear(win.renderer);

		renderTexture(win.renderer, SDL_Point{ (int)(635 - 486 / 2), (int)(360 - 97 / 2)}, "logo");


		win.endFrame();
	}

	return 0;

}