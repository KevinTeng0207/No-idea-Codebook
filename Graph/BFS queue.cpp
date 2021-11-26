/*BFS - queue version*/
void BFS(vector<int> &result, vector<pair<int, int>> edges, int node, int start)
{
    vector<int> pass(node, 0);
    queue<int> q;
    queue<int> p;
    q.push(start);
    int count = 1;
    vector<pair<int, int>> newedges;
    while (!q.empty())
    {
        pass[q.front()] = 1;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].first == q.front() && pass[edges[i].second] == 0)
            {
                p.push(edges[i].second);
                result[edges[i].second] = count;
            }
            else if (edges[i].second == q.front() && pass[edges[i].first] == 0)
            {
                p.push(edges[i].first);
                result[edges[i].first] = count;
            }
            else
                newedges.push_back(edges[i]);
        }
        edges = newedges;
        newedges.clear();
        q.pop();
        if (q.empty() == true)
        {
            q = p;
            queue<int> tmp;
            p = tmp;
            count++;
        }
    }
}
int main()
{
    int node;
    cin >> node;
    vector<pair<int, int>> edges;
    int a, b;
    while (cin >> a >> b)
    {
        /*a = b = -1 means input edges ended*/
        if (a == -1 && b == -1)
            break;
        edges.push_back(pair<int, int>(a, b));
    }
    vector<int> result(node, -1);
    BFS(result, edges, node, 0);

    return 0;
}