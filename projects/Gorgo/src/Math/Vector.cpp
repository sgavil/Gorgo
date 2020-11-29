#include "grgpch.h"
#include "Vector.h"


namespace Gorgo {

	Vector::Vector()
		:x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{

	}

	Vector::Vector(float p_x, float p_y, float p_z)
		: x(p_x), y(p_y), z(p_z), w(1.0f)
	{
	}

	Vector::Vector(float p_x, float p_y, float p_z, float p_w)
		: x(p_x), y(p_y), z(p_z), w(p_w)
	{
	}

	Vector Vector::operator*(int p_multNumber) const
	{
		return Vector(x * p_multNumber, y * p_multNumber, z * p_multNumber);
	}

	Vector Vector::operator+(int p_sumNumber) const
	{
		return Vector(x + p_sumNumber, y + p_sumNumber, z + p_sumNumber);
	}

	Vector Vector::operator-(int p_subNumber) const
	{
		return Vector(x - p_subNumber, y - p_subNumber, z - p_subNumber);
	}

	std::ostream& operator<<(std::ostream& p_os, const Vector& p_vector)
	{
		p_os << "(" << p_vector.x << ", " << p_vector.y << ", " << p_vector.z << ", " << p_vector.w << ")";
		return p_os;
	}

}

