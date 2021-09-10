/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include <random>

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Background.h"

using namespace std;

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
	random_device rd;
	mt19937 mt;
	uniform_real_distribution<float> distributionX, distributionY, distributionVelocity;
	Scene* scene = nullptr;         // gerenciador de cena

	bool viewBBox = false;          // habilita visualiza��o da bounding box
	bool ctrlKeyB = false;          // controle da tecla B

public:
	void Init();                    // inicializa jogo
	void Update();                  // atualiza l�gica do jogo
	void Draw();                    // desenha jogo
	void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif