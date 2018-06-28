/*#include "Vec2i.hpp"
#include <iostream>
using namespace math;

Vec2::Vec2(float x_, float y_)
	:x(x_),y(y_)
{

}


Vec2::~Vec2()
{
}

Vec2& math::Vec2::add(const Vec2 &other)
{
	x = x + other.x;
	y = y + other.y;
	return *this;
}

Vec2& math::Vec2::subtract(const Vec2 &other)
{
	x = x - other.x;
	y = y - other.y;
	return *this;
}

Vec2& math::Vec2::multiply(const int &scale)
{
	x = x * scale;
	y = y * scale;
	return *this;
}

Vec2 & math::Vec2::divide(const int &scale)
{
	x = x / scale;
	y = y / scale;
	return *this;
}



bool math::Vec2::operator==(const Vec2 & other) const
{
	return(x == other.x) && (y == other.y);
}

float math::Vec2::dot(Vec2  other)
{
	return (x*other.x) + (y*other.y);
	
}

float math::Vec2::dot(Vec2 &other1, Vec2 &other2)
{
	return (other1.x*other2.x) + (other1.y*other2.y);
}

float math::Vec2::magnitude()
{
	return sqrt(this->mag2());
}

float math::Vec2::mag2()
{
	return (x*x) + (y*y);
}

Vec2 & math::Vec2::normalized()
{
	float magn = this->magnitude();
	x /= magn;
	y /= magn;
	return *this;
}

float math::Vec2::angle()
{
	return atan(y / x) * 180 / PI;
}

float math::Vec2::angle(Vec2 other)
{
	float dot_product = this->dot(other);
	float this_magnitude = this->magnitude();
	float other_magnitude = other.magnitude();
	return dot_product/(this_magnitude*other_magnitude) * 180 / PI;
}

void math::Vec2::print()
{
	std::cout << "v(" << x << "," << y << ")"  << " Magnitude : "<< magnitude() << " Angle : " << angle() << std::endl;
}

Vec2 math::operator+(Vec2 left, Vec2 right)
{
	return left.add(right);
}

Vec2 math::operator-(Vec2 left, Vec2 right)
{
	return left.subtract(right);
}

/*Vec2 math::operator*(Vec2 left, Vec2 right)
{
	Vec2 returnVector;
	returnVector.x = left.x * right.x;
	returnVector.y = left.y * right.y;
	return returnVector;
}*/

/*float math::Vec2::size(Vec2 other)
{
	return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
}*/

/*void math::Vec3::print()
{
	std::cout << "v(" << x << "," << y << "," << z << ")" << " Magnitude : " << magnitude() << " Angle : "  << std::endl;
}

float math::Vec3::magnitude()
{
	return sqrt(this->mag2());
}

float math::Vec3::mag2()
{
	return (x*x) + (y, y) + (z, z);
}*/


