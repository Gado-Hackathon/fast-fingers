#include "Engine.h"
#include "Resources.h"
#include "Menu.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 620);
	engine->window->Color(255, 255, 255);
	engine->window->Title("FastFingers");
	engine->window->Icon(IDI_ICON);
	int status = engine->Start(new Menu());

	delete engine;
	return status;
}
