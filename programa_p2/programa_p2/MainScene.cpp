#include "MainScene.h"

void MainScene::Init()
{
	camera.SetPosition(Vector3D(5, 4, 18));

	ModelLoader* loader = new ModelLoader(0.1f);
	Model* naveJugador = new Model();
	loader->LoadModel("..\\..\\3dModels\\naveJugador.obj");
	*naveJugador = loader->GetModel();
	naveJugador->PaintColor();
	naveJugador->SetPosition(Vector3D(5, -5, 0));
	naveJugador->SetOrientation(Vector3D(-90, 90, 0));
	player = new Player(naveJugador);
	this->AddGameObject(naveJugador);

	loader->Clear();

	loader = new ModelLoader(0.4f);
	Model* proyectilJugador = new Model();
	loader->LoadModel("..\\..\\3dModels\\cohete.obj");
	*proyectilJugador = loader->GetModel();
	proyectilJugador->PaintColor();
	proyectilJugador->SetPosition(Vector3D(0, -10.0, 0.0));
	proyectilJugador->SetOrientation(Vector3D(0, 90, 0.0));
	proyectil = new ProyectilJugador(proyectilJugador);
	this->AddGameObject(proyectilJugador);

	loader->Clear();
	

	loader = new ModelLoader(0.3f);
	Model* proyectilE = new Model();
	loader->LoadModel("..\\..\\3dModels\\cohete.obj");
	*proyectilE = loader->GetModel();
	proyectilE->PaintColor();
	proyectilE->SetPosition(Vector3D(0.0, -10.0, 0.0));
	proyectilE->SetOrientation(Vector3D(180, 90, 0.0));
	this->proyectilEnemigo = new ProyectilEnemigo(proyectilE);
	this->AddGameObject(proyectilE);

	loader->Clear();

	for (int i = 0; i < 33; ++i) {
		loader = new ModelLoader(0.5f);
		Model* ufo = new Model();
		loader->LoadModel("..\\..\\3dModels\\ufo.obj");
		*ufo = loader->GetModel();
		if (i < 11)
		{
			ufo->SetPosition(Vector3D(-1 + i * 1.1, 13, 0));
		}
		else if (i < 22 && i >= 11)
		{
			ufo->SetPosition(Vector3D(this->enemigos[i - 11]->GetEnemigo()->GetPosition().GetX(), 12, 0));
		}
		else if (i < 33 && i >= 22)
		{
			ufo->SetPosition(Vector3D(this->enemigos[i - 11]->GetEnemigo()->GetPosition().GetX(), 11, 0));
		}

		if (velocidadJuego <= 0.20)
		{
			ufo->SetSpeed(Vector3D(0.1 + velocidadJuego, 0.0, 0.0));
		}
		else
		{
			ufo->SetSpeed(Vector3D(0.3, 0.0, 0.0));
		}
		
		ufo->PaintColor();
		NaveEnemiga* enemigo = new NaveEnemiga(ufo);
		this->enemigos.push_back(enemigo);
		this->AddGameObject(ufo);

		loader->Clear();
	}
}

void MainScene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void MainScene::Update(const float& time, int& puntos)
{
	puntos = puntuacion;

	this->camera.Update(time);

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(time);
	}

	if (this->proyectil->GetProyectil()->GetPosition().GetY() > 14)
	{
		this->misilActivo = true;
	}
	if (this->pressedLeft)
	{
		this->player->Action("LEFT");
	}
	if (this->pressedRight)
	{
		this->player->Action("RIGHT");
	}
	ImpactoEnAlien();
	ImpactoEnJugador();
	MovimientoAlien();
	contadorTimer++;
	if (contadorTimer % 120 == 0)
	{
		DisparoAlien();
	}
	this->RemoveGameObject(this->textoPuntuacion);
	this->textoPuntuacion = new Text(Vector3D(-3, 10, 6.5), "Puntuacion: " + std::to_string(puntuacion));
	this->AddGameObject(this->textoPuntuacion);
	this->RemoveGameObject(this->textoVidas);
	this->textoVidas = new Text(Vector3D(11.5, 10, 6.5), "Vidas: " + std::to_string(this->player->GetVidas()));
	this->AddGameObject(this->textoVidas);
	
}

void MainScene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	if (key == 'a' || key == 'A')
	{
		this->pressedLeft = true;
	}
	if (key == 'd' || key == 'D')
	{
		this->pressedRight = true;
	}
	if ((key == ' ' || key == 'w' || key == 'W') && this->misilActivo == true)
	{
		this->misilActivo = false;
		this->proyectil->DispararMisil(this->player->GetPosX(), this->player->GetPosY());
	}
}

void MainScene::ProcessKeyReleased(unsigned char key, int px, int py)
{
	if (key == 'a' || key == 'A')
	{
		this->pressedLeft = false;
	}
	if (key == 'd' || key == 'D')
	{
		this->pressedRight = false;
	}
}

void MainScene::ProcessKeyArrows(unsigned char key, int px, int py)
{
	if (key == GLUT_KEY_LEFT)
	{
		this->pressedLeft = true;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		this->pressedRight = true;
	}
}

void MainScene::ProcessKeyArrowsUp(unsigned char key, int px, int py)
{
	if (key == GLUT_KEY_LEFT)
	{
		this->pressedLeft = false;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		this->pressedRight = false;
	}
}

void MainScene::RestartMainScene()
{
	this->RemoveGameObject(this->proyectilEnemigo->GetProyectil());
	this->RemoveGameObject(this->proyectil->GetProyectil());
	this->RemoveGameObject(this->player->GetPlayer());
	this->player->SetVidas(2);
	this->misilActivo = true;
	this->pressedLeft = false;
	this->pressedRight = false;
	
	for (int i = 0; i < 33; ++i)
	{
		this->RemoveGameObject(this->enemigos[i]->GetEnemigo());
	}
	this->enemigos.clear();
	this->Init();
}

void MainScene::ImpactoEnAlien()
{
	int contadorMuertos = 0;
	for (int i = 0; i < 33; i++) {
		if (this->proyectil->GetProyectil()->GetPosition().GetY() > this->enemigos[i]->GetEnemigo()->GetPosition().GetY() - 0.5
			&& this->proyectil->GetProyectil()->GetPosition().GetY() < this->enemigos[i]->GetEnemigo()->GetPosition().GetY() + 0.5
			&& this->proyectil->GetProyectil()->GetPosition().GetX() > this->enemigos[i]->GetEnemigo()->GetPosition().GetX() - 0.5
			&& this->proyectil->GetProyectil()->GetPosition().GetX() < this->enemigos[i]->GetEnemigo()->GetPosition().GetX() + 0.5
			&& this->enemigos[i]->GetEstado() == true)
		{
			this->misilActivo = true;
			this->enemigos[i]->SetEstado(false);
			this->proyectil->GetProyectil()->SetPosition(Vector3D(0, -100, 0));
			this->proyectil->GetProyectil()->SetSpeed(Vector3D(0, 0, 0));
			this->RemoveGameObject(this->enemigos[i]->GetEnemigo());
			this->puntuacion += 20;

		}
		if (this->enemigos[i]->GetEstado() == false)
		{
			contadorMuertos++;
		}
	}
	
	if (contadorMuertos == 33)
	{
		this->velocidadJuego += 0.05;
		RestartMainScene();
	}
}

void MainScene::MovimientoAlien()
{
	for (int i = 0; i < 33; i++) {
		if ((this->enemigos[i]->GetEnemigo()->GetPosition().GetX() >= 16 || this->enemigos[i]->GetEnemigo()->GetPosition().GetX() <= -6)
			&& this->enemigos[i]->GetEstado() == true)
		{
			this->cambioDireccion = true;
		}
		if (this->enemigos[i]->GetEnemigo()->GetPosition().GetY() - 0.5 <= this->player->GetPlayer()->GetPosition().GetY() + 1 && this->enemigos[i]->GetEstado() == true)
		{
			gameOver = true;
		}
	}

	if (this->cambioDireccion == true)
	{
		this->cambioDireccion = false;
		for (int i = 0; i < 33; i++)
		{
			this->enemigos[i]->GetEnemigo()->SetPosition(Vector3D(this->enemigos[i]->GetEnemigo()->GetPosition().GetX(), this->enemigos[i]->GetEnemigo()->GetPosition().GetY() - 0.5, 0.0));
			this->enemigos[i]->GetEnemigo()->SetSpeed(Vector3D(this->enemigos[i]->GetEnemigo()->GetSpeed().GetX() * -1, 0.0, 0.0));
		}
	}
}

void MainScene::DisparoAlien()
{
	int numAleatorio;
	do
	{
		numAleatorio = rand() % 33;
	} while (this->enemigos[numAleatorio]->GetEstado() == false);

	this->proyectilEnemigo->DispararMisil(this->enemigos[numAleatorio]->GetEnemigo()->GetPosition().GetX(), this->enemigos[numAleatorio]->GetEnemigo()->GetPosition().GetY());
}

void MainScene::ImpactoEnJugador()
{
	if (this->proyectilEnemigo->GetProyectil()->GetPosition().GetY() > this->player->GetPlayer()->GetPosition().GetY() - 1
		&& this->proyectilEnemigo->GetProyectil()->GetPosition().GetY() < this->player->GetPlayer()->GetPosition().GetY() + 1
		&& this->proyectilEnemigo->GetProyectil()->GetPosition().GetX() > this->player->GetPlayer()->GetPosition().GetX() - 1
		&& this->proyectilEnemigo->GetProyectil()->GetPosition().GetX() < this->player->GetPlayer()->GetPosition().GetX() + 1)
	{
		this->proyectilEnemigo->GetProyectil()->SetPosition(Vector3D(0.0, -10.0, 0.0));
		this->player->SetVidas(this->player->GetVidas() - 1);
		if (this->player->GetVidas() <= 0)
		{
			gameOver = true;
		}
	}
}

int MainScene::GetNextScene()
{
	if (!gameOver) return 0;
	else
	{
		gameOver = false;
		this->velocidadJuego = 0.05;
		puntuacion = 0;
		RestartMainScene();
		return 1;
	}
}
