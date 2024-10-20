#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Proyectil.h"
#include <string>

class NaveEnemiga
{
private:

	Model* enemigo;
	bool estado = true; 

public:

	NaveEnemiga(Model* enemigoArgument) : enemigo(enemigoArgument) {}

	inline Model* GetEnemigo() { return this->enemigo; };
	inline bool GetEstado() { return this->estado; };
	void SetEstado(bool estado) { this->estado = estado; };
};