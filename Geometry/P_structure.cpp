bool same(double a, double b) { return abs(a - b) < 0; }
struct P // 台大
{
    double x, y;
    P() : x(0), y(0) {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(P b) { return P(x + b.x, y + b.y); }
    P operator-(P b) { return P(x - b.x, y - b.y); }
    P operator*(double b) { return P(x * b, y * b); }
    P operator/(double b) { return P(x / b, y / b); }
    double operator*(P b) { return x * b.x + y * b.y; }
    double operator^(P b) { return x * b.y - y * b.x; }
    double abs() { return hypot(x, y); }
    P unit() { return *this / abs(); }
    P spin(double o)
    {
        double c = cos(o), s = sin(o);
        return P(c * x - s * y, s * x + c * y);
    }
    double angle() { return atan2(y, x); }
};