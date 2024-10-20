#pragma once
#include "Scene.h"
#include "Player.h"
#include "ProyectilJugador.h"
#include "ProyectilEnemigo.h"
#include "NaveEnemiga.h"

class MainScene : public Scene
{
private:
	bool misilActivo;
	bool gameOver;
	bool cambioDireccion;
	bool pressedLeft;
	bool pressedRight;
	float velocidadJuego;
	int contadorTimer;
	int puntuacion;

	Player* player;
	ProyectilJugador* proyectil;
	ProyectilEnemigo* proyectilEnemigo;
	vector<NaveEnemiga*> enemigos;
	Text* textoPuntuacion;
	Text* textoVidas;

public:
	MainScene() : misilActivo(true), cambioDireccion(false), gameOver(false), 
		pressedLeft(false), pressedRight(false), velocidadJuego(0.05), contadorTimer(0), puntuacion(0) {}

	void Init();
	void Render();
	void Update(const float& time, int& puntos);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyReleased(unsigned char key, int px, int py);
	void ProcessKeyArrows(unsigned char key, int px, int py);
	void ProcessKeyArrowsUp(unsigned char key, int px, int py);
	void RestartMainScene();
	void ImpactoEnAlien();
	void MovimientoAlien();
	void ImpactoEnJugador();
	void DisparoAlien();
	int GetNextScene();
};
