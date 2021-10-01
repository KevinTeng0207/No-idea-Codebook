/*bipartite - maximum matching*/
bool dfs(vector<vector<bool>> res,int node,vector<int>& x, vector<int>& y, vector<bool> pass){
    for (int i = 0; i < res[0].size(); i++){
        if(res[node][i] && !pass[i]){
            pass[i] = true;
            if(y[i] == -1 || dfs(res,y[i],x,y,pass)){
                x[node] = i;
                y[i] = node;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m,l;
    while(cin>>n>>m>>l){
        vector<vector<bool>> res(n, vector<bool>(m, false));
        for (int i = 0; i < l; i++){
            int a, b;
            cin >> a >> b;
            res[a][b] = true;
        }
        int ans = 0;
        vector<int> x(n, -1);
        vector<int> y(n, -1);
        for (int i = 0; i < n; i++){
            vector<bool> pass(n, false);
            if(dfs(res,i,x,y,pass))
                ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
input:
4 3 5 //n matching m, l links
0 0
0 2
1 0
2 1
3 1
answer is 3
*/