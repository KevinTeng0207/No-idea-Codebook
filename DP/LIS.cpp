vector<int> ans;
void printLIS(vector<int> &arr, vector<int> &pos, int index)
{
    if (pos[index] != -1)
        printLIS(arr, pos, pos[index]);
    // printf("%d", arr[index]);
    ans.push_back(arr[index]);
}
void LIS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    vector<int> pos(arr.size(), -1);
    int res = INT_MIN, index = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] > arr[i])
            {
                if (dp[i] + 1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    pos[j] = i;
                }
            }
        }
        if (dp[i] > res)
        {
            res = dp[i];
            index = i;
        }
    }
    cout << res << endl; // length
    printLIS(arr, pos, index);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ' ';
    }
    cout << '\n';
}

int LIS(vector<int> &v) // O(n*log(n))
{
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}