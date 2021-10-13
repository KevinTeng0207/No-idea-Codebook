typedef long long ll;
ll modmul(ll a, ll b, ll mod)
{
    ll ret = 0;
    for (; b; b >>= 1, a = (a + a) % mod)
        if (b & 1)
            ret = (ret + a) % mod;
    return ret;
}
ll qpow(ll x, ll u, ll mod)
{
    ll ret = 1ll;
    for (; u; u >>= 1, x = modmul(x, x, mod))
        if (u & 1)
            ret = modmul(ret, x, mod);
    return ret;
}
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll Pollard_Rho(ll n, ll c)
{
    ll i = 1, j = 2, x = rand() % (n - 1) + 1, y = x;
    while (1)
    {
        i++;
        x = (modmul(x, x, n) + c) % n;
        ll p = gcd((y - x + n) % n, n);
        if (p != 1 && p != n)
            return p;
        if (y == x)
            return n;
        if (i == j)
        {
            y = x;
            j <<= 1;
        }
    }
}
bool Miller_Rabin(ll n)
{
    ll x, pre, u = n - 1;
    int i, j, k = 0;
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
        return 1;
    if (n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11))
        return 0;
    while (!(u & 1))
    {
        k++;
        u >>= 1;
    }
    srand((long long)12234336);
    for (i = 1; i <= 50; i++)
    {
        x = rand() % (n - 2) + 2;
        if (!(n % x))
            return 0;
        x = qpow(x, u, n);
        pre = x;
        for (j = 1; j <= k; j++)
        {
            x = modmul(x, x, n);
            if (x == 1 && pre != 1 && pre != n - 1)
                return 0;
            pre = x;
        }
        if (x != 1)
            return 0;
    }
    return 1;
}
// if (Miller_Rabin(n)) puts("Prime");