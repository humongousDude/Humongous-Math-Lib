#include "vector3.hpp"
#include <iostream>

using namespace HumongousMath;

int main()
{
    Vector3  v(1, 2, 3);
    Vector3  v2(12, 22, 33);
    Vector3* v3 = new Vector3(1, 2, 3);

    Vector3::Distance(HumongousMath::Vector3(1, 2, 3), HumongousMath::Vector3(12, 22, 33));

    std::cout << v.Distance(v2);
}
