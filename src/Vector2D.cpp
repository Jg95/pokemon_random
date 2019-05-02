#include "Vector2D.h"

Vector2D::Vector2D(void): x(0), y(0)
{
}

Vector2D::Vector2D(int inx, int iny) :x(inx), y(iny) 
{

}

Vector2D::~Vector2D(void)
{
}

void Vector2D::operator += (Vector2D v2)
{
	 x += v2.x;
	 y += v2.y;
}

void Vector2D::operator -= (Vector2D v2)
{
	x -= v2.x;
	y -= v2.y;
}

Vector2D Vector2D::operator + (Vector2D v2)
{
	Vector2D result;

	result.x = x + v2.x;
	result.y = y + v2.y;

	return result;
}

Vector2D Vector2D::operator - (Vector2D v2)
{
	Vector2D result;

	result.x = x - v2.x;
	result.y = y - v2.y;

	return result;
}

Vector2D Vector2D::operator / (int n)
{
	if (n)
	{
		Vector2D result;

		result.x = (int)(x / n);
		result.y = (int)(y / n);

		return result;
	}

	return Vector2D(0, 0);
}

Vector2D Vector2D::operator * (int n)
{
	Vector2D result;

	result.x = x * n;
	result.y = y * n;

	return result;
}

bool Vector2D::operator==(Vector2D v)
{
	if (x == v.x && y == v.y)
		return true;
	else
		return false;
}

bool Vector2D::operator!=(Vector2D v)
{
	if (x != v.x || y != v.y)
		return true;
	else
		return false;
}
