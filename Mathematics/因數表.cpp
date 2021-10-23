const int limit = 10000000;
vector<vector<int>> arr(limit);
for (int i = 1; i <= limit; i++)
{
    for (int j = i; j <= limit; j += i)
        arr[j].pb(i); // i 為因數
}