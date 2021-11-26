struct BccVertex
{
    int n, nBcc, step, dfn[MXN], low[MXN], top, stk[MXN];
    vector<int> E[MXN], bccv[MXN];
    void init(int _n)
    {
        n = _n;
        nBcc = step = 0;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void addEdge(int u, int v)
    {
        E[u].push_back(v);
        E[v].push_back(u);
    }
    void DFS(int u, int f)
    {
        dfn[u] = low[u] = step++;
        stk[top++] = u;
        for (auto v : E[u])
        {
            if (v == f)
                continue;
            if (dfn[v] == -1)
            {
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                {
                    int z;
                    bccv[nBcc].clear();
                    do
                    {
                        z = stk[--top];
                        bccv[nBcc].push_back(z);
                    } while (z != v);
                    bccv[nBcc++].push_back(u);
                }
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
    }
    vector<vector<int>> solve()
    {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
            dfn[i] = low[i] = -1;
        for (int i = 0; i < n; i++)
            if (dfn[i] == -1)
            {
                top = 0;
                DFS(i, i);
            }
        for (int i = 0; i < nBcc; i++)
            res.push_back(bccv[i]);
        return res;
    }
} graph;