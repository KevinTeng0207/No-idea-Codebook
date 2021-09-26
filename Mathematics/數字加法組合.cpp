void recur(int i, int n, int m, vector<int> &out, vector<vector<int>> &ans)
{
    if (n == 0)
    {
        for (int i : out)
            if (i > m)
                return;
        ans.push_back(out);
    }
    for (int j = i; j <= n; j++)
    {
        out.push_back(j);
        recur(j, n - j, m, out, ans);
        out.pop_back();
    }
}
vector<vector<int>> ans;
vector<int> zero;
recur(1, num, num, zero, ans);
// num 為 input 數字
for (int i = 0; i < ans.size(); i++)
{
    for (int j = 0; j < ans[i].size() - 1; j++)
        cout << ans[i][j] << " ";
    cout << ans[i][ans[i].size() - 1] << endl;
}