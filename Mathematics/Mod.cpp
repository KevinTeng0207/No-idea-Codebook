int pow_mod(int a, int n, int m) // a ^ n mod m;
{                                // a, n, m < 10 ^ 9
    if (n == 0)
        return 1;
    int x = pow_mid(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1)
        ans = ans * a % m;
    return (int)ans;
}
int inv(int a, int n, int p) // n = p-2
{
    long long res = 1;
    for (; n; n >>= 1, (a *= a) %= p)
        if (n & 1)
            (res *= a) %= p;
    return res;
}
