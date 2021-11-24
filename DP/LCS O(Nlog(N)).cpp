#define LEN 500004
int a[LEN], b[LEN];
int loc[LEN], n;
int LIS()
{
    for (int i = 1; i <= n; i++)
        loc[b[i]] = i;
    for (int i = 1; i <= n; i++)
        b[i] = loc[a[i]];
    int k, l, r, mid;
    a[1] = b[1], k = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[k] < b[i])
            a[++k] = b[i];
        else
        {
            l = 1;
            r = k;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a[mid] < b[i])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            a[l] = b[i];
        }
    }
    return k;
}