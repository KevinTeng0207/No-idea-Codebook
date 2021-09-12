typedef long long ll;
struct MF
{
    static const int N = 5000 + 5;
    static const int M = 60000 + 5;
    static const ll oo = 10000000000000LL;

    int n, m, s, t, tot, tim;
    int first[N], next[M];
    int u[M], v[M], cur[N], vi[N];
    ll cap[M], flow[M], dis[N];
    int que[N + N];

    void Clear()
    {
        tot = 0;
        tim = 0;
        for (int i = 1; i <= n; ++i)
            first[i] = -1;
    }
    void Add(int from, int to, ll cp, ll flw)
    {
        u[tot] = from;
        v[tot] = to;
        cap[tot] = cp;
        flow[tot] = flw;
        next[tot] = first[u[tot]];
        first[u[tot]] = tot;
        ++tot;
    }
    bool bfs()
    {
        ++tim;
        dis[s] = 0;
        vi[s] = tim;

        int head, tail;
        head = tail = 1;
        que[head] = s;
        while (head <= tail)
        {
            for (int i = first[que[head]]; i != -1; i = next[i])
            {
                if (vi[v[i]] != tim && cap[i] > flow[i])
                {
                    vi[v[i]] = tim;
                    dis[v[i]] = dis[que[head]] + 1;
                    que[++tail] = v[i];
                }
            }
            ++head;
        }
        return vi[t] == tim;
    }
    ll dfs(int x, ll a)
    {
        if (x == t || a == 0)
            return a;
        ll flw = 0, f;
        int &i = cur[x];
        for (i = first[x]; i != -1; i = next[i])
        {
            if (dis[x] + 1 == dis[v[i]] && (f = dfs(v[i], min(a, cap[i] - flow[i]))) > 0)
            {
                flow[i] += f;
                flow[i ^ 1] -= f;
                a -= f;
                flw += f;
                if (a == 0)
                    break;
            }
        }
        return flw;
    }
    ll MaxFlow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flw = 0;
        while (bfs())
        {
            for (int i = 1; i <= n; ++i)
                cur[i] = 0;
            flw += dfs(s, oo);
        }
        return flw;
    }
};
// MF Net;
// Net.n = n;
// Net.Clear();
// a 到 b (注意從1開始!!!!)
// Net.Add(a, b, w, 0);
// Net.MaxFlow(s, d)
// s 到 d 的 MF