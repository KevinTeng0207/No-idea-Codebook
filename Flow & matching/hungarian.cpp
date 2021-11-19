/*bipartite - hungarian*/
/*Based on 2017 ICPC Taiwan regional final Problem I*/
bool dfs(vector<vector<bool>> mp, vector<bool> pass, vector<int>& pre,int cur){
    for(int i = 0;i < mp[cur].size(); i++){
        if(mp[cur][i] && !pass[i]){
            pass[i] = true;
            if(pre[i] == -1 || dfs(mp,pass,pre,pre[i])){
                pre[i] = cur;
                return true;
            }
        }
    }
    return false;
}
int hungarian(vector<vector<bool>> mp,int n,int m){
    int ans = 0;
    vector<int> pre(m,-1);
    for(int i = 0;i < n; i++){
        vector<bool> pass(m,false);
        if(dfs(mp,pass,pre,i))
            ans += 1;
    }
    return ans;
}
int main(){
    int m,n,e;
    while(cin>>n){
        if(n == 0) break;
        cin>>m>>e;
        int a,b;
        vector<vector<bool>> mp(n,vector<bool>(m,false));
        for(int i = 0;i < e; i++){
            cin>>a>>b;
            mp[a][b] = true;
        }
        cout<<hungarian(mp,n,m)<<endl;
    }
    return 0;
}