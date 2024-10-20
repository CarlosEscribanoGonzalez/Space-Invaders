#pragma once
#include "Proyectil.h"

class ProyectilJugador : public Proyectil
{
public:

	ProyectilJugador(Model* proyectilJugadorArgument) : Proyectil(proyectilJugadorArgument){}

	void DispararMisil(float x, float y);
};

