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