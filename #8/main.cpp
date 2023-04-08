#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;

    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator*(double scalar)
    {
        return Point(this->x * scalar, this->y * scalar);
    }

    Point operator+(const Point &other)
    {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point &point)
    {
        return Point(x - point.x, y - point.y);
    }

    Point operator/(Point other)
    {
        return Point(x / other.x, y / other.y);
    }

    Point operator*(Point other)
    {
        return Point(x * other.x, y * other.y);
    }

    double prod()
    {
        return sqrt(x * x + y * y);
    }
};

// divide line in given ratio
Point div_dot(const Point &s, const Point &e, double ratio)
{
    return Point((s.x + ratio * e.x) / (1 + ratio), (s.y + ratio * e.y) / (1 + ratio));
}

Point transpose_point(const Point &point, const Point &a, const Point &b, const Point &d, Point &ratio)
{
    auto n = div_dot(a, b, ratio.x);
    auto m = div_dot(a, d, ratio.y);

    return n + m - a;
}

int main()
{
    const double epsilon = 0.00001;

    double x, y;
    Point a, a1;
    Point b, b1;
    Point c, c1;
    Point d, d1;

    cin >> x >> y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    auto a_ratio = Point(a.x / (x - a.x), a.y / (y - a.y));
    auto b_ratio = Point(b.x / (x - b.x), b.y / (y - b.y));
    auto c_ratio = Point(c.x / (x - c.x), c.y / (y - c.y));
    auto d_ratio = Point(d.x / (x - d.x), d.y / (y - d.y));
    
    while(fabs((a - c).prod()) >= epsilon)
    {
        a1 = transpose_point(a, a, b, d, a_ratio);
        b1 = transpose_point(b, a, b, d, b_ratio);
        c1 = transpose_point(c, a, b, d, c_ratio);
        d1 = transpose_point(d, a, b, d, d_ratio);

        a = a1; 
        b = b1;
        c = c1;
        d = d1;
    }

    Point center = div_dot(a,  c, 0.5);

    cout << center.x << ' ' << center.y;
    return 0;
}
