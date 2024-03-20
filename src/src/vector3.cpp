#include "vector3.hpp"
#include "utils.hpp"
#include "vector2.hpp"

namespace HumongousMath
{

Vector3::operator Vector2() const { return {x, y}; };

float Vector3::Dot(Vector3 v1, Vector3 v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

float Vector3::Dot(Vector3 v) const { return x * v.x + y * v.y + z * v.z; }

Vector3 Vector3::Cross(Vector3 v1, Vector3 v2) { return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x}; }

Vector3 Vector3::Cross(Vector3 v) const { return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x}; }

float Vector3::Distance(const Vector3& v1, const Vector3& v2)
{
    return 1.0f / Utils::FastInvSqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
}

float Vector3::Distance(Vector3 v) const { return 1.0f / Utils::FastInvSqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z)); }

float Vector3::DistanceSquared(Vector3 v1, Vector3 v2)
{
    return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z);
}

float Vector3::DistanceSquared(Vector3 v) const { return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z); }

float Vector3::Length() const { return 1.0f / Utils::FastInvSqrt(x * x + y * y + z * z); }

float Vector3::Length(Vector3 v) { return 1.0f / Utils::FastInvSqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

float Vector3::LengthSquared() const { return x * x + y * y + z * z; }

float Vector3::LengthSquared(Vector3 v) { return v.x * v.x + v.y * v.y + v.z * v.z; }

void Vector3::Normalize(Vector3& v)
{
    float mag = Length(v);
    if(mag == 0.0f) { return; }

    v.x /= mag;
    v.y /= mag;
    v.z /= mag;
}

void Vector3::Normalize()
{
    float mag = Length();
    if(mag == 0.0f) { return; }

    x /= mag;
    y /= mag;
    z /= mag;
}

void Vector3::Lerp(Vector3& v1, Vector3& v2, float t)
{
    v1.x = v1.x * (1.0f - t) + v2.x * t;
    v1.y = v1.y * (1.0f - t) + v2.y * t;
    v1.z = v1.z * (1.0f - t) + v2.z * t;
}

void Vector3::Lerp(Vector3& v, float t)
{
    x = x * (1.0f - t) + v.x * t;
    y = y * (1.0f - t) + v.y * t;
    z = z * (1.0f - t) + v.z * t;
}

#pragma region Operators

Vector3 Vector3::operator+(Vector3& v) const { return {x + v.x, y + v.y, z + v.z}; }

Vector3 Vector3::operator+(Vector2& v) const { return {x + v.x, y + v.y, z}; }

Vector3 Vector3::operator+(float s) const { return {x + s, y + s, z + s}; }

void Vector3::operator+=(Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector3::operator+=(Vector2& v)
{
    x += v.x;
    y += v.y;
}

void Vector3::operator+=(float s)
{
    x += s;
    y += s;
    z += s;
}

Vector3 Vector3::operator*(Vector3& s) const { return {x * s.x, y * s.y, z * s.z}; }

Vector3 Vector3::operator*(Vector2& s) const { return {x * s.x, y * s.y, z}; }

Vector3 Vector3::operator*(float s) const { return {x * s, y * s, z * s}; }

void Vector3::operator*=(Vector3& s)
{
    x *= s.x;
    y *= s.y;
    z *= s.z;
}

void Vector3::operator*=(Vector2& s)
{
    x *= s.x;
    y *= s.y;
}

void Vector3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
}

Vector3 Vector3::operator-(Vector3& v) const { return {x - v.x, y - v.y, z - v.z}; }

Vector3 Vector3::operator-(Vector2& v) const { return {x - v.x, y - v.y, z}; }

Vector3 Vector3::operator-(float s) const { return {x - s, y - s, z - s}; }

void Vector3::operator-=(Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::operator-=(Vector2& v)
{
    x -= v.x;
    y -= v.y;
}

void Vector3::operator-=(float s)
{
    x -= s;
    y -= s;
    z -= s;
}

Vector3 Vector3::operator/(Vector3& v) const { return {x / v.x, y / v.y, z / v.z}; }

Vector3 Vector3::operator/(Vector2& v) const { return {x / v.x, y / v.y, z}; }

Vector3 Vector3::operator/(float s) const { return {x / s, y / s, z / s}; }

void Vector3::operator/=(Vector3& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
}

void Vector3::operator/=(Vector2& v)
{
    x /= v.x;
    y /= v.y;
}

void Vector3::operator/=(float s)
{
    x /= s;
    y /= s;
    z /= s;
}

#pragma endregion

} // namespace HumongousMath
