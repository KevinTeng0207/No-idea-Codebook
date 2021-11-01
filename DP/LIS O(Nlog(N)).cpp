int LIS(vector<int> &v) // O(n*log(n))
{ // 需要求 LDS 請把 array reverse 反過來求 LIS
  // 但必須注意 lower_bound or upper_bound
    if (v.size() == 0)
        return 0;
    vector<int> dp(v.size(), 0);
    int length = 1;
    dp[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto b = dp.begin(), e = dp.begin() + length;
        // auto it = lower_bound(b, e, v[i]); // 後面 >= 前面
        auto it = upper_bound(b, e, v[i]); // 後面 > 前面
        if (it == dp.begin() + length)
            dp[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}