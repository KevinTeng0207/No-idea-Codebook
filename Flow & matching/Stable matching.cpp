/*based on UVa1175*/
/*stable marriage problem*/
void engage(vector<int>& bm, vector<int>& gm, int a, int b, queue<int>& q){
    int tmp = gm[b];
    if(tmp != -1){
        bm[tmp] = -1;
        q.push(tmp);
    }
    bm[a] = b;
    gm[b] = a;
}
int main(){
    int cases;
    bool blank = false;
    cin>>cases;
    while(cases--){
        if(blank) cout<<endl;
        int n,a;
        cin>>n;
        queue<int> q; // proposal
        vector<vector<int>> boy(n+1,vector<int>(n+1,0)),girl(n+1,vector<int>(n+1,0));
        vector<int> p(n+1,1);
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= n; j++){
                cin>>a;
                boy[i][j] = a;
            }
            q.push(i);
        }
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= n; j++){
                cin>>a;
                girl[i][a] = j;
            }
        }
        vector<int> bm(n+1,-1),gm(n+1,-1);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int car = boy[cur][p[cur]++];
            if(gm[car] == -1 || girl[car][cur] < girl[car][gm[car]]) engage(bm,gm,cur,car,q);
            else q.push(cur);
        }
        /*This is optimal solution for lady*/
        /*If want optimal for man change the lady and man on above algorithm*/
        for(int i = 1;i <= n; i++){
            cout<<bm[i]<<endl; 
        }
        blank = true;
    }
    return 0;
}