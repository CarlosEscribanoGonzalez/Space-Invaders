#include "Text.h"
void Text::Render()
{
	glPushMatrix();

	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glRasterPos3d(0, 0, 0);
	for (char c : text) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	glPopMatrix();
}