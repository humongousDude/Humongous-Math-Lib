#include "vector2.hpp"
#include "utils.hpp"
#include "vector3.hpp"

namespace HumongousMath
{
Vector2::operator Vector3() { return Vector3(x, y, 0); }

float Vector2::Dot(Vector2 v1, Vector2 v2) { return v1.x * v2.x + v1.y * v2.y; }

float Vector2::Dot(Vector2 v) { return x * v.x + y * v.y; }

float Vector2::Distance(Vector2 v1, Vector2 v2) { return 1.0f / Utils::FastInvSqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)); }

float Vector2::Distance(Vector2 v) { return 1.0f / Utils::FastInvSqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y)); }

} // namespace HumongousMath
