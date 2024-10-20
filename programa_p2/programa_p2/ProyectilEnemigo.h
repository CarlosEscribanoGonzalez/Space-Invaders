#pragma once
#include "Proyectil.h"

class ProyectilEnemigo : public Proyectil
{
public:

	ProyectilEnemigo(Model* proyectilEnemigoArgument) : Proyectil(proyectilEnemigoArgument){}

	void DispararMisil(float x, float y);
};


