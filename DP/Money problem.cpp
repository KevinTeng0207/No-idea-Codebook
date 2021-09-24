void change(vector<int> price, int limit)
{
    vector<bool> c(limit + 1, 0);
    c[0] = true;
    for (int i = 0; i < price.size(); ++i)      // 依序加入各種面額
        for (int j = price[i]; j <= limit; ++j) // 由低價位逐步到高價位
            c[j] = c[j] || c[j - price[i]];     // 湊、湊、湊
    if (c[limit])
        cout << "YES\n";
    else
        cout << "NO\n";
}