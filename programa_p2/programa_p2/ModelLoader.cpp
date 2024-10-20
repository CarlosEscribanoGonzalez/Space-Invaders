#include "ModelLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void ModelLoader::LoadModel(const string& filePath)
{
	ifstream objFile(filePath);
	if (objFile.is_open())
	{
		string line;
		int count = 0;
		while (getline(objFile, line))
		{
			if (line[0] == 'v' && line[1] != 'n' && line[1] != 't')
			{
				Vector3D vertex = this->parseObjLineToVector3D(line);
				this->calcBoundaries(vertex);
				this->vertexes.push_back(vertex);
			}
			else if (line[0] == 'v' && line[1] == 'n')
			{
				Vector3D normal = this->parseObjLineToVector3D(line);
				this->normals.push_back(normal);
			}
			else if (line[0] == 'v' && line[1] == 't')
			{
				Vector2D texCoord = this->parseObjLineToVector2D(line);
				this->textures.push_back(texCoord);
			}
		
			else if (line[0] == 'f')
			{
				Triangle triangle = this->parseObjLineTriangle(line);
				this->model.AddTriangle(this->center(triangle));
			}
		}
		objFile.close();
	}
	else
	{
		cout << "No se ha podido abrir el archivo: " << filePath << endl;
	}

}

Vector3D ModelLoader::parseObjLineToVector3D(const string& line)
{
	string typeOfPoint;
	float xValue, yValue, zValue;
	
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xValue >> yValue >> zValue;

	Vector3D vertex(xValue, yValue, zValue);
	return vertex * this->scale;
	//return vertex;

}

Vector2D ModelLoader::parseObjLineToVector2D(const string& line)
{
	string typeOfPoint;
	float xValue, yValue;

	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xValue >> yValue;

	Vector2D vertex(xValue, yValue);
	return vertex * this->scale;
	//return vertex;

}

Triangle ModelLoader::parseObjLineTriangle(const string& line)
{
	// f 7//10 9//10 3//10
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;
	int idxTexture0, idxTexture1, idxTexture2;

	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> idxTexture0 >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> idxTexture1 >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> idxTexture2 >> c >> idxNormal2;

	Vector3D vertex0 = this->vertexes[idxVertex0 - 1];
	Vector3D vertex1 = this->vertexes[idxVertex1 - 1];
	Vector3D vertex2 = this->vertexes[idxVertex2 - 1];
	Vector3D normal = this->normals[idxNormal0 - 1];
	Vector2D texture = this->textures[idxTexture0 - 1];

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal,texture, texture, texture);
	return parsedTriangle;
}

void ModelLoader::calcBoundaries(Vector3D vertex)
{
	this->maxX = fmax(this->maxX, vertex.GetX());
	this->maxY = fmax(this->maxY, vertex.GetY());
	this->maxZ = fmax(this->maxZ, vertex.GetZ());

	this->minX = fmin(this->minX, vertex.GetX());
	this->minY = fmin(this->minY, vertex.GetY());
	this->minZ = fmin(this->minZ, vertex.GetZ());
}

Triangle ModelLoader::center(Triangle triangle)
{
	Vector3D modelCenter(
		this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0);

	Triangle centered(
		triangle.GetVertex0() - modelCenter,
		triangle.GetVertex1() - modelCenter,
		triangle.GetVertex2() - modelCenter,
		triangle.GetNormal0(),
		triangle.GetNormal1(),
		triangle.GetNormal2(),
		triangle.GetTexture0(),
		triangle.GetTexture1(), 
		triangle.GetTexture2());
	
	return centered;
}

void ModelLoader::Clear()
{
	this->vertexes.clear();
	this->normals.clear();
	this->textures.clear();
	this->model.Clear();
	this->maxX = 0;
	this->maxY = 0;
	this->maxZ = 0;
	this->minX = 0;
	this->minY = 0;
	this->minZ = 0;
}






