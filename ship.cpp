#include <iostream>
#include <cmath>

class Vector3
{
    public:
    long double x, y, z;

    Vector2(long double x, long double y) : x(x), y(y) {}
    long double abs()
    {
        return sqrtl(x * x + y * y);
    }
};

class Point3 : public Vector3
{
    public:
    Point3(long double x, long double y, long double z) : Vector2(x, y, z) {}
};

Vector3 vectorFromPoints(Point3& A, Point3& B)
{
    return Vector3(B.x - A.x, B.y - A.y, B.z - A.z);
}

Vector3 crossProduct(Vector3& a, Vector3& b)
{
    return Vector3(a.y * b.z - a.z * b.y, a.x * b.z - a.z * b.x, a.x * b.y - a.y * b.x);
}

class Ship
{
    Point3 origin;
    Vector3 facing;
}

int main(void) {
    return 0;
}
