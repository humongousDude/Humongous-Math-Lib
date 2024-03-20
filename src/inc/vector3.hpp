#pragma once

namespace HumongousMath
{
class Vector2;

class Vector3
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

    Vector3() : x(0.0f), y(0.0f), z(0.0f){};
    Vector3(float x, float y, float z) : x(x), y(y), z(z){};
    explicit Vector3(const VectorType& type)
    {
        switch(type)
        {
            case VectorType::UP:
                x = 0, y = 1, z = 0;
                break;
            case VectorType::DOWN:
                x = 0, y = -1, z = 0;
                break;
            case VectorType::LEFT:
                x = -1, y = 0, z = 0;
                break;
            case VectorType::RIGHT:
                x = 1, y = 0, z = 0;
                break;
            case VectorType::ZERO:
                x = 0, y = 0, z = 0;
                break;
        }
    }

    explicit operator Vector2() const;

#pragma region Operators

    bool operator==(Vector3& v) const { return x == v.x && y == v.y && z == v.z; }

    Vector3 operator+(Vector3& v) const;
    Vector3 operator-(Vector3& v) const;
    Vector3 operator*(Vector3& v) const;
    Vector3 operator/(Vector3& v) const;

    Vector3 operator+(Vector2& v) const;
    Vector3 operator-(Vector2& v) const;
    Vector3 operator*(Vector2& v) const;
    Vector3 operator/(Vector2& v) const;

    Vector3 operator+(float s) const;
    Vector3 operator-(float s) const;
    Vector3 operator*(float s) const;
    Vector3 operator/(float s) const;

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
    [[nodiscard]] float        Dot(Vector3 v) const;

    static Vector3 Cross(Vector3 v1, Vector3 v2);
    [[nodiscard]] Vector3        Cross(Vector3 v) const;

    static float Distance(const Vector3& v1, const Vector3& v2);
    [[nodiscard]] float        Distance(Vector3 v) const;

    static float DistanceSquared(Vector3 v1, Vector3 v2);
    [[nodiscard]] float        DistanceSquared(Vector3 v) const;

    static float Length(Vector3 v);
    [[nodiscard]] float        Length() const;

    static float LengthSquared(Vector3 v);
    [[nodiscard]] float        LengthSquared() const;

    static void Normalize(Vector3& v);
    void        Normalize();

    static void Lerp(Vector3& v1, Vector3& v2, float t);
    void        Lerp(Vector3& v, float t);
};
} // namespace HumongousMath
