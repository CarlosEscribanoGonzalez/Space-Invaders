#pragma once
#include "Scene.h"

class GameOverScene : public Scene
{
private:
	int puntuacion;
	bool restart;
	Text* textoGameOver;
	Text* restartInfo;
	Text* textoPuntuacionFinal;

public:
	GameOverScene() : restart(false) {}
	void Init();
	void Render();
	void Update(const float& time, int& puntos);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyReleased(unsigned char key, int px, int py) {};
	void ProcessKeyArrows(unsigned char key, int px, int py) {};
	void ProcessKeyArrowsUp(unsigned char key, int px, int py) {};
	int GetNextScene();
};

