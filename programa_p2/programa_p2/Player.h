#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Proyectil.h"
#include <string>

class Player
{
private:

	Model* player;
	int vidas;

public:

	Player(Model* playerArgument):player(playerArgument),vidas(2) {}

	inline Model* GetPlayer(){return this->player;};
	inline int GetVidas(){ return this->vidas; };
	void SetVidas(int vidas) { this->vidas = vidas; };
	void Action(string comando);
	float GetPosX();
	float GetPosY();
};
