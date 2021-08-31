// 埃拉托斯特尼篩法
const int maxn = 10000000;
bitset<maxn> prime;
void sieve()
{
    for (int i = 2; i * i < maxn; ++i)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < maxn; j += i)
                prime[j] = 1;
        }
    }
}
/* 0跟1要寫if過濾掉 */
// if(!prime[數字])
//     我是質數