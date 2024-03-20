#include "vector2.hpp"
#include "vector3.hpp"

using namespace HumongousMath;

int main()
{
    Vector3 v3(1, 2, 3);
    Vector2 v2(1, 2);
    Vector3 v1{1.5, 3.1, 1.2};

    Vector3 v = (v2 + v3 + v1 + v2 + v3) / v1+v2 * v3;
}
