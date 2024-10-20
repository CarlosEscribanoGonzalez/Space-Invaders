#include "Model.h"

void Model::AddTriangle(Triangle triangle)
{
	this->triangles.push_back(triangle);
}

void Model::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glTexCoord2f(GetTexCoords().GetX(), GetTexCoords().GetY());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	
	for (Triangle& triangle : this->triangles)
	{
		triangle.Render();
	}
	
	glPopMatrix();
}

void Model::PaintColor()
{
	for (Triangle& triangle : this->triangles)
	{
		triangle.SetColor0(Color(0.6, 0.2, 1));
		triangle.SetColor1(Color(0.6, 0.2, 1));
		triangle.SetColor2(Color(0.6, 0.2, 1));
	}
}



void Model::Clear()
{
	this->triangles.clear();
}
