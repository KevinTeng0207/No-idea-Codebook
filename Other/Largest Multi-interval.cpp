/*多區間算最大值*/
bool name(pii a, pii b)
{ return b.first > a.first;}
vector<pii> data;
data.pb(pii(a, c)); // 區間 a 到 c
sort(data.begin(), data.end(), name); // pair first 從 小 到 大
int l = data[0].x, r = data[0].y, res = 0;
for (int i = 1; i < data.size(); i++)
{
    if (data[i].x <= r)
    {
        if (r < data[i].y)
            r = data[i].y;
    }
    else
    {
        res += r - l;
        l = data[i].x;
        r = data[i].y;
    }
}
res += r - l;