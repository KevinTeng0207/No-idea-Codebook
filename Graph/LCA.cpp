bool adj[9][9]; // adjacency matrix
bool visit[9];  // DFS當下已經拜訪過的點
int lca[9][9];  // 所有兩點之間的LCA
int p[9];       // Disjoint-sets Forest
// 最多兩步
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
int DFS(int x)
{
    if (visit[x])
        return;
    visit[x] = true;
    // 計算LCA
    for (int y = 0; y < 9; ++y)
        if (visit[y])
            lca[x][y] = lca[y][x] = find(y);
    // DFS
    for (int y = 0; y < 9; ++y)
        if (adj[x][y])
        {
            DFS(y);
            p[y] = x; // merge(y, x)，並讓x是樹根。
        }
}

void demo()
{
    for (int i = 0; i < 9; ++i)
        p[i] = i;
    for (int i = 0; i < 9; ++i)
        visit[i] = false;
    DFS(0); // 假設樹根為0
    int x, y;
    while (cin >> x >> y)
        cout << "x點與y點的LCA是" << lca[x][y];
}