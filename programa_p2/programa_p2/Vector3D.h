#pragma once
template <class S> class Vector3Dx;

typedef Vector3Dx<float> Vector3D;

template <class S> class Vector3Dx
{
private:
	S x;
	S y;
	S z;
public:
	Vector3Dx(S x = 0, S y = 0, S z = 0) : x(x), y(y), z(z) {}

	Vector3Dx(const Vector3Dx& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
	}

	inline S GetX() const { return this->x; }
	inline S GetY() const { return this->y; }
	inline S GetZ() const { return this->z; }
	inline void SetX(const S& d) { this->x = d; }
	inline void SetY(const S& d) { this->y = d; }
	inline void SetZ(const S& d) { this->z = d; }


	Vector3Dx<S> Add(const Vector3Dx<S>& b)
	{
		Vector3Dx<S> result(x + b.x, y + b.y, z + b.z);
		return result;
	}

	Vector3Dx<S> operator+(const Vector3Dx<S>& b)
	{
		Vector3Dx<S> result(x + b.x, y + b.y, z + b.z);
		return result;
	}

	Vector3Dx<S> Substract(const Vector3Dx<S>& b)
	{
		Vector3Dx<S> result(x - b.x, y - b.y, z - b.z);
		return result;
	}

	Vector3Dx<S> operator-(const Vector3Dx<S>& b)
	{
		Vector3Dx<S> result(x - b.x, y - b.y, z - b.z);
		return result;
	}

	Vector3Dx<S> Product(const S& b)
	{
		Vector3Dx<S> result(x * b, y * b, z * b);
		return result;
	}

	Vector3Dx<S> operator*(const S& b)
	{
		Vector3Dx<S> result(x * b, y * b, z * b);
		return result;
	}

	Vector3Dx<S> operator/(const Vector3Dx<S>& m)
	{
		Vector3Dx<S> result;
		result.x = x / m;
		result.y = y / m;
		result.z = z / m;
		return result;
	}

	S DotProduct(const Vector3Dx<S>& v)
	{
		S result;
		result = x * v.x + y * v.y + z * v.z;
		return result;
	}

	S operator*(const Vector3Dx<S>& v)
	{
		S result;
		result = x * v.x + y * v.y + z * v.z;
		return result;
	}
};

