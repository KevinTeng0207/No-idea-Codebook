const int maxn = sqrt(INT_MAX);
vector<int> p;
bitset<maxn> is_notp;
void PrimeTable()
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i <= maxn; ++i)
    {
        if (!is_notp[i])
            p.push_back(i);
        for (int j = 0; j < (int)p.size(); ++j)
        {
            if (i * p[j] > maxn)
                break;
            is_notp[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}