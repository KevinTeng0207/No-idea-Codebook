void dfs(int j, int old, int num, vector<int> com, vector<vector<int>> &ans)
{
    for (int i = j; i <= sqrt(num); i++)
    {
        if (old == num)
            com.clear();
        if (num % i == 0)
        {
            vector<int> a;
            a = com;
            a.push_back(i);
            finds(i, old, num / i, a, ans);
            a.push_back(num / i);
            ans.push_back(a);
        }
    }
}
vector<vector<int>> ans;
vector<int> zero;
dfs(2, num, num, zero, ans);
/*/num 為 input 數字*/
for (int i = 0; i < ans.size(); i++)
{
    for (int j = 0; j < ans[i].size() - 1; j++)
        cout << ans[i][j] << " ";
    cout << ans[i][ans[i].size() - 1] << endl;
}