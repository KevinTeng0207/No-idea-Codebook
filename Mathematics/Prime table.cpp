// 埃拉托斯特尼篩法
const int maxn = 10000000;
bitset<maxn> is_not_prime; // false 是質數
void sieve()
{
    is_not_prime[0] = is_not_prime[1] = 1;
    for (int i = 2; i * i < maxn; ++i)
    {
        if (is_not_prime[i] == 0)
        {
            for (int j = i * i; j < maxn; j += i)
                is_not_prime[j] = 1;
        }
    }
}
