int LCS(vector<int> Ans, vector<int> num) // Ans 跟 num 都要 index 從1開始放
{
    vector<vector<int>> LCS(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (Ans[i] == num[j])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    // printf("%d\n", LCS[N][N]);
    return LCS[N][N];
    //列印 LCS
    vector<int> k;
    while (n && m)
    {
        if (LCS[n][m] != max(LCS[n - 1][m], LCS[n][m - 1]))
        {
            k.push_back(arr1[n]);
            n--;
            m--;
        }
        else if (LCS[n][m] == LCS[n - 1][m])
            n--;
        else if (LCS[n][m] == LCS[n][m - 1])
            m--;
    }

    reverse(k.begin(), k.end());
}
