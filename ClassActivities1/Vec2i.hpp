//Vector 2D Int 
#pragma once
#include <iostream>
#define PI 3.14159265
namespace mymath {

	template <class T>
	class Vec2 
	{
	public:
		Vec2();
		Vec2(T x, T y);
		~Vec2();

		T x,y;

		Vec2<T>& add(const Vec2<T> &other);
		Vec2<T>& subtract(const Vec2<T> &other);
		Vec2<T>& multiply(const T &scale);
		Vec2<T>& divide(const T &scale);

		//overload operator +, -
		template <class T>
	    friend Vec2<T> operator+(Vec2<T> left, Vec2<T> right);

		template <class T>
	    friend Vec2<T> operator-(Vec2<T> left, Vec2<T> right);

		bool operator==(const Vec2<T> &other) const;
		bool operator!=(const Vec2<T> & other) const;

		float dot(Vec2<T> other);
		static float dot(Vec2<T> &other1, Vec2<T> &other2);
		float magnitude();
		float mag2();
		Vec2<T>& normalized();
		float angle();
		float angle(Vec2<T> other);

		void print();

	};

	template <class T>
	Vec2<T>::Vec2()
	{
	}

	template <class T>
	Vec2<T>::Vec2(T x_, T y_)
		:x(x_), y(y_)
	{
	}

	template <class T>
	Vec2<T>::~Vec2()
	{
	}

	template <class T>
	void Vec2<T>::print()
	{
		std::cout << "v(" << x << "," << y << ")" << " Magnitude : " << magnitude() << " Angle : " << angle() << std::endl;
	}

	template <class T>
	Vec2<T>& Vec2<T>::add(const Vec2<T> &other)
	{
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::subtract(const Vec2<T> &other)
	{
		x = x - other.x;
		y = y - other.y;
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::multiply(const T &scale)
	{
		x = x * scale;
		y = y * scale;
		return *this;
	}

	template <class T>
	Vec2<T> & Vec2<T>::divide(const T &scale)
	{
		x = x / scale;
		y = y / scale;
		return *this;
	}
	//////////////////////////////////////////////////////////////
	template <class T>
	Vec2<T> operator+(Vec2<T> left, Vec2<T> right)
	{
		return left.add(right);
	}

	template <class T>
	Vec2<T> operator-(Vec2<T> left, Vec2<T> right)
	{
		return left.subtract(right);
	}

	template <class T>
	bool Vec2<T>::operator==(const Vec2<T> & other) const
	{
		return(x == other.x) && (y == other.y);
	}

	template <class T>
	bool Vec2<T>::operator!=(const Vec2<T> & other) const
	{
		return(x != other.x) || (y != other.y);
	}

	/////////////////////////////////////////////////////////////
	template <class T>
	float Vec2<T>::dot(Vec2<T>  other)
	{
		return (x*other.x) + (y*other.y);

	}

	template <class T>
	float Vec2<T>::dot(Vec2<T> &other1, Vec2<T> &other2)
	{
		return (other1.x*other2.x) + (other1.y*other2.y);
	}

	template <class T>
	float Vec2<T>::magnitude()
	{
		return sqrt(this->mag2());
	}

	template <class T>
	float Vec2<T>::mag2()
	{
		return (x*x) + (y*y);
	}

	template <class T>
	Vec2<T> & Vec2<T>::normalized()
	{
		float magn = this->magnitude();
		x /= magn;
		y /= magn;
		return *this;
	}

	template <class T>
	float Vec2<T>::angle()
	{
		return atan(y / x) * 180 / PI;
	}

	template <class T>
	float Vec2<T>::angle(Vec2<T> other)
	{
		float dot_product = this->dot(other);
		float this_magnitude = this->magnitude();
		float other_magnitude = other.magnitude();
		/*float this_slope = 0, other_slope = 0;
		if(x != 0)
		this_slope = atan(this->y / this->x);
		if (x != 0)
		other_slope = atan(other.y / other.x);

		if (((this->x == other.x) && (this->y == other.y)) 
			|| (this->x == 0 && this->y == 0) 
			|| (other.x == 0 && other.y == 0) 
			|| this_slope == other_slope)
		{
			return 0;
		}
		else*/
		return acos(dot_product / (this_magnitude*other_magnitude))* 180 / PI;
	}

	/*class Vec3 : public Vec2
	{
	public:
		Vec3() {}
		Vec3(float x_, float y_, float z_)
		{
			x = x_;
			y = y_;
			z = z_;
		}

		float z;

		Vec2& add(const Vec3 &other) {
			Vec2::add(other);
			z = z + other.z;
			return *this;
		}
		Vec2& add(const Vec2 &other) override { return Vec2::add(other); }

		Vec2& subtract(const Vec3 &other) {
			Vec2::subtract(other);
			z = z - other.z;
			return *this;
		}
		Vec2& subtract(const Vec2 &other) override { return Vec2::subtract(other); }

		Vec2& multiply(const int &scale)
		{
			Vec2::multiply(scale);
			z = z*scale;
			return *this;
		}

		Vec2& divide(const int &scale)
		{
			Vec2::divide(scale);
			z = z/scale;
			return *this;
		}

		friend Vec3 operator+(Vec2 left, Vec3 right) {
			right.add(left);
			return right;
		}
		friend Vec3 operator+(Vec3 left, Vec2 right) {
			left.add(right);
			return left;
		}
		friend Vec3 operator+(Vec3 left, Vec3 right) {
			left.add(right);
			return left;
		}

		friend Vec3 operator-(Vec2 left, Vec3 right) {
			left.subtract(right);
			Vec3 dummy(left.x, left.y, -right.z);
			return dummy;
		}
		friend Vec3 operator-(Vec3 left, Vec2 right) {
			left.subtract(right);
			return left;
		}
		friend Vec3 operator-(Vec3 left, Vec3 right) {
			left.subtract(right);
			return left;
		}

		bool operator==(const Vec2 &other) const override { return Vec2::operator==(other); }
		bool operator==(const Vec3 &other) const {
			if (Vec2::operator==(other) && z == other.z)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void print() override;

		float dot(Vec2 other) override { return Vec2::dot(other); }
		float dot(Vec3 other) {
			float xy = Vec2::dot(other);
			return (z*other.z) + xy;
		}

		Vec3& cross(Vec3 other)
		{
			Vec3 crossResult(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
			*this = crossResult;
			return *this;
		}

		float magnitude() override;
		float mag2() override;

		/*static float dot(Vec3 &other1, Vec3 &other2);
		Vec3& normalized();
		float angle();
		float angle(Vec3 other);
		*/

	//};*/
}


