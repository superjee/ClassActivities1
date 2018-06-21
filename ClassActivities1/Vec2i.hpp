//Vector 2D Int 
#pragma once
#define PI 3.14159265
namespace math {
	class Vec2i 
	{
	public:
		Vec2i() {}
		Vec2i(int x,int y);
		~Vec2i();

		float x,y;

		Vec2i& add(const Vec2i &other);
		Vec2i& subtract(const Vec2i &other);
		Vec2i& multiply(const int &scale);
		Vec2i& divide(const int &scale);

		//overload operator +, -
		friend Vec2i operator+(Vec2i left, Vec2i right);
		friend Vec2i operator-(Vec2i left, Vec2i right);
		//friend Vec2i operator*(Vec2i left, Vec2i right);

		bool operator==(const Vec2i &other) const;

		float dot(Vec2i other);
		static float dot(Vec2i &other1,Vec2i &other2);
		float magnitude();
		float mag2();
		Vec2i& normalized();
		float angle();
		float angle(Vec2i other);



		void print();
		
	};
}


