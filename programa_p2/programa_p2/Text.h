#pragma once
#include <GL/glut.h>
#include "Solid.h"
#include <string>
#include <iostream>

class Text : public Solid
{
private:

	std::string text;

public:

	Text(Vector3D positionArgument,std::string textArgument) : Solid(positionArgument), text(textArgument) {}

	inline std::string GetText() const { return this->text; }
	inline void SetText(const std::string& textToSet) { this->text = textToSet; }
	void Render();
};

