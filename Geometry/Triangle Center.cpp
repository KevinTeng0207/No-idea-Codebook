//台大
P TriangleCircumCenter(P a, P b, P c) //外心
{
    P res;
    double a1 = atan2(b.y - a.y, b.x - a.x) + PI / 2;
    double a2 = atan2(c.y - b.y, c.x - b.x) + PI / 2;
    double ax = (a.x + b.x) / 2;
    double ay = (a.y + b.y) / 2;
    double bx = (c.x + b.x) / 2;
    double by = (c.y + b.y) / 2;
    double r1 = (sin(a2) * (ax - bx) + cos(a2) * (by - ay)) / (sin(a1) * cos(a2) - sin(a2) * cos(a1));
    return P(ax + r1 * cos(a1), ay + r1 * sin(a1));
}
P TriangleMassCenter(P a, P b, P c) //重心
{
    return (a + b + c) / 3.0;
}
P TriangleOrthoCenter(P a, P b, P c)//垂心
{
    return TriangleMassCenter(a, b, c) * 3.0 -
           TriangleCircumCenter(a, b, c) * 2.0;
}
P TriangleInnerCenter(P a, P b, P c) //內心
{//len sqrt((x1-x2)(x1-x2) + (y1-y1)(x1-x2))
    P res;
    double la = len(b - c);
    double lb = len(a - c);
    double lc = len(a - b);
    res.x = (la * a.x + lb * b.x + lc * c.x) / (la + lb + lc);
    res.y = (la * a.y + lb * b.y + lc * c.y) / (la + lb + lc);
    return res;
}