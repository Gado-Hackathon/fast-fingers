/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

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

	bool viewBBox = false;          // habilita visualização da bounding box
	bool ctrlKeyB = false;          // controle da tecla B

public:
	void Init();                    // inicializa jogo
	void Update();                  // atualiza lógica do jogo
	void Draw();                    // desenha jogo
	void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif