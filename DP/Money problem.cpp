//能否湊得某個價位
void change(vector<int> price, int limit)
{
    vector<bool> c(limit + 1, 0);
    c[0] = true;
    for (int i = 0; i < price.size(); ++i)      // 依序加入各種面額
        for (int j = price[i]; j <= limit; ++j) // 由低價位逐步到高價位
            c[j] = c[j] || c[j - price[i]];     // 湊、湊、湊
    if (c[limit]) cout << "YES\n";
    else cout << "NO\n";
}
// 湊得某個價位的湊法總共幾種
void change(vector<int> price, int limit)
{
    vector<bool> c(limit + 1, 0);
    c[0] = true;
    for (int i = 0; i < price.size(); ++i)
        for (int j = price[i]; j <= limit; ++j)
            c[j] += c[j - price[i]];
    cout << c[limit] << '\n';
}
// 湊得某個價位的最少錢幣用量
void change(vector<int> price, int limit)
{
    vector<bool> c(limit + 1, 0);
    c[0] = true;
    for (int i = 0; i < price.size(); ++i)
        for (int j = price[i]; j <= limit; ++j)
            c[j] = min(c[j], c[j - price[i]] + 1);
    cout << c[limit] << '\n';
}
//湊得某個價位的錢幣用量，有哪幾種可能性
void change(vector<int> price, int limit)
{
    vector<bool> c(limit + 1, 0);
    c[0] = true;
    for (int i = 0; i < price.size(); ++i)
        for (int j = price[i]; j <= limit; ++j)
            c[j] |= c[j-price[i]] << 1; // 錢幣數量加一，每一種可能性都加一。
 
    for (int i = 1; i <= 63; ++i)
        if (c[m] & (1 << i))
            cout << "用" << i << "個錢幣可湊得價位" << m;
}