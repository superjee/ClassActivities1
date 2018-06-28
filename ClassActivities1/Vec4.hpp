#pragma once
#include <iostream>
#define PI 3.14159265
namespace mymath {
	template <class T>
	class Vec4
	{
	public:
		Vec4();
		Vec4(T x, T y, T z,T w);
		~Vec4();

		T x, y, z,w;

		void print();

		Vec4<T>& add(const Vec4<T> &other);
		Vec4<T>& subtract(const Vec4<T> &other);
		Vec4<T>& multiply(const T &scale);
		Vec4<T>& divide(const T &scale);

		//overload operator +, -
		template <class T>
		friend Vec4<T> operator+(Vec4<T> left, Vec4<T> right);

		template <class T>
		friend Vec4<T> operator-(Vec4<T> left, Vec4<T> right);

		bool operator==(const Vec4<T> &other) const;
		bool operator!=(const Vec4<T> & other) const;

		float dot(Vec4<T> other);
		static float dot(Vec4<T> &other1, Vec4<T> &other2);
		//Vec4<T> & cross(Vec4<T> other);
		float magnitude();
		float mag2();
		Vec4<T>& normalized();
		//float angle();
		//float angle(Vec4<T> other);

	};

	template <class T>
	Vec4<T>::Vec4()
	{
	}

	template <class T>
	Vec4<T>::Vec4(T x_, T y_, T z_, T w_)
		:x(x_), y(y_), z(z_), w(w_)
	{
	}

	template <class T>
	Vec4<T>::~Vec4()
	{
	}

	template <class T>
	void Vec4<T>::print()
	{
		std::cout << "v(" << x << "," << y << "," << z << "," << w << ")" << " Magnitude : " << magnitude() << std::endl; //<< " Angle : " << angle() << std::endl;
	}

	template <class T>
	Vec4<T>& Vec4<T>::add(const Vec4<T> &other)
	{
		x = x + other.x;
		y = y + other.y;
		z = z + other.z;
		w = w + other.w;
		return *this;
	}

	template <class T>
	Vec4<T>& Vec4<T>::subtract(const Vec4<T> &other)
	{
		x = x - other.x;
		y = y - other.y;
		z = z - other.z;
		w = w - other.w;
		return *this;
	}

	template <class T>
	Vec4<T>& Vec4<T>::multiply(const T &scale)
	{
		x = x * scale;
		y = y * scale;
		z = z * scale;
		w = w * scale;
		return *this;
	}

	template <class T>
	Vec4<T> & Vec4<T>::divide(const T &scale)
	{
		x = x / scale;
		y = y / scale;
		z = z / scale;
		w = w / scale;
		return *this;
	}
	//////////////////////////////////////////////////////////////
	template <class T>
	Vec4<T> operator+(Vec4<T> left, Vec4<T> right)
	{
		return left.add(right);
	}

	template <class T>
	Vec4<T> operator-(Vec4<T> left, Vec4<T> right)
	{
		return left.subtract(right);
	}

	template <class T>
	bool Vec4<T>::operator==(const Vec4<T> & other) const
	{
		return(x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
	}

	template <class T>
	bool Vec4<T>::operator!=(const Vec4<T> & other) const
	{
		return(x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
	}
	/////////////////////////////////////////////////////////////
	template <class T>
	float Vec4<T>::dot(Vec4<T>  other)
	{
		return (x*other.x) + (y*other.y) + (z*other.z) + (w*other.w);

	}

	template <class T>
	float Vec4<T>::dot(Vec4<T> &other1, Vec4<T> &other2)
	{
		return (other1.x*other2.x) + (other1.y*other2.y) + (other1.z*other2.z) + (other1.w*other2.w);
	}

	/*template <class T>
	Vec4<T> & Vec4<T>::cross(Vec4<T> other)
	{
		Vec4<T> crossResult(0, 0, 0);
		crossResult.x = y*other.z - z*other.y;
		crossResult.y = z*other.x - x*other.z;
		crossResult.z = x*other.y - y*other.x;
		x = crossResult.x;
		y = crossResult.y;
		z = crossResult.z;
		return *this;
	}*/


	template <class T>
	float Vec4<T>::magnitude()
	{
		return sqrt(this->mag2());
	}

	template <class T>
	float Vec4<T>::mag2()
	{
		return (x*x) + (y*y) + (z*z) + (w*w);
	}

	template <class T>
	Vec4<T> & Vec4<T>::normalized()
	{
		float magn = this->magnitude();
		x /= magn;
		y /= magn;
		z /= magn;
		w /= magn;
		return *this;
	}

	/*template <class T>
	float Vec4<T>::angle(Vec4<T> other)
	{
		float dot_product = this->dot(other);
		float this_magnitude = this->magnitude();
		float other_magnitude = other.magnitude();
		return acos(dot_product / (this_magnitude*other_magnitude)) * 180 / PI;
	}*/
}

