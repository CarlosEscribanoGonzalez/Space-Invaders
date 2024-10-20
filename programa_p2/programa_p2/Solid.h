#pragma once
#include "Vector3D.h"
#include "Vector2D.h"
#include "Color.h"

class Solid
{
private:
	Vector3D position;
	Vector3D speed;
	Color color;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector2D texCoords;
	bool isTransparent;

public:

	Solid(
		Vector3D positionArgument = Vector3D(),
		Color colorArgument = Color(),
		Vector3D speedArgument = Vector3D(),
		Vector3D orientationArgument = Vector3D(),
		Vector3D orientationSpeedArgument = Vector3D(),
		Vector2D texCoordsArgument = Vector2D()) :
		position(positionArgument),
		color(colorArgument),
		speed(speedArgument),
		orientation(orientationArgument),
		orientationSpeed(orientationSpeedArgument),
		texCoords(texCoordsArgument)
	{
		this->isTransparent = false;
	}

	inline Vector3D GetPosition() const { return this->position; }
	inline Vector3D GetSpeed() const { return this->speed; }
	inline Color GetColor() const { return this->color; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetOrientationSpeed() const { return this->orientationSpeed; }
	inline Vector2D GetTexCoords() const { return this->texCoords; }
	inline bool GetIsTransparent() const { return this->isTransparent; }

	inline void SetPosition(const Vector3D& positionToSet) { this->position = positionToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	inline void SetTexCoords(const Vector2D& texCoordToSet) { this->texCoords = texCoordToSet; }
	inline void SetIsTransparent(const bool& isTransparentToSet) { this->isTransparent = isTransparentToSet; }

	virtual void Render() = 0;
	virtual void Update(const float& time);

};

