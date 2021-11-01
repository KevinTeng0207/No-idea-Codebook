/*SPA - Dijkstra*/
const int MAXN = 1e5 + 3;
const int inf = INT_MAX;
typedef pair<int, int> pii;
vector<vector<pii>> weight(MAXN);
vector<int> isDone(MAXN, false), dist, ancestor;
void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    ancestor[s] = -1;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        isDone[u] = true;

        for (auto &pr : weight[u])
        {
            int v = pr.first, w = pr.second;

            if (!isDone[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
                ancestor[v] = u;
            }
        }
    }
}
// weight[a - 1].push_back(pii(b - 1, w));
// weight[b - 1].push_back(pii(a - 1, w));
// dist.resize(n, inf);
// ancestor.resize(n, -1);
// dist[0] = 0;
// dijkstra(0);