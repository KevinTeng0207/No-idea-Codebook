vector<vector<int>> arr(10000000);
const int limit = 10e7;
for (int i = 1; i <= limit; i++)
{
    for (int j = i; j <= limit; j += i)
        arr[j].pb(i); // i 為因數
}