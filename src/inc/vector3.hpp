#pragma once

namespace HumongousMath
{
class Vector2;

class Vector3
{
public:
    Vector3() : x(0.0f), y(0.0f), z(0.0f){};
    Vector3(float x, float y, float z) : x(x), y(y), z(z){};

    operator Vector2();

#pragma region Operators

    bool operator==(Vector3& v) { return x == v.x && y == v.y && z == v.z; }

    Vector3 operator+(Vector3& v);
    Vector3 operator-(Vector3& v);
    Vector3 operator*(Vector3& v);
    Vector3 operator/(Vector3& v);

    Vector3 operator+(Vector2& v);
    Vector3 operator-(Vector2& v);
    Vector3 operator*(Vector2& v);
    Vector3 operator/(Vector2& v);

    Vector3 operator+(float s);
    Vector3 operator-(float s);
    Vector3 operator*(float s);
    Vector3 operator/(float s);

    void operator+=(Vector3& v);
    void operator-=(Vector3& v);
    void operator*=(Vector3& v);
    void operator/=(Vector3& v);

    void operator+=(Vector2& v);
    void operator-=(Vector2& v);
    void operator*=(Vector2& v);
    void operator/=(Vector2& v);

    void operator+=(float s);
    void operator-=(float s);
    void operator*=(float s);
    void operator/=(float s);

#pragma endregion

    float x, y, z;

    static float Dot(Vector3 v1, Vector3 v2);
    float        Dot(Vector3 v);

    static Vector3 Cross(Vector3 v1, Vector3 v2);
    Vector3        Cross(Vector3 v);

    static float Distance(const Vector3& v1, const Vector3& v2);
    float        Distance(Vector3 v);

    static float DistanceSquared(Vector3 v1, Vector3 v2);
    float        DistanceSquared(Vector3 v);

    static float Length(Vector3 v);
    float        Length();

    static float LengthSquared(Vector3 v);
    float        LengthSquared();

    static void Normalize(Vector3& v);
    void        Normalize();

    static void Lerp(Vector3& v1, Vector3& v2, float t);
    void        Lerp(Vector3& v, float t);
};
} // namespace HumongousMath
