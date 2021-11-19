// 計算 回文子字串數量
int countSubstrings(string s)
{
    int n = s.size(), res = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
            if (dp[i][j])
                ++res;
        }
    }
    return res;
}