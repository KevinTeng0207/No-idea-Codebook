template <typename T>
struct triangle
{
    point<T> a, b, c;
    triangle() {}
    triangle(const point<T> &a, const point<T> &b, const point<T> &c) : a(a), b(b), c(c) {}
    T area() const
    {
        T t = (b - a).cross(c - a) / 2;
        return t > 0 ? t : -t;
    }
    point<T> barycenter() const
    { //重心
        return (a + b + c) / 3;
    }
    point<T> circumcenter() const
    { //外心
        static line<T> u, v;
        u.p1 = (a + b) / 2;
        u.p2 = point<T>(u.p1.x - a.y + b.y, u.p1.y + a.x - b.x);
        v.p1 = (a + c) / 2;
        v.p2 = point<T>(v.p1.x - a.y + c.y, v.p1.y + a.x - c.x);
        return u.line_intersection(v);
    }
    point<T> incenter() const
    { //內心
        T A = sqrt((b - c).abs2()), B = sqrt((a - c).abs2()), C = sqrt((a - b).abs2());
        return point<T>(A * a.x + B * b.x + C * c.x, A * a.y + B * b.y + C * c.y) / (A + B + C);
    }
    point<T> perpencenter() const
    { //垂心
        return barycenter() * 3 - circumcenter() * 2;
    }
};