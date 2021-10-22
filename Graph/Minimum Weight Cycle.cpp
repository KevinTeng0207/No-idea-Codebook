// 最小環
// 圖上無負環 !!!!
#define INF 99999
vector<vector<int>> w, d, p;
vector<int> cycle;
int c = 0;
void trace(int i, int j)
{
    cycle[c++] = i;
    if (i != j)
        trace(p[i][j], j);
}
void init(int n)
{
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
}
void minimum_cycle(int n)
{
    int weight = 1e9;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (i != j)
                    if (w[k][i] + d[i][j] + w[j][k] < weight)
                    {
                        weight = w[k][i] + d[i][j] + w[j][k];
                        c = 0;
                        trace(i, j);
                        cycle[c++] = k;
                    }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
    if (weight == 1e9)
        cout << "No exist";
    else
    {
        bug(weight);
        bug(c);
        bugarr(cycle);
    }
}
void simple_minimum_cycle(int n) // No use vector p
{
    int weight = INF;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (i != j)
                    weight = min(mp[k][i] + d[i][j] + mp[j][k], weight);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
    }
    if (weight == INF)
        cout << "Back to jail\n";
    else
        cout << weight << endl;
}
w.resize(n, vector<int>(n, INF));
d.resize(n, vector<int>(n, INF));
p.resize(n, vector<int>(n));
cycle.resize(n);
//Edge input
w[a][b] = w;
d[a][b] = w;
p[a][b] = b;
init(n);
minimum_cycle(n);

