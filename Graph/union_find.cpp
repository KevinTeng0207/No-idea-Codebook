// union_find from 台大
vector<int> father;
vector<int> people;
void init(int)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        people[i] = 1;
    }
}
int Find(int x)
{
    if (x != father[x])
        father[x] = Find(father[x]);
    return father[x];
}

void Union(int x, int y)
{
    int m = Find(x);
    int n = Find(y);
    if (m != n)
    {
        father[n] = m;
        people[m] += people[n];
    }
}