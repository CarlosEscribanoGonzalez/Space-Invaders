#pragma once
#include "MainScene.h"
#include "GameOverScene.h"
#include "Player.h"
#include "NaveEnemiga.h"
#include "Proyectil.h"
#include "ProyectilJugador.h"
#include "ProyectilEnemigo.h"
#include "Text.h"
#include <chrono>

using namespace std::chrono;

class Game
{
private:

	const double TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;

	int puntuacion;


	milliseconds initialMilliseconds;
	long lastUpdatedTime;


	Scene* activeScene;
	vector<Scene*> scenes;
	Scene* mainScene = new(nothrow) MainScene;
	Scene* endScene = new(nothrow) GameOverScene;

public:
	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
		lastUpdatedTime(0), puntuacion(0) {}

	void Init();
	void Render();
	void Update();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyReleased(unsigned char key, int px, int py);
	void ProcessKeyArrows(unsigned char key, int px, int py);
	void ProcessKeyArrowsUp(unsigned char key, int px, int py);
};

