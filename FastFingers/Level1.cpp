/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#include <fstream>
#include <sstream>

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Pivot.h"
#include "HitLine.h"
#include "Key.h"
#include "Scoreboard.h"
#include "KeyManager.h"
#include "LevelLoader.h"

#include <string>
#include <fstream>

using std::ifstream;
using std::stringstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
	mt = mt19937(rd());
	distributionX = uniform_real_distribution<float>(0.0f, float(window->Width()));
	distributionY = uniform_real_distribution<float>(-200.0f, 0);
	distributionVelocity = uniform_real_distribution<float>(100.0f, 150.0f);

	// cria gerenciador de cena
	scene = new Scene();
	scene->Add(new Background(), STATIC);
	scene->Add(new HitLine(), STATIC);
	// scene->Add(new Key('Q', window->Width() / 2.0f, 200.0f, 100.0f, scene), MOVING);
	// scene->Add(new Key('R', window->Width() / 2.0f - 100, 100.0f, 100.0f, scene), MOVING);
	scene->Add(new Scoreboard(4269), STATIC);
	auto keyManager = new KeyManager(scene);
	keyManager->addAll(loadLevel("Level1.txt"));
	scene->Add(keyManager, STATIC);
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete scene;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	// habilita/desabilita bounding box
	if (ctrlKeyB && window->KeyDown('B'))
	{
		viewBBox = !viewBBox;
		ctrlKeyB = false;
	}
	else if (window->KeyUp('B'))
	{
		ctrlKeyB = true;
	}

	if (window->KeyDown(VK_ESCAPE))
	{
		// volta para a tela de abertura
		Engine::Next<Menu>();
	}
	else if (window->KeyDown('N'))
	{
		// passa manualmente para o pr�ximo n�vel
		Engine::Next<Level2>();
	}
	else
	{
		// atualiza cena
		scene->Update();
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	// desenha cena
	scene->Draw();

	// desenha bounding box dos objetos
	if (viewBBox)
		scene->DrawBBox();
}

// ------------------------------------------------------------------------------