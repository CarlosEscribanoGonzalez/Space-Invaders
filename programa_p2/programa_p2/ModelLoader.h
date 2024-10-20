#pragma once
#include "Model.h"
#include <string>

using namespace std;

class ModelLoader
{
private:
	float scale;
	float scale2;
	Model model;
	vector<Vector3D> vertexes;
	vector<Vector3D> normals;
	vector<Vector2D> textures;
	float maxX, maxY, maxZ;
	float minX, minY, minZ;
	inline float getWidth() { return this->maxX - this->minX; }
	inline float getHeight() { return this->maxY - this->minY; }
	inline float getLength() { return this->maxZ - this->minZ; }

	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjLineTriangle(const string& line);
	Vector2D parseObjLineToVector2D(const string& line);

	void calcBoundaries(Vector3D vector);
	Triangle center(Triangle triangle);

public:
	ModelLoader(float scaleArgument = 1.0) : scale(scaleArgument),
		maxX(0), maxY(0), maxZ(0), minX(0), minY(0), minZ(0) {}

	void LoadModel(const string& filePath);

	void Clear();

	inline Model GetModel() { return this->model; }

};

