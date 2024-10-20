#include "Vector2D.h"
Vector2D Vector2D::Add(const Vector2D& b)
{
	Vector2D result(x + b.x, y + b.y);
	return result;
}

Vector2D Vector2D::operator+(const Vector2D& b)
{
	Vector2D result(x + b.x, y + b.y);
	return result;
}

Vector2D Vector2D::Substract(const Vector2D& b)
{
	Vector2D result(x - b.x, y - b.y);
	return result;
}

Vector2D Vector2D::operator-(const Vector2D& b)
{
	Vector2D result(x - b.x, y - b.y);
	return result;
}

Vector2D Vector2D::Product(const float& b)
{
	Vector2D result(x * b, y * b);
	return result;
}

Vector2D Vector2D::operator*(const float& b)
{
	Vector2D result(x * b, y * b);
	return result;
}

Vector2D Vector2D::operator*(const float& b) const
{
	Vector2D result(x * b, y * b);
	return result;
}

Vector2D Vector2D::operator/(const float& m)
{
	Vector2D result;
	result.x = x / m;
	result.y = y / m;
	return result;
}

float Vector2D::DotProduct(const Vector2D& v)
{
	float result;
	result = x * v.x + y * v.y;
	return result;
}

float Vector2D::operator*(const Vector2D& v)
{
	float result;
	result = x * v.x + y * v.y;
	return result;
}