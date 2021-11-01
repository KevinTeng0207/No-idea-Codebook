int LIS(vector<int> &v) // O(n*log(n))
{
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto b = tail.begin(), e = tail.begin() + length;
        // auto it = lower_bound(b, e, v[i]); // 後面 >= 前面
        auto it = upper_bound(b, e, v[i]); // 後面 > 前面
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}