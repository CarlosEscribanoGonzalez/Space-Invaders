#include "Game.h"
#include <iostream>
#include <cstdlib>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessKeyReleased(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyReleased(key, px, py);
}

void Game::ProcessKeyArrows(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyArrows(key, px, py);
}

void Game::ProcessKeyArrowsUp(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyArrowsUp(key, px, py);
}

void Game::Init()
{
	cout << "GAME INIT..." << endl;
	
	this->endScene->Init();
	this->mainScene->Init();
	this->activeScene = mainScene;
	this->scenes.push_back(mainScene);
	this->scenes.push_back(endScene);
}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT, puntuacion);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
		this->activeScene = scenes[this->activeScene->GetNextScene()];
	}
}



