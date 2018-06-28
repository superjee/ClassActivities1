#include "Mat4.h"
using namespace std;
using namespace mymath;


Mat4::Mat4()
{
}


Mat4::~Mat4()
{
}

mymath::Mat4::Mat4(float diagonal)
{
	setDiagonal(diagonal);
}

mymath::Mat4::Mat4(float * m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			_m[i][j] = *m;
	}
}

Mat4::Mat4(const Vec4<float>& row0
	, const Vec4<float>& row1
	, const Vec4<float>& row2
	, const Vec4<float>& row3)
{
	_m[0][0] = row0.x;
	_m[0][1] = row0.y;
	_m[0][2] = row0.z;
	_m[0][3] = row0.w;

	_m[1][0] = row1.x;
	_m[1][1] = row1.y;
	_m[1][2] = row1.z;
	_m[1][3] = row1.w;

	_m[2][0] = row2.x;
	_m[2][1] = row2.y;
	_m[2][2] = row2.z;
	_m[2][3] = row2.w;

	_m[3][0] = row3.x;
	_m[3][1] = row3.y;
	_m[3][2] = row3.z;
	_m[3][3] = row3.w;
}

void Mat4::print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		std::cout << _m[i][j] << " ";
		std::cout << std::endl;
	}
}

Mat4 & mymath::Mat4::Multiply(const Mat4 & other)
{
	Mat4 Result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float Total = 0.0f;
			for (int a = 0; a < 4; a++)
			{
				Total += _m[i][a] * other._m[a][j];
			}
			Result._m[i][j] = Total;
		}
	}
	return Result;
}

Mat4 & mymath::Mat4::operator*=(const Mat4 & other)
{
	*this = this->Multiply(other);
	return *this;
}

Vec3<float> mymath::Mat4::Multiply(const Vec3<float>& other) const
{
	Vec3<float> Result;
	float Total = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		float Total = 0.0f;

		Total += _m[i][0] * other.x;
		Total += _m[i][1] * other.y;
		Total += _m[i][2] * other.z;
		Total += _m[i][3] * 0;

		if(i == 0)
			Result.x = Total;
		else if(i == 1)
			Result.y = Total;
		else if (i == 2)
			Result.z = Total;	
	}

	return Result;
}

Vec4<float> mymath::Mat4::Multiply(const Vec4<float>& other) const
{
	Vec4<float> Result;
	float Total = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		float Total = 0.0f;

		Total += _m[i][0] * other.x;
		Total += _m[i][1] * other.y;
		Total += _m[i][2] * other.z;
		Total += _m[i][3] * other.w;

		if (i == 0)
			Result.x = Total;
		else if (i == 1)
			Result.y = Total;
		else if (i == 2)
			Result.z = Total;
		else if (i == 3)
			Result.w = Total;
	}

	return Result;
}

void Mat4::setData(int row, Vec4<float>& vec4)
{
	_m[0][row] = vec4.x;
	_m[1][row] = vec4.y;
	_m[2][row] = vec4.z;
	_m[3][row] = vec4.w;
}

void mymath::Mat4::setDiagonal(float diagonal)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				_m[i][j] = diagonal;
			}
			else
			{
				_m[i][j] = 0;
			}
		}
	}
}

Mat4 mymath::operator*(Mat4 left, const Mat4 & right)
{
	return left.Multiply(right);
	/*Mat4 Result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float Total = 0.0f;
			for (int a = 0; a < 4; a++)
			{
				Total += left._m[i][a] * right._m[a][j];
			}
			Result._m[i][j] = Total;
		}
	}
	return Result;*/
}

Vec3<float> mymath::operator*(const Mat4 & left, const Vec3<float>& right)
{
	return left.Multiply(right);
}

Vec4<float> mymath::operator*(const Mat4 & left, const Vec4<float>& right)
{
	return left.Multiply(right);
}
