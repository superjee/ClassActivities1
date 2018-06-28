#pragma once
#include <iostream>
#define PI 3.14159265
namespace mymath {

	template <class T>
	class Vec3
	{
	public:
		Vec3();
		Vec3(T x, T y, T z);
		~Vec3();

		T x, y, z;

		void print();

		Vec3<T>& add(const Vec3<T> &other);
		Vec3<T>& subtract(const Vec3<T> &other);
		Vec3<T>& multiply(const T &scale);
		Vec3<T>& divide(const T &scale);

		//overload operator +, -
		template <class T>
		friend Vec3<T> operator+(Vec3<T> left, Vec3<T> right);

		template <class T>
		friend Vec3<T> operator-(Vec3<T> left, Vec3<T> right);

		bool operator==(const Vec3<T> &other) const;
		bool operator!=(const Vec3<T> & other) const;

		float dot(Vec3<T> other);
		static float dot(Vec3<T> &other1, Vec3<T> &other2);
		Vec3<T> & cross(Vec3<T> other);
		float magnitude();
		float mag2();
		Vec3<T>& normalized();
		//float angle();
		float angle(Vec3<T> other);

	};

	template <class T>
	Vec3<T>::Vec3()
	{
	}

	template <class T>
	Vec3<T>::Vec3(T x_, T y_, T z_)
		:x(x_), y(y_), z(z_)
	{
	}

	template <class T>
	Vec3<T>::~Vec3()
	{
	}

	template <class T>
	void Vec3<T>::print()
	{
		std::cout << "v(" << x << "," << y << "," << z << ")" << " Magnitude : " << magnitude() << std::endl;//<< " Angle : " << angle() << std::endl;
	}

	template <class T>
	Vec3<T>& Vec3<T>::add(const Vec3<T> &other)
	{
		x = x + other.x;
		y = y + other.y;
		z = z + other.z;
		return *this;
	}

	template <class T>
	Vec3<T>& Vec3<T>::subtract(const Vec3<T> &other)
	{
		x = x - other.x;
		y = y - other.y;
		z = z - other.z;
		return *this;
	}

	template <class T>
	Vec3<T>& Vec3<T>::multiply(const T &scale)
	{
		x = x * scale;
		y = y * scale;
		z = z * scale;
		return *this;
	}

	template <class T>
	Vec3<T> & Vec3<T>::divide(const T &scale)
	{
		x = x / scale;
		y = y / scale;
		z = z / scale;
		return *this;
	}
	//////////////////////////////////////////////////////////////
	template <class T>
	Vec3<T> operator+(Vec3<T> left, Vec3<T> right)
	{
		return left.add(right);
	}

	template <class T>
	Vec3<T> operator-(Vec3<T> left, Vec3<T> right)
	{
		return left.subtract(right);
	}

	template <class T>
	bool Vec3<T>::operator==(const Vec3<T> & other) const
	{
		return(x == other.x) && (y == other.y) && (z == other.z);
	}

	template <class T>
	bool Vec3<T>::operator!=(const Vec3<T> & other) const
	{
		return(x != other.x) || (y != other.y) || (z != other.z);
	}
	/////////////////////////////////////////////////////////////
	template <class T>
	float Vec3<T>::dot(Vec3<T>  other)
	{
		return (x*other.x) + (y*other.y) + (z*other.z);

	}

	template <class T>
	float Vec3<T>::dot(Vec3<T> &other1, Vec3<T> &other2)
	{
		return (other1.x*other2.x) + (other1.y*other2.y) + (other1.z*other2.z);
	}

	template <class T>
	Vec3<T> & Vec3<T>::cross(Vec3<T> other)
	{
		Vec3<T> crossResult(0, 0, 0);
		crossResult.x = y*other.z - z*other.y;
		crossResult.y = z*other.x - x*other.z;
		crossResult.z = x*other.y - y*other.x;
		x = crossResult.x;
		y = crossResult.y;
		z = crossResult.z;
		return *this;
	}


	template <class T>
	float Vec3<T>::magnitude()
	{
		return sqrt(this->mag2());
	}

	template <class T>
	float Vec3<T>::mag2()
	{
		return (x*x) + (y*y) + (z*z);
	}

	template <class T>
	Vec3<T> & Vec3<T>::normalized()
	{
		float magn = this->magnitude();
		x /= magn;
		y /= magn;
		z /= magn;
		return *this;
	}

	template <class T>
	float Vec3<T>::angle(Vec3<T> other)
	{
		float dot_product = this->dot(other);
		float this_magnitude = this->magnitude();
		float other_magnitude = other.magnitude();
		return acos(dot_product / (this_magnitude*other_magnitude)) *180 / PI;
	}
}

