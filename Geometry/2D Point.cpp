const double PI = atan2(0.0, -1.0);
template <typename T>
struct point
{
    T x, y;
    point() {}
    point(const T &x, const T &y) : x(x), y(y) {}
    point operator+(const point &b) const
    {
        return point(x + b.x, y + b.y);
    }
    point operator-(const point &b) const
    {
        return point(x - b.x, y - b.y);
    }
    point operator*(const T &b) const
    {
        return point(x * b, y * b);
    }
    point operator/(const T &b) const
    {
        return point(x / b, y / b);
    }
    bool operator==(const point &b) const
    {
        return x == b.x && y == b.y;
    }
    T dot(const point &b) const
    {
        return x * b.x + y * b.y;
    }
    T cross(const point &b) const
    {
        return x * b.y - y * b.x;
    }
    point normal() const
    { //求法向量
        return point(-y, x);
    }
    T abs() const
    { //向量長度的平方
        return sqrt(abs2(p));
    }
    T abs2() const
    { //向量長度的平方
        return dot(*this);
    }
    T rad(const point &b) const
    { //兩向量的弧度
        return fabs(atan2(fabs(cross(b)), dot(b)));
    }
    T getA() const
    {                      //對x軸的弧度
        T A = atan2(y, x); //超過180度會變負的
        if (A <= -PI / 2)
            A += PI * 2;
        return A;
    }
};