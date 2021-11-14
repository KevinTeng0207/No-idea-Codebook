vector<int> primeFactorization(int tn) // 配合質數表
{                                      //重複 or 不重複擇一
    vector<int> f;
    f.clear();
    int n = tn;
    for (int i = 0; i < (int)p.size(); ++i)
    {
        if (p[i] * p[i] > n)
            break;
        if (n % p[i])
            continue;
        // f.pb(p[i]); //不重複
        while (n % p[i] == 0)
        {
            n /= p[i];
            // f.pb(p[i]); //重複
        }
    }
    if (n != 1)
        f.pb(n);
    return f;
}
vector<int> factorcount(int tn) // 質因數個數
{   // ex tn = 2 * 2 * 3 => {2, 1} 
    // "2" 個 2, "1" 個 3
    vector<int> fac;
    for (auto pr : p)
    {
        if (pr * pr > tn)
            break;
        if (tn % pr == 0)
        {
            int cc = 0;
            while (tn % pr == 0)
            {
                cc++;
                tn /= pr;
            }
            fac.push_back(cc);
        }
    }
    if (tn > 1)
        fac.push_back(1);
    return fac;
}