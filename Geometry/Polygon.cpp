template <typename T>
struct polygon
{
    polygon() {}
    vector<point<T>> p; //逆時針順序
    T area() const
    { //面積
        T ans = 0;
        for (int i = p.size() - 1, j = 0; j < (int)p.size(); i = j++)
            ans += p[i].cross(p[j]);
        return ans / 2;
    }
    point<T> center_of_mass() const
    { //重心
        T cx = 0, cy = 0, w = 0;
        for (int i = p.size() - 1, j = 0; j < (int)p.size(); i = j++)
        {
            T a = p[i].cross(p[j]);
            cx += (p[i].x + p[j].x) * a;
            cy += (p[i].y + p[j].y) * a;
            w += a;
        }
        return point<T>(cx / 3 / w, cy / 3 / w);
    }
    char ahas(const point<T> &t) const
    { //點是否在簡單多邊形內，是的話回傳1、在邊上回傳-1、否則回傳0
        bool c = 0;
        for (int i = 0, j = p.size() - 1; i < p.size(); j = i++)
            if (line<T>(p[i], p[j]).point_on_segment(t))
                return -1;
            else if ((p[i].y > t.y) != (p[j].y > t.y) &&
                     t.x < (p[j].x - p[i].x) * (t.y - p[i].y) / (p[j].y - p[i].y) + p[i].x)
                c = !c;
        return c;
    }
    char point_in_convex(const point<T> &x) const
    {
        int l = 1, r = (int)p.size() - 2;
        while (l <= r)
        { //點是否在凸多邊形內，是的話回傳1、在邊上回傳-1、否則回傳0
            int mid = (l + r) / 2;
            T a1 = (p[mid] - p[0]).cross(x - p[0]);
            T a2 = (p[mid + 1] - p[0]).cross(x - p[0]);
            if (a1 >= 0 && a2 <= 0)
            {
                T res = (p[mid + 1] - p[mid]).cross(x - p[mid]);
                return res > 0 ? 1 : (res >= 0 ? -1 : 0);
            }
            else if (a1 < 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return 0;
    }
    vector<T> getA() const
    {//凸包邊對x軸的夾角
        vector<T> res; //一定是遞增的
        for (size_t i = 0; i < p.size(); ++i)
            res.push_back((p[(i + 1) % p.size()] - p[i]).getA());
        return res;
    }
    bool line_intersect(const vector<T> &A, const line<T> &l) const
    { //O(logN)
        int f1 = upper_bound(A.begin(), A.end(), (l.p1 - l.p2).getA()) - A.begin();
        int f2 = upper_bound(A.begin(), A.end(), (l.p2 - l.p1).getA()) - A.begin();
        return l.cross_seg(line<T>(p[f1], p[f2]));
    }
    polygon cut(const line<T> &l) const
    { //凸包對直線切割，得到直線l左側的凸包
        polygon ans;
        for (int n = p.size(), i = n - 1, j = 0; j < n; i = j++)
        {
            if (l.ori(p[i]) >= 0)
            {
                ans.p.push_back(p[i]);
                if (l.ori(p[j]) < 0)
                    ans.p.push_back(l.line_intersection(line<T>(p[i], p[j])));
            }
            else if (l.ori(p[j]) > 0)
                ans.p.push_back(l.line_intersection(line<T>(p[i], p[j])));
        }
        return ans;
    }
    static bool graham_cmp(const point<T> &a, const point<T> &b)
    { //凸包排序函數 // 起始點不同 
        // return (a.x < b.x) || (a.x == b.x && a.y < b.y);  //最左下角開始
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);  //Y最小開始
    }
    void graham(vector<point<T>> &s)
    { //凸包 Convexhull 2D
        sort(s.begin(), s.end(), graham_cmp);
        p.resize(s.size() + 1);
        int m = 0;
        // cross >= 0 順時針。cross <= 0 逆時針旋轉
        for (size_t i = 0; i < s.size(); ++i)
        {
            while (m >= 2 && (p[m - 1] - p[m - 2]).cross(s[i] - p[m - 2]) <= 0)
                --m;
            p[m++] = s[i];
        }
        for (int i = s.size() - 2, t = m + 1; i >= 0; --i)
        {
            while (m >= t && (p[m - 1] - p[m - 2]).cross(s[i] - p[m - 2]) <= 0)
                --m;
            p[m++] = s[i];
        }
        if (s.size() > 1) // 重複頭一次需扣掉
            --m;
        p.resize(m);
    }
    T diam()
    { //直徑
        int n = p.size(), t = 1;
        T ans = 0;
        p.push_back(p[0]);
        for (int i = 0; i < n; i++)
        {
            point<T> now = p[i + 1] - p[i];
            while (now.cross(p[t + 1] - p[i]) > now.cross(p[t] - p[i]))
                t = (t + 1) % n;
            ans = max(ans, (p[i] - p[t]).abs2());
        }
        return p.pop_back(), ans;
    }
    T min_cover_rectangle()
    { // 先做凸包 //最小覆蓋矩形 
        int n = p.size(), t = 1, r = 1, l;
        if (n < 3)
            return 0; //也可以做最小周長矩形
        T ans = 1e99;
        p.push_back(p[0]);
        for (int i = 0; i < n; i++)
        {
            point<T> now = p[i + 1] - p[i];
            while (now.cross(p[t + 1] - p[i]) > now.cross(p[t] - p[i]))
                t = (t + 1) % n;
            while (now.dot(p[r + 1] - p[i]) > now.dot(p[r] - p[i]))
                r = (r + 1) % n;
            if (!i)
                l = r;
            while (now.dot(p[l + 1] - p[i]) <= now.dot(p[l] - p[i]))
                l = (l + 1) % n;
            T d = now.abs2();
            T tmp = now.cross(p[t] - p[i]) * (now.dot(p[r] - p[i]) - now.dot(p[l] - p[i])) / d;
            ans = min(ans, tmp);
        }
        return p.pop_back(), ans;
    }
    T dis2(polygon &pl)
    { //凸包最近距離平方
        vector<point<T>> &P = p, &Q = pl.p;
        int n = P.size(), m = Q.size(), l = 0, r = 0;
        for (int i = 0; i < n; ++i)
            if (P[i].y < P[l].y)
                l = i;
        for (int i = 0; i < m; ++i)
            if (Q[i].y < Q[r].y)
                r = i;
        P.push_back(P[0]), Q.push_back(Q[0]);
        T ans = 1e99;
        for (int i = 0; i < n; ++i)
        {
            while ((P[l] - P[l + 1]).cross(Q[r + 1] - Q[r]) < 0)
                r = (r + 1) % m;
            ans = min(ans, line<T>(P[l], P[l + 1]).seg_dis2(line<T>(Q[r], Q[r + 1])));
            l = (l + 1) % n;
        }
        return P.pop_back(), Q.pop_back(), ans;
    }
    static char sign(const point<T> &t)
    {
        return (t.y == 0 ? t.x : t.y) < 0;
    }
    static bool angle_cmp(const line<T> &A, const line<T> &B)
    {
        point<T> a = A.p2 - A.p1, b = B.p2 - B.p1;
        return sign(a) < sign(b) || (sign(a) == sign(b) && a.cross(b) > 0);
    }
    int halfplane_intersection(vector<line<T>> &s)
    {  //半平面交
        sort(s.begin(), s.end(), angle_cmp); //線段左側為該線段半平面
        int L, R, n = s.size();
        vector<point<T>> px(n);
        vector<line<T>> q(n);
        q[L = R = 0] = s[0];
        for (int i = 1; i < n; ++i)
        {
            while (L < R && s[i].ori(px[R - 1]) <= 0)
                --R;
            while (L < R && s[i].ori(px[L]) <= 0)
                ++L;
            q[++R] = s[i];
            if (q[R].parallel(q[R - 1]))
            {
                --R;
                if (q[R].ori(s[i].p1) > 0)
                    q[R] = s[i];
            }
            if (L < R)
                px[R - 1] = q[R - 1].line_intersection(q[R]);
        }
        while (L < R && q[L].ori(px[R - 1]) <= 0)
            --R;
        p.clear();
        if (R - L <= 1)
            return 0;
        px[R] = q[R].line_intersection(q[L]);
        for (int i = L; i <= R; ++i)
            p.push_back(px[i]);
        return R - L + 1;
    }
};