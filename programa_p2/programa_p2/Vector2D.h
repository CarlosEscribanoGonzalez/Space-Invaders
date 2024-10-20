#pragma once
class Vector2D
{
private:
	float x;
	float y;
public:
	Vector2D(float x = 0, float y = 0) : x(x), y(y)  {}

	Vector2D(const Vector2D& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
	}

	inline float GetX() const { return this->x; }
	inline float GetY() const { return this->y; }
	inline void SetX(const float& d) { this->x = d; }
	inline void SetY(const float& d) { this->y = d; }

	Vector2D Add(const Vector2D& b);
	Vector2D Substract(const Vector2D& b);
	Vector2D Product(const float& b);
	float DotProduct(const Vector2D& v);

	Vector2D operator+(const Vector2D& b);
	Vector2D operator-(const Vector2D& b);
	Vector2D operator*(const float& b);
	Vector2D operator*(const float& b) const;
	Vector2D operator/(const float& b);
	float operator*(const Vector2D& v);
};
