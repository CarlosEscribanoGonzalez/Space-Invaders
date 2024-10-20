#pragma once
#include <GL/glut.h>
#include "Solid.h"
class Triangle : public Solid
{
private:

	Vector3D vertex0, vertex1, vertex2;
	Vector3D normal0, normal1, normal2;
	Color color0, color1, color2;
	Vector2D texture0, texture1, texture2;

public:
	Triangle(
		Vector3D vertex0Argument = Vector3D(),
		Vector3D vertex1Argument = Vector3D(),
		Vector3D vertex2Argument = Vector3D(),
		Vector3D normal0Argument = Vector3D(),
		Vector3D normal1Argument = Vector3D(),
		Vector3D normal2Argument = Vector3D(),
		Vector2D texture0Argument = Vector2D(),
		Vector2D texture1Argument = Vector2D(),
		Vector2D texture2Argument = Vector2D(),
		Color color0Argument = Color(1, 0, 0),
		Color color1Argument = Color(0, 1, 0),
		Color color2Argument = Color(0, 0, 1)):
		
		vertex0(vertex0Argument), vertex1(vertex1Argument), vertex2(vertex2Argument),
		normal0(normal0Argument), normal1(normal1Argument), normal2(normal2Argument),
		texture0(texture0Argument), texture1(texture1Argument), texture2(texture2Argument),
		color0(color0Argument), color1(color1Argument), color2(color2Argument) {}

	

	inline Vector3D GetVertex0() const { return this->vertex0; }
	inline Vector3D GetVertex1() const { return this->vertex1; }
	inline Vector3D GetVertex2() const { return this->vertex2; }

	inline Vector3D GetNormal0() const { return this->normal0; }
	inline Vector3D GetNormal1() const { return this->normal1; }
	inline Vector3D GetNormal2() const { return this->normal2; }

	inline Vector2D GetTexture0() const { return this->texture0; }
	inline Vector2D GetTexture1() const { return this->texture1; }
	inline Vector2D GetTexture2() const { return this->texture2; }

	inline Color GetColor0() const { return this->color0; }
	inline Color GetColor1() const { return this->color1; }
	inline Color GetColor2() const { return this->color2; }

	inline void SetColor0(const Color& colorToSet) { this->color0 = colorToSet; }
	inline void SetColor1(const Color& colorToSet) { this->color1 = colorToSet; }
	inline void SetColor2(const Color& colorToSet) { this->color2 = colorToSet; }

	void Render();
};

