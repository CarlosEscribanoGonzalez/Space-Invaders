#pragma once
#include "Model.h"
class Proyectil
{
protected:
    Model* modeloProyectil;

public:
    Proyectil(Model* modeloProyectilArgumento) : modeloProyectil(modeloProyectilArgumento) {}

    Model* GetProyectil() { return this->modeloProyectil; };
    virtual void DispararMisil(float x, float y) = 0;
};

