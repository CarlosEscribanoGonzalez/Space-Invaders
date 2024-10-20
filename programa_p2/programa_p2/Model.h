#pragma once
#include "Triangle.h"
#include <GL/glut.h>
#include <vector>
#include <string>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;
public:
	Model() {}

	void AddTriangle(Triangle triangle);
	void PaintColor();
	void Clear();

	void Render();


};

