#pragma once
#ifndef _MAT4
#define _MAT4

#include <iostream>
#include <string>
#include "Vec3.hpp"
#include "Vec4.hpp"
#define PI 3.14159265
namespace mymath {
	//template <class T>
	class Mat4
	{
	public:
		float _m[4][4];

		Mat4();
		~Mat4();
		Mat4(float diagonal);
		Mat4(float* m);
		Mat4(const Vec4<float>& row0
			, const Vec4<float>& row1
			, const Vec4<float>& row2
			, const Vec4<float>& row3);

		void setData(int row , Vec4<float>& vec4);
		void setDiagonal(float diagonal);
		void print();

		Mat4& Multiply(const Mat4& other);
		friend Mat4 operator*(Mat4 left, const Mat4& right);
		Mat4& operator*=(const Mat4& other);

		Vec3<float> Multiply(const Vec3<float>& other) const;
		friend Vec3<float> operator*(const Mat4& left, const Vec3<float>& right);

		Vec4<float> Multiply(const Vec4<float>& other) const;
		friend Vec4<float> operator*(const Mat4& left, const Vec4<float>& right);
		

		//Mat4& Invert();

		static Mat4 Identity();

		static Mat4 Translate(const Vec3<float>& translation);
		static Mat4 Rotate(float angle, const Vec3<float>& axis);
		//static Mat4 Scale(const Vec3<float>& scale);
		//static Mat4 Invert(const Mat4& matrix);
		static Mat4 Transpose(const Mat4& matrix);

		std::string ToString() const;
	};
}
#endif