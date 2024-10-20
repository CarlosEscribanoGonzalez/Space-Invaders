#include "GameOverScene.h"

void GameOverScene::Init()
{
	camera.SetPosition(Vector3D(5, 4, 18));
	textoGameOver = new Text(Vector3D(4.5, 4.5, 6.5), "Game Over");
	restartInfo = new Text(Vector3D(3.0, 1.5, 6.5), "Pulse 'r' para volver a jugar");
	this->AddGameObject(textoGameOver);
	this->AddGameObject(restartInfo);
}

void GameOverScene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void GameOverScene::Update(const float& time, int& puntos)
{
	puntuacion = puntos;
	this->camera.Update(time);

	this->RemoveGameObject(this->textoPuntuacionFinal);
	textoPuntuacionFinal = new Text(Vector3D(4.1, 3, 6.5), "Puntuacion: " + std::to_string(puntuacion));
	this->AddGameObject(textoPuntuacionFinal);

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(time);
	}
}

void GameOverScene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	if (key == 'r' || key == 'R') restart = true;
}

int GameOverScene::GetNextScene()
{
	if (restart)
	{
		restart = false;
		return 0;
	}
	else return 1;
}
