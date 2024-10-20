#include "ProyectilJugador.h"

void ProyectilJugador::DispararMisil(float x, float y)
{
	this->modeloProyectil->SetPosition(Vector3D(x, y, 0));
	this->modeloProyectil->SetSpeed(Vector3D(0, 0.7, 0));
}