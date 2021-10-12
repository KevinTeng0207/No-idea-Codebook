/*Optimize version*/
int find(int x, vector<int> &union_set)
{
    if (union_set[x] != x)
        union_set[x] = find(union_set[x], union_set); //compress path
    return union_set[x];
}
void merge(int x, int y, vector<int> &union_set, vector<int> &rank)
{
    int rx, ry;
    rx = find(x, union_set);
    ry = find(y, union_set);
    if (rx == ry)
        return;
    /*merge by rank -> always merge small tree to big tree*/
    if (rank[rx] > rank[ry])
        union_set[ry] = rx;
    else
    {
        union_set[rx] = ry;
        if (rank[rx] == rank[ry])
            ++rank[ry];
    }
}
int main()
{
    int node;
    cin >> node; //Input Node number
    vector<int> union_set(node, 0);
    vector<int> rank(node, 0);
    for (int i = 0; i < node; i++)
        union_set[i] = i;
    int edge;
    cin >> edge; //Input Edge number
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b, union_set, rank);
    }
    /*build party*/
    vector<vector<int>> party(node, vector<int>(0));
    for (int i = 0; i < node; i++)
        party[find(i, union_set)].push_back(i);
}
/*Simplify version*/
int find(int x,vector<int> union_set){
    return (x == union_set[x]) ? x : find(union_set[x],union_set);
}
int main(){
    int node;
    cin>>node;
    vector<int> union_set(node,0);
    for(int i = 0;i < node; i++)
        union_set[i] = i;
    int edge;
    cin>>edge;
    for(int i = 0; i < edge; i++){
        int a,b;
        cin>>a>>b;
        union_set[a] = find(b,union_set);
    }
    for(int i = 0;i < node; i++) // find the root
        union_set[i] = find(i,union_set);
    /*build party*/
    vector<vector<int>> party(node, vector<int>(0));
    for (int i = 0; i < node; i++)
        party[find(i, union_set)].push_back(i);
    
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