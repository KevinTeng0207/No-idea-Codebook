LL ans;
void find(LL n, LL c) // 配合質數判斷
{
    if (n == 1)
        return;
    if (Miller_Rabin(n))
    {
        ans = min(ans, n);
        // bug(ans); //質因數
        return;
    }
    LL x = n, k = c;
    while (x == n)
        x = Pollard_Rho(x, c--);
    find(n / x, k);
    find(x, k);
}