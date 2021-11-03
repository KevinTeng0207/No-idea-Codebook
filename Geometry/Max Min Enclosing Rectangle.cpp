const int maxn = 100; // 凸包點最大數量
const double eps = 1e-10;
const double pi = acos(-1); // PI
int dcmp(double a) { return fabs(a) < eps ? 0 : (a < 0 ? -1 : 1); }
struct p
{
    double x, y;
    void read() {}
    p(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator<(const p &b) const { return dcmp(x - b.x) == -1 || (dcmp(x - b.x) == 0 && dcmp(y - b.y) == -1); }
    bool operator==(const p &b) const { return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0; }
};
typedef vector<p> polygon;
const p seaLevel = p(10, 0);
p operator+(p a, p b) { return p(a.x + b.x, a.y + b.y); }
p operator-(p a, p b) { return p(a.x - b.x, a.y - b.y); }
p operator*(p a, double b) { return p(a.x * b, a.y * b); }
p operator/(p a, double b) { return p(a.x / b, a.y / b); }
p Rotate(p a, double rad) { return p(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)); }
double Dot(p a, p b) { return a.x * b.x + a.y * b.y; }
double Cross(p a, p b) { return a.x * b.y - a.y * b.x; }
double Length(p a) { return sqrt(Dot(a, a)); }
double angle(p a) { return atan2(a.y, a.x); }
double angle(p a, p b) { return atan2(Cross(a, b), Dot(a, b)); }
double turnAngle(p a, p b) { return dcmp(Dot(a, b)) == 1 ? angle(a, b) : pi + angle(a, b); }
p ch[maxn]; // 凸包點
bool Andrew_Monotone_Chain(p a, p b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}
int convexHull(polygon &p) // 凸包
{
    sort(p.begin(), p.end(), Andrew_Monotone_Chain);
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--)
    {
        while (m > k && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) < 0)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1)
        m--;
    return m;
}
double distanceOfpAndLine(p a, p b, p c) { return fabs(Cross(b - a, c - a) / Length(b - c)); }
double Area(int a, int b, int c, int d, p ab, p cd)
{
    double h1 = distanceOfpAndLine(ch[a], ch[b], ch[b] + ab);
    double h2 = distanceOfpAndLine(ch[c], ch[d], ch[d] + cd);
    return h1 * h2;
}

p now; // input
polygon po; // 多邊形
for (int i = 0; i < n; i++)
{
    cin >> now.x >> now.y;
    po.push_back(now); // 輸入點
}
int m = convexHull(po);
if (m < 3)
{
    // 最小外接矩形 = 0
    // 最大外接矩形 = 0
    // 不做下面了
}
ch[m] = ch[0]; 
double Min = 1e20, Max = -1;
double Minx = ch[0].x, Miny = ch[0].y, Maxx = ch[0].x, Maxy = ch[0].y;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
p v1, v2, ori;
ori = v1 = p(1, 0);
v2 = p(0, 1);
for (int i = 1; i < m; i++)
{
    if (dcmp(Minx - ch[i].x) == 1)
        Minx = ch[i].x, p3 = i;
    if (dcmp(Maxx - ch[i].x) == -1)
        Maxx = ch[i].x, p4 = i;
    if (dcmp(Miny - ch[i].y) == 1)
        Miny = ch[i].y, p1 = i;
    if (dcmp(Maxy - ch[i].y) == -1)
        Maxy = ch[i].y, p2 = i;
}
while (dcmp(Cross(ori, v1)) >= 0)
{
    double minRad = 1e20;
    minRad = min(minRad, turnAngle(v1, ch[p1 + 1] - ch[p1]));
    minRad = min(minRad, turnAngle(v1 * (-1), ch[p2 + 1] - ch[p2]));
    minRad = min(minRad, turnAngle(v2 * (-1), ch[p3 + 1] - ch[p3]));
    minRad = min(minRad, turnAngle(v2, ch[p4 + 1] - ch[p4]));
    double l = 0, r = minRad;
    Min = min(Min, Area(p1, p2, p3, p4, Rotate(v1, l), Rotate(v2, l)));
    while (dcmp(l - r))
    {
        double len = (r - l) / 3;
        double midl = l + len;
        double midr = r - len;

        if (dcmp(Area(p1, p2, p3, p4, Rotate(v1, midl), Rotate(v2, midl)) - Area(p1, p2, p3, p4, Rotate(v1, midr), Rotate(v2, midr))) == 1)
            r = midr;
        else
            l = midl;
    }
    Max = max(Max, Area(p1, p2, p3, p4, Rotate(v1, l), Rotate(v2, l)));
    v1 = Rotate(v1, minRad);
    v2 = Rotate(v2, minRad);
    if (dcmp(angle(v1, ch[p1 + 1] - ch[p1])) == 0)
        p1 = (p1 + 1) % m;
    if (dcmp(angle(v1 * (-1), ch[p2 + 1] - ch[p2])) == 0)
        p2 = (p2 + 1) % m;
    if (dcmp(angle(v2 * (-1), ch[p3 + 1] - ch[p3])) == 0)
        p3 = (p3 + 1) % m;
    if (dcmp(angle(v2, ch[p4 + 1] - ch[p4])) == 0)
        p4 = (p4 + 1) % m;
}
// Min = 最小外接矩形
// Max = 最大外接矩形
