#pragma once

#include <random>

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Background.h"

using namespace std;

class Level : public Game
{
private:
	random_device rd;
	mt19937 mt;
	uniform_real_distribution<float> distributionX, distributionY, distributionVelocity;
	Scene* scene = nullptr;         // gerenciador de cena
	string fileName;

	bool viewBBox = false;          // habilita visualiza��o da bounding box
	bool ctrlKeyB = false;          // controle da tecla B

public:
	Level(const string& fileName);

	void Init();                    // inicializa jogo
	virtual void Update();          // atualiza l�gica do jogo
	void Draw();                    // desenha jogo
	void Finalize();                // finaliza jogo
};
