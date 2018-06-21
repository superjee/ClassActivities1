#include "Vec2i.hpp"
#include <iostream>
using namespace math;

Vec2i::Vec2i(int x_, int y_)
	:x(x_),y(y_)
{

}


Vec2i::~Vec2i()
{
}

Vec2i& math::Vec2i::add(const Vec2i &other)
{
	x = x + other.x;
	y = y + other.y;
	return *this;
}

Vec2i& math::Vec2i::subtract(const Vec2i &other)
{
	x = x - other.x;
	y = y - other.y;
	return *this;
}

Vec2i& math::Vec2i::multiply(const int &scale)
{
	x = x * scale;
	y = y * scale;
	return *this;
}

Vec2i & math::Vec2i::divide(const int &scale)
{
	x = x / scale;
	y = y / scale;
	return *this;
}



bool math::Vec2i::operator==(const Vec2i & other) const
{
	return(x == other.x) && (y == other.y);
}

float math::Vec2i::dot(Vec2i  other)
{
	return (x*other.x) + (y*other.y);
	
}

float math::Vec2i::dot(Vec2i &other1, Vec2i &other2)
{
	return (other1.x*other2.x) + (other1.y*other2.y);
}

float math::Vec2i::magnitude()
{
	return sqrt(this->mag2());
}

float math::Vec2i::mag2()
{
	return pow(x, 2) + pow(y, 2);
}

Vec2i & math::Vec2i::normalized()
{
	float magn = this->magnitude();
	x /= magn;
	y /= magn;
	return *this;
}

float math::Vec2i::angle()
{
	return atan(y / x) * 180 / PI;
}

float math::Vec2i::angle(Vec2i other)
{
	float dot_product = this->dot(other);
	float this_magnitude = this->magnitude();
	float other_magnitude = other.magnitude();
	return dot_product/(this_magnitude*other_magnitude);
}

void math::Vec2i::print()
{
	std::cout << "v(" << x << "," << y << ")"  << " Magnitude : "<< magnitude() << " Angle : " << angle() << std::endl;
}

Vec2i math::operator+(Vec2i left, Vec2i right)
{
	return left.add(right);
}

Vec2i math::operator-(Vec2i left, Vec2i right)
{
	return left.subtract(right);
}

/*Vec2i math::operator*(Vec2i left, Vec2i right)
{
	Vec2i returnVector;
	returnVector.x = left.x * right.x;
	returnVector.y = left.y * right.y;
	return returnVector;
}*/

/*float math::Vec2i::size(Vec2i other)
{
	return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
}*/
