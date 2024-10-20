#include "Solid.h"

void Solid::Update(const float& time)
{
	this->SetPosition(this->GetPosition() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
}
