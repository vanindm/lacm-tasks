#include <iostream>
#include <cmath>

class Vector2
{
    public:
    long double x, y;

    Vector2(long double x, long double y) : x(x), y(y) {}
};

class Point2 : public Vector2
{
    public:
    Point2(long double x, long double y) : Vector2(x,y) {}
};

long double dotProduct(Vector2& a, Vector2& b)
{
    return a.x * b.x + a.y * b.y;
}

long double skewProduct(Vector2& a, Vector2& b)
{
    return a.x * b.y - a.y * b.x;
}

Vector2 vectorFromPoints(Point2& A, Point2& B)
{
    return Vector2(B.x - A.x, B.y - A.y);
}

int main(void) {
    
    long double x, y;

    std::cin >> x >> y;
    Vector2 a = {x, y};

    std::cin >> x >> y;
    Vector2 b = {x, y};

    std::cin >> x >> y;
    Point2 A = Point2(x, y);

    std::cin >> x >> y;
    Point2 B = Point2(x, y);
    
    Vector2 AB = vectorFromPoints(A, B);

    long double p1 = skewProduct(a, AB);

    long double p2 = skewProduct(AB, b);

    long double p3 = skewProduct(a, b);

    if (std::signbit(p1) == std::signbit(p2) && std::signbit(p2) == std::signbit(p3))
    {
        std::cout << "YES" << std::endl;
    } else 
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
