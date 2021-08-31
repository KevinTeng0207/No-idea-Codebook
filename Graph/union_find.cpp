int find(int x,vector<int> &union_set){
    if(union_set[x] != x)
        union_set[x] = find(union_set[x], union_set); //compress path
    return union_set[x];
}
void merge(int x,int y,vector<int> &union_set,vector<int> &rank){
    int rx, ry;
    rx = find(x,union_set);
    ry = find(y,union_set);
    if(rx == ry)
        return;
    /*merge by rank -> always merge small tree to big tree*/
    if(rank[rx] > rank[ry])
        union_set[ry] = rx;
    else
    {
        union_set[rx] = ry;
        if(rank[rx] == rank[ry])
            ++rank[ry];
    }
}
int main(){
    int node;
    cout << "Input Node number: ";
    cin >> node;
    vector<int> union_set(node, 0);
    vector<int> rank(node, 0);
    for (int i = 0; i < node; i++)
        union_set[i] = i;
    int edge;
    cout << "Input Edge number: ";
    cin >> edge;
    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b, union_set,rank);
    }
    for (int i = 0; i < node; i++)
        cout << i << " ";
    cout << endl;
    for (auto i : union_set)
        cout << i << " ";
    cout << endl;
    /*build party*/
    vector<vector<int> > party(node, vector<int>(0));
    for (int i = 0; i < node; i++)
        party[find(i, union_set)].push_back(i);
    for (int i = 0; i < party.size(); i++){
        if(!party[i].empty())
        {
            cout << "Party " << i << ": ";
            for(auto j : party[i])
                cout << j << " ";
            cout << endl;
        }
    }
}
/*
    Input Node number: 5
    Input Edge number: 3
    0 1
    1 3
    2 4
    node:   0 1 2 3 4
    parent: 0 0 2 0 2
    party 1: 0 1 3
    party 2: 2 4

    Input Node number: 10
    Input Edge number: 8
    0 1
    1 4
    2 8
    6 7
    3 5
    3 9
    0 4
    7 2
    node:   0 1 2 3 4 5 6 7 8 9
    parent: 1 1 8 5 1 5 7 8 8 5 //use parent to check party  
    party 1: 0 1 4
    party 5: 3 5 9
    party 8: 2 6 7 8

*/