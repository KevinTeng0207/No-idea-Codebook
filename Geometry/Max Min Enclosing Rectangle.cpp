const double PI = atan2(0.0, -1.0);
const double eps = 1e-10;
typedef point<double> p; // data type 依照題目更改
int mycmp(double a) { return fabs(a) < eps ? 0 : (a < 0 ? -1 : 1); }
double Length(p a) { return sqrt(a.dot(a)); }
p Rotate(p a, double rad) { return p(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)); }
double angle(p a) { return atan2(a.y, a.x); }
double angle(p a, p b) { return atan2(a.cross(b), a.dot(b)); }
double turnAngle(p a, p b) { return mycmp(a.dot(b)) == 1 ? angle(a, b) : PI + angle(a, b); }
double distanceOfpAndLine(p a, p b, p c) { return fabs((b - a).cross(c - a) / Length(b - c)); }
double Area(int a, int b, int c, int d, p ab, p cd, polygon<double> po)
{
    double h1 = distanceOfpAndLine(po.p[a], po.p[b], po.p[b] + ab);
    double h2 = distanceOfpAndLine(po.p[c], po.p[d], po.p[d] + cd);
    return h1 * h2;
}
double max_enclose(polygon<double> po)
{
    po.p.pb(po.p[0]);
    int m = po.p.size();
    if (m < 3)
        return 0; // 沒凸包哪來外包矩形
    double Max = -1;
    double Minx = po.p[0].x, Miny = po.p[0].y, Maxx = po.p[0].x, Maxy = po.p[0].y;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    p v1, v2, ori;
    ori = v1 = p(1, 0);
    v2 = p(0, 1);
    for (int i = 1; i < m; i++)
    {
        if (mycmp(Minx - po.p[i].x) == 1)
            Minx = po.p[i].x, p3 = i;
        if (mycmp(Maxx - po.p[i].x) == -1)
            Maxx = po.p[i].x, p4 = i;
        if (mycmp(Miny - po.p[i].y) == 1)
            Miny = po.p[i].y, p1 = i;
        if (mycmp(Maxy - po.p[i].y) == -1)
            Maxy = po.p[i].y, p2 = i;
    }
    while (mycmp(ori.cross(v1)) >= 0)
    {
        double minRad = 1e20;
        minRad = min(minRad, turnAngle(v1, po.p[p1 + 1] - po.p[p1]));
        minRad = min(minRad, turnAngle(v1 * (-1), po.p[p2 + 1] - po.p[p2]));
        minRad = min(minRad, turnAngle(v2 * (-1), po.p[p3 + 1] - po.p[p3]));
        minRad = min(minRad, turnAngle(v2, po.p[p4 + 1] - po.p[p4]));
        double l = 0, r = minRad;
        while (mycmp(l - r))
        {
            double len = (r - l) / 3;
            double midl = l + len;
            double midr = r - len;

            if (mycmp(Area(p1, p2, p3, p4, Rotate(v1, midl), Rotate(v2, midl), po) - Area(p1, p2, p3, p4, Rotate(v1, midr), Rotate(v2, midr), po)) == 1)
                r = midr;
            else
                l = midl;
        }
        Max = max(Max, Area(p1, p2, p3, p4, Rotate(v1, l), Rotate(v2, l), po));
        v1 = Rotate(v1, minRad);
        v2 = Rotate(v2, minRad);
        if (mycmp(angle(v1, po.p[p1 + 1] - po.p[p1])) == 0)
            p1 = (p1 + 1) % m;
        if (mycmp(angle(v1 * (-1), po.p[p2 + 1] - po.p[p2])) == 0)
            p2 = (p2 + 1) % m;
        if (mycmp(angle(v2 * (-1), po.p[p3 + 1] - po.p[p3])) == 0)
            p3 = (p3 + 1) % m;
        if (mycmp(angle(v2, po.p[p4 + 1] - po.p[p4])) == 0)
            p4 = (p4 + 1) % m;
    }
    return Max;
}