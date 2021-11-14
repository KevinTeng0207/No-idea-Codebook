void primeFactorization(int n) // 配合質數判斷
{
    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] * p[i] > n)
            break;
        if (n % p[i])
            continue;
        bug(p[i]);
        while (n % p[i] == 0)
            n /= p[i];
    }
    if (n != 1)
        bug(n);
}