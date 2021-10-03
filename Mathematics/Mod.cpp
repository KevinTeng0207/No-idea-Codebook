int pow_mod(int a, int n, int m) // a ^ n mod m;
{ // a, n, m < 10 ^ 9
    if (n == 0)
        return 1;
    int x = pow_mid(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1)
        ans = ans * a % m;
    return (int)ans;
}
