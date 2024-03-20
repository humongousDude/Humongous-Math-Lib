#pragma once

namespace HumongousMath
{
class Vector3;

class Vector2
{
public:
     enum class VectorType
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ZERO
    };

    Vector2() : x(0.0f), y(0.0f){}
    Vector2(float x, float y) : x(x), y(y){}
    explicit Vector2(const VectorType& type)
    {
        switch(type)
        {
            case VectorType::UP:
                x = 0, y = 1;
                break;
            case VectorType::DOWN:
                x = 0, y = -1;
                break;
            case VectorType::LEFT:
                x = -1, y = 0;
                break;
            case VectorType::RIGHT:
                x = 1, y = 0;
                break;
            case VectorType::ZERO:
                x = 0, y = 0;
                break;
        }
    }

    explicit operator Vector3() const;

#pragma region Operators

    bool operator==(Vector2& v) const { return x == v.x && y == v.y; }

    Vector2 operator+(Vector2& v) const;
    Vector2 operator-(Vector2& v) const;
    Vector2 operator*(Vector2& v) const;
    Vector2 operator/(Vector2& v) const;

    Vector3 operator+(Vector3& v) const;
    Vector3 operator-(Vector3& v) const;
    Vector3 operator*(Vector3& v) const;
    Vector3 operator/(Vector3& v) const;

    Vector2 operator+(float s) const;
    Vector2 operator-(float s) const;
    Vector2 operator*(float s) const;
    Vector2 operator/(float s) const;

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
    float        Dot(Vector2 v) const;

    static float Distance(Vector2 v1, Vector2 v2);
    float        Distance(Vector2 v) const;

    static float DistanceSquared(Vector2 v1, Vector2 v2);
    float        DistanceSquared(Vector2 v) const;

    static float Length(Vector2 v);
    float        Length() const;

    static float LengthSquared(Vector2 v);
    float        LengthSquared() const;

    static void Normalize(Vector2& v);
    void        Normalize();

    static void Lerp(Vector2& v1, Vector2& v2, float t);
    void        Lerp(Vector2& v, float t);
};
} // namespace HumongousMath
