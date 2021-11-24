/*from 演算法筆記*/
typedef int Graph[9][9];    // adjacency matrix
Graph C, F, R;              // 分別是容量上限、流量、剩餘容量
bool visit[9];
void DFS(int i)
{
    visit[i] = true;
    for (int j=0; j<9; ++j)
        if (!visit[j] && F[i][j] < C[i][j])
            DFS(j);
}
 
void minimum_s_t_cut(int s, int t)
{
    // 求一個最大源匯流，源點為s點，匯點為t點。
    Edmonds_Karp(s, t);
 
    // 從源點開始遍歷，找出流量瓶頸。
    memset(visit, false, sizeof(visit));
    DFS(s);
 
    // 找出其中一個最小源匯割，會是源點側點數最少的最小源匯割。
    for (int i=0; i<9; ++i)         // 窮舉源點側的點
        if (visit[i])
            for (int j=0; j<9; ++j) // 窮舉匯點側的點
                if (!visit[j])
                    if (C[i][j] > 0)    // 要確定有邊
                        cout << "割上的邊有"
                            << "由" << i << "到" << j;
}