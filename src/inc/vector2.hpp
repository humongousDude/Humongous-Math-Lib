#pragma once

namespace HumongousMath
{
class Vector3;

class Vector2
{
public:
    Vector2() : x(0.0f), y(0.0f){};
    Vector2(float x, float y) : x(x), y(y){};

    operator Vector3();

#pragma region Operators

    bool operator==(Vector2& v) { return x == v.x && y == v.y; }

    Vector2 operator+(Vector2& v);
    Vector2 operator-(Vector2& v);
    Vector2 operator*(Vector2& v);
    Vector2 operator/(Vector2& v);

    Vector2 operator+(Vector3& v);
    Vector2 operator-(Vector3& v);
    Vector2 operator*(Vector3& v);
    Vector2 operator/(Vector3& v);

    Vector2 operator+(float s);
    Vector2 operator-(float s);
    Vector2 operator*(float s);
    Vector2 operator/(float s);

    void operator+=(Vector2& v);
    void operator-=(Vector2& v);
    void operator*=(Vector2& v);
    void operator/=(Vector2& v);

    void operator+=(Vector3& v);
    void operator-=(Vector3& v);
    void operator*=(Vector3& v);
    void operator/=(Vector3& v);

    void operator+=(float s);
    void operator-=(float s);
    void operator*=(float s);
    void operator/=(float s);

#pragma endregion

    float x, y;

    static float Dot(Vector2 v1, Vector2 v2);
    float        Dot(Vector2 v);

    static float Distance(Vector2 v1, Vector2 v2);
    float        Distance(Vector2 v);

    static float DistanceSquared(Vector2 v1, Vector2 v2);
    float        DistanceSquared(Vector2 v);

    static float Length(Vector2 v);
    float        Length();

    static float LengthSquared(Vector2 v);
    float        LengthSquared();

    static void Normalize(Vector2& v);
    void        Normalize();

    static void Lerp(Vector2& v1, Vector2& v2, float t);
    void        Lerp(Vector2& v, float t);

private:
    static float FastInvSqrt(float x)
    {
        float xhalf = 0.5f * x;
        int   i = *(int*)&x;
        i = 0x5f3759df - (i >> 1);
        x = *(float*)&i;
        x = x * (1.5f - xhalf * x * x);
        return x;
    }
};
} // namespace HumongousMath
