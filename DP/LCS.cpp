int LCS(vector<string> Ans, vector<string> num)
{
    int N = Ans.size(), M = num.size();
    vector<vector<int>> LCS(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (Ans[i - 1] == num[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    cout << LCS[N][M] << '\n';
    //列印 Last appear LCS
    int n = N, m = M;
    vector<string> k;
    while (n && m)
    {
        if (LCS[n][m] != max(LCS[n - 1][m], LCS[n][m - 1]))
        {
            k.push_back(Ans[n - 1]);
            n--;
            m--;
        }
        else if (LCS[n][m] == LCS[n - 1][m])
            n--;
        else if (LCS[n][m] == LCS[n][m - 1])
            m--;
    }
    reverse(k.begin(), k.end());
    for (auto i : k)
        cout << i << " ";
    cout << endl;
    return LCS[N][M];
}
