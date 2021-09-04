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
bool operator<(const P &a, const P &b) { return same(a.x, b.x) ? a.y < b.y : a.x < b.x; }
bool operator>(const P &a, const P &b) { return same(a.x, b.x) ? a.y > b.y : a.x > b.x; }
#define crx(a, b, c) ((b - a) ^ (c - a)) // (向量OA叉積向量OB。) > 0 表示從OA到OB為逆時針旋轉。
vector<P> convex(vector<P> ps) // Andrew's Monotone Chain
{
    vector<P> p;

    sort(ps.begin(), ps.end(), [](P &a, P &b)
         { return a.y < b.y || (a.y == b.y && a.x < b.x); });
    for (int i = 0; i < ps.size(); ++i)
    {
        while (p.size() >= 2 && crx(p[p.size() - 2], ps[i], p[p.size() - 1]) >= 0)
            p.pop_back();
        p.push_back(ps[i]);
    }
    int t = p.size();
    for (int i = (int)ps.size() - 2; i >= 0; --i)
    {
        while (p.size() > t && crx(p[p.size() - 2], ps[i], p[p.size() - 1]) >= 0)
            p.pop_back();
        p.push_back(ps[i]);
    }
    // p.pop_back(); //起點依照題目
    return p;
}