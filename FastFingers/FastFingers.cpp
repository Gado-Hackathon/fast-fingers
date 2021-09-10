/**********************************************************************************
// PacMan (C�digo Fonte)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exerc�cio sobre detec��o de colis�o
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine* engine = new Engine();

	// configura a janela do jogo
	engine->window->Mode(BORDERLESS);
	engine->window->Size(960, 620);
	engine->window->Color(255, 255, 255);
	engine->window->Title("FastFingers");
	engine->window->Icon(IDI_ICON);

	// configura dispositivo gr�fico
	//engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new Menu());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------

