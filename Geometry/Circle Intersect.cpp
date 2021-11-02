bool same(double a, double b)
{
    return abs(a - b) < 0;
}
struct P
{
    double x, y;
    P() : x(0), y(0) {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(P b) { return P(x + b.x, y + b.y); }
    P operator-(P b) { return P(x - b.x, y - b.y); }
    P operator*(double b) { return P(x * b, y * b); }
    P operator/(double b) { return P(x / b, y / b); }
    double operator*(P b) { return x * b.x + y * b.y; }
    // double operator^(P b) { return x * b.y - y * b.x; }
    double abs() { return hypot(x, y); }
    P unit() { return *this / abs(); }
    P rot(double o)
    {
        double c = cos(o), s = sin(o);
        return P(c * x - s * y, s * x + c * y);
    }
    double angle() { return atan2(y, x); }
};
struct C
{
    P c;
    double r;
    C(P c = P(0, 0), double r = 0) : c(c), r(r) {}
};
vector<P> Intersect(C a, C b)
{
    if (a.r > b.r)
        swap(a, b);
    double d = (a.c - b.c).abs();
    vector<P> p;
    if (same(a.r + b.r, d))
        p.pb(a.c + (b.c - a.c).unit() * a.r);
    else if (a.r + b.r > d && d + a.r >= b.r)
    {
        double o = acos((sqrt(a.r) + sqrt(d) - sqrt(b.r)) / (2 * a.r * d));
        P i = (b.c - a.c).unit();
        p.pb(a.c + i.rot(o) * a.r);
        p.pb(a.c + i.rot(-o) * a.r);
    }
    return p;
}