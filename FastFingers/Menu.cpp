/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Menu.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Menu::Init()
{
	background = new Sprite("Resources/Menu.png");
}

// ------------------------------------------------------------------------------

void Menu::Finalize()
{
	delete background;
}

// ------------------------------------------------------------------------------

void Menu::Update()
{
	// sai do jogo com a tecla ESC
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
	{
		ctrlKeyESC = false;
		window->Close();
	}
	else if (window->KeyUp(VK_ESCAPE))
	{
		ctrlKeyESC = true;
	}

	// passa ao primeiro nível com ENTER
	if (window->KeyDown(VK_SPACE))
		Engine::Next(new Level1());
}

// ------------------------------------------------------------------------------

void Menu::Draw()
{
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------