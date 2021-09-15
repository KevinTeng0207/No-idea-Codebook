template <typename T>
struct line
{
    line() {}
    point<T> p1, p2;
    T a, b, c; //ax+by+c=0
    line(const point<T> &x, const point<T> &y) : p1(x), p2(y) {}
    void pton()
    { //轉成一般式
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = -a * p1.x - b * p1.y;
    }
    T ori(const point<T> &p) const
    { //點和有向直線的關係，>0左邊、=0在線上<0右邊
        return (p2 - p1).cross(p - p1);
    }
    T btw(const point<T> &p) const
    { //點投影落在線段上<=0
        return (p1 - p).dot(p2 - p);
    }
    bool point_on_segment(const point<T> &p) const
    { //點是否在線段上
        return ori(p) == 0 && btw(p) <= 0;
    }
    T dis2(const point<T> &p, bool is_segment = 0) const
    { //點跟直線/線段的距離平方
        point<T> v = p2 - p1, v1 = p - p1;
        if (is_segment)
        {
            point<T> v2 = p - p2;
            if (v.dot(v1) <= 0)
                return v1.abs2();
            if (v.dot(v2) >= 0)
                return v2.abs2();
        }
        T tmp = v.cross(v1);
        return tmp * tmp / v.abs2();
    }
    T seg_dis2(const line<T> &l) const
    { //兩線段距離平方
        return min({dis2(l.p1, 1), dis2(l.p2, 1), l.dis2(p1, 1), l.dis2(p2, 1)});
    }
    point<T> projection(const point<T> &p) const
    { //點對直線的投影
        point<T> n = (p2 - p1).normal();
        return p - n * (p - p1).dot(n) / n.abs2();
    }
    point<T> mirror(const point<T> &p) const
    {
        //點對直線的鏡射，要先呼叫pton轉成一般式
        point<T> R;
        T d = a * a + b * b;
        R.x = (b * b * p.x - a * a * p.x - 2 * a * b * p.y - 2 * a * c) / d;
        R.y = (a * a * p.y - b * b * p.y - 2 * a * b * p.x - 2 * b * c) / d;
        return R;
    }
    bool equal(const line &l) const
    { //直線相等
        return ori(l.p1) == 0 && ori(l.p2) == 0;
    }
    bool parallel(const line &l) const
    {
        return (p1 - p2).cross(l.p1 - l.p2) == 0;
    }
    bool cross_seg(const line &l) const
    {
        return (p2 - p1).cross(l.p1 - p1) * (p2 - p1).cross(l.p2 - p1) <= 0; //直線是否交線段
    }
    int line_intersect(const line &l) const
    { //直線相交情況，-1無限多點、1交於一點、0不相交
        return parallel(l) ? (ori(l.p1) == 0 ? -1 : 0) : 1;
    }
    int seg_intersect(const line &l) const
    {
        T c1 = ori(l.p1), c2 = ori(l.p2);
        T c3 = l.ori(p1), c4 = l.ori(p2);
        if (c1 == 0 && c2 == 0)
        { //共線
            bool b1 = btw(l.p1) >= 0, b2 = btw(l.p2) >= 0;
            T a3 = l.btw(p1), a4 = l.btw(p2);
            if (b1 && b2 && a3 == 0 && a4 >= 0)
                return 2;
            if (b1 && b2 && a3 >= 0 && a4 == 0)
                return 3;
            if (b1 && b2 && a3 >= 0 && a4 >= 0)
                return 0;
            return -1; //無限交點
        }
        else if (c1 * c2 <= 0 && c3 * c4 <= 0)
            return 1;
        return 0; //不相交
    }
    point<T> line_intersection(const line &l) const
    { /*直線交點*/
        point<T> a = p2 - p1, b = l.p2 - l.p1, s = l.p1 - p1;
        //if(a.cross(b)==0)return INF;
        return p1 + a * (s.cross(b) / a.cross(b));
    }
    point<T> seg_intersection(const line &l) const
    { //線段交點
        int res = seg_intersect(l);
        if (res <= 0)
            assert(0);
        if (res == 2)
            return p1;
        if (res == 3)
            return p2;
        return line_intersection(l);
    }
};