void primeFactorization(int n) // 配合質數表
{
    for (int i = 0; i < (int)p.size(); ++i)
    {
        if (p[i] * p[i] > n)
            break;
        if (n % p[i])
            continue;
        cout << p[i] << ' ';
        while (n % p[i] == 0)
            n /= p[i];
    }
    if (n != 1)
        cout << n << ' ';
    cout << '\n';
}