//Vector 2D Int 
#pragma once
#define PI 3.14159265
namespace math {

	template <class T>
	T addtest(T right, T left) {
		
		right.x += left.x;
		right.y += left.y;
		/*if(right.z != nullptr)
		right.z += left.z;*/

		return right;
	}

	class Vec2i 
	{
	public:
		Vec2i() {}
		Vec2i(float x, float y);
		virtual ~Vec2i();

		float x,y;

		virtual Vec2i& add(const Vec2i &other);
		virtual Vec2i& subtract(const Vec2i &other);
		virtual Vec2i& multiply(const int &scale);
		virtual Vec2i& divide(const int &scale);

		//overload operator +, -
	    friend Vec2i operator+(Vec2i left, Vec2i right);
	    friend Vec2i operator-(Vec2i left, Vec2i right);
		//friend Vec2i operator*(Vec2i left, Vec2i right);

		virtual bool operator==(const Vec2i &other) const;

		virtual float dot(Vec2i other);
		static float dot(Vec2i &other1,Vec2i &other2);
		virtual float magnitude();
		virtual float mag2();
		Vec2i& normalized();
		float angle();
		float angle(Vec2i other);

		virtual void print();

	};

	class Vec3 : public Vec2i
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

		Vec2i& add(const Vec3 &other) {
			Vec2i::add(other);
			z = z + other.z;
			return *this;
		}
		Vec2i& add(const Vec2i &other) override { return Vec2i::add(other); }

		Vec2i& subtract(const Vec3 &other) {
			Vec2i::subtract(other);
			z = z - other.z;
			return *this;
		}
		Vec2i& subtract(const Vec2i &other) override { return Vec2i::subtract(other); }

		Vec2i& multiply(const int &scale)
		{
			Vec2i::multiply(scale);
			z = z*scale;
			return *this;
		}

		Vec2i& divide(const int &scale)
		{
			Vec2i::divide(scale);
			z = z/scale;
			return *this;
		}

		friend Vec3 operator+(Vec2i left, Vec3 right) {
			right.add(left);
			return right;
		}
		friend Vec3 operator+(Vec3 left, Vec2i right) {
			left.add(right);
			return left;
		}
		friend Vec3 operator+(Vec3 left, Vec3 right) {
			left.add(right);
			return left;
		}

		friend Vec3 operator-(Vec2i left, Vec3 right) {
			left.subtract(right);
			Vec3 dummy(left.x, left.y, -right.z);
			return dummy;
		}
		friend Vec3 operator-(Vec3 left, Vec2i right) {
			left.subtract(right);
			return left;
		}
		friend Vec3 operator-(Vec3 left, Vec3 right) {
			left.subtract(right);
			return left;
		}

		bool operator==(const Vec2i &other) const override { return Vec2i::operator==(other); }
		bool operator==(const Vec3 &other) const {
			if (Vec2i::operator==(other) && z == other.z)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void print() override;

		float dot(Vec2i other) override { return Vec2i::dot(other); }
		float dot(Vec3 other) {
			float xy = Vec2i::dot(other);
			return (z*other.z) + xy;
		}

		Vec3& cross(Vec3 other)
		{
			//return x * other.y - y * other.x;
			Vec3 crossResult(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
			/*crossResult.x = y*other.z - z*other.y;
			crossResult.y = z*other.x - x*other.z;
			crossResult.z = x*other.y - y*other.x;*/
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

	};
}


