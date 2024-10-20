#include "Player.h"
#include "Vector3D.h"


void Player::Action(string comando)
{
	if(comando == "LEFT" && this->player->GetPosition().GetX() > -6)
	{
		this->player->SetPosition(this->player->GetPosition() + Vector3D(-0.15, 0.0, 0.0));
	}
	else if(comando == "RIGHT" && this->player->GetPosition().GetX() < 16)
	{
		this->player->SetPosition(this->player->GetPosition() + Vector3D(0.15, 0.0, 0.0));
	}
}

float Player::GetPosX()
{
	return this->player->GetPosition().GetX();
}

float Player::GetPosY()
{
	return this->player->GetPosition().GetY();
}