#include "ProyectilEnemigo.h"

void ProyectilEnemigo::DispararMisil(float x, float y)
{
	this->modeloProyectil->SetPosition(Vector3D(x, y, 0));

	float orientation = rand() % 20 - 10; //Está en grados, hay que pasarlo a radianes antes de calcular su seno y coseno
	this->modeloProyectil->SetOrientation(Vector3D(0, 0, orientation)); //Todavía sigue en grados para rotar el modelo bien

	orientation = orientation * 3.1415 / 180; //Se pasa a radianes
	this->modeloProyectil->SetSpeed(Vector3D(0.5 * sin(orientation), -0.5 * cos(orientation), 0.0)); //Se calcula la nueva velocidad en ambos ejes
}