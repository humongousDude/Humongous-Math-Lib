#include "vector2.hpp"
#include "utils.hpp"
#include "vector3.hpp"

namespace HumongousMath
{
Vector2::operator Vector3() const { return {x, y, 0}; }

float Vector2::Dot(Vector2 v1, Vector2 v2) { return v1.x * v2.x + v1.y * v2.y; }

float Vector2::Dot(Vector2 v) const { return x * v.x + y * v.y; }

float Vector2::Distance(Vector2 v1, Vector2 v2) { return 1.0f / Utils::FastInvSqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)); }

float Vector2::Distance(Vector2 v) const { return 1.0f / Utils::FastInvSqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y)); }

float Vector2::DistanceSquared(Vector2 v) const { return ((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y)); }

float Vector2::DistanceSquared(Vector2 v1, Vector2 v2) { return ((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)); }

float Vector2::Length(Vector2 v) { return 1.0f / Utils::FastInvSqrt(v.x * v.x + v.y * v.y); }

float Vector2::Length() const { return 1.0f / Utils::FastInvSqrt(x * x + y * y); }

float Vector2::LengthSquared() const { return (x * x + y * y); }

float Vector2::LengthSquared(Vector2 v) { return (v.x * v.x + v.y * v.y); }

void Vector2::Normalize(Vector2& v)
{
    float mag = Length(v);
    if(mag == 0.0f) { return; }

    v /= mag;
}

void Vector2::Normalize()
{

    float mag = Length();
    if(mag == 0.0f) { return; }
    *this /= mag;
}

void Vector2::Lerp(Vector2& v, float t)
{
    x = x * (1.0f - t) + v.x * t;
    y = y * (1.0f - t) + v.y * t;
}

void Vector2::Lerp(Vector2& v1, Vector2& v2, float t)
{
    v1.x = v1.x * (1.0f - t) + v2.x * t;
    v1.y = v1.y * (1.0f - t) + v2.y * t;
}

#pragma region Operators

Vector2 Vector2::operator+(Vector2& v) const { return {x + v.x, y + v.y}; }

Vector3 Vector2::operator+(Vector3& v) const { return {x + v.x, y + v.y, 0}; }

Vector2 Vector2::operator+(float s) const { return {x + s, y + s}; }

void Vector2::operator+=(Vector2& v)
{
    x += v.x;
    y += v.y;
}

void Vector2::operator+=(Vector3& v)
{
    x += v.x;
    y += v.y;
}

void Vector2::operator+=(float s)
{
    x += s;
    y += s;
}

Vector2 Vector2::operator*(Vector2& s) const { return {x * s.x, y * s.y}; }

Vector3 Vector2::operator*(Vector3& s) const { return {x * s.x, y * s.y, s.z}; }

Vector2 Vector2::operator*(float s) const { return{x * s, y * s}; }

void Vector2::operator*=(Vector2& s)
{
    x *= s.x;
    y *= s.y;
}

void Vector2::operator*=(Vector3& s)
{
    x *= s.x;
    y *= s.y;
}

void Vector2::operator*=(float s)
{
    x *= s;
    y *= s;
}

Vector2 Vector2::operator-(Vector2& v) const { return {x - v.x, y - v.y}; }

Vector3 Vector2::operator-(Vector3& v) const { return {x - v.x, y - v.y, v.z}; }

Vector2 Vector2::operator-(float s) const { return {x - s, y - s}; }

void Vector2::operator-=(Vector2& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2::operator-=(Vector3& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2::operator-=(float s)
{
    x -= s;
    y -= s;
}

Vector2 Vector2::operator/(Vector2& v) const { return {x / v.x, y / v.y}; }

Vector3 Vector2::operator/(Vector3& v) const { return {x / v.x, y / v.y, v.z}; }

Vector2 Vector2::operator/(float s) const { return {x / s, y / s}; }

void Vector2::operator/=(Vector2& v)
{
    x /= v.x;
    y /= v.y;
}

void Vector2::operator/=(Vector3& v)
{
    x /= v.x;
    y /= v.y;
}

void Vector2::operator/=(float s)
{
    x /= s;
    y /= s;
}
#pragma endregion

} // namespace HumongousMath
