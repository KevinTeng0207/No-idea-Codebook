int mp[30][30];
int vis[30];
int n, m;
int dfs(int now){
    for(int i = 0;i < now; i++){

        if(mp[now][i]&&(vis[now] == vis[i]))//與now相鄰的結點與now有相同的頻率
            return 0;
    }
    if(now == n - 1){//遍歷結束
        return 1;
    }
    for(int i = 1;i <= 3; i++){//選顏色
        vis[now+1] = i;
        if(dfs(now+1))
            return 1;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        cin >> n >> m;
        while(m--){
            int a, b;
            cin >> a >> b;
            mp[a][b] = 1;
            mp[b][a] = 1;
        }
        vis[0] = 1;//第一個節點任意選一種顏色
        if(dfs(0))
            cout <<"Y"<<endl;
        else
            cout <<"N"<<endl;
        //print vis = print result of combinaton
    }
    return 0;
}