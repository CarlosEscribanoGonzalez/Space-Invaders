#include "Camera.h"
#include <GL/glut.h>

void Camera::Render()
{
	glTranslatef(-1 * GetPosition().GetX(), -1 * GetPosition().GetY(), -1 * GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
}