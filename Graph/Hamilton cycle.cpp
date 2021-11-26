/*find hamilton cycle*/
void hamilton(vector<vector<int>> gp, int k, int cur, vector<int>& solution,vector<bool> pass,bool& flag){
    if(k == gp.size()-1){
        if(gp[cur][1] == 1){
            cout << 1 << " ";
            while(cur != 1){
                cout << cur << " ";
                cur = solution[cur];
            }
            cout << cur << endl;
            flag = true;
            return;
        }
    }
    for (int i = 0; i < gp[cur].size() && !flag; i++){
        if(gp[cur][i] == 1 && !pass[i]){
            pass[i] = true;
            solution[i] = cur;
            hamilton(gp, k + 1, i, solution, pass,flag);
            pass[i] = false;
        }
    }
}
int main(){
    int n;
    while(cin>>n){
        int a,b;
        bool end = false;
        vector<vector<int>> gp(n+1,vector<int>(n+1,0));
        while(cin>>a>>b){
            if(a == 0 && b == 0)
                break;
            gp[a][b] = 1;
            gp[b][a] = 1;
        }
        vector<int> solution(n + 1, -1);
        vector<bool> pass(n + 1, false);
        solution[1] = 0;
        pass[1] = true;
        bool flag = false;
        hamilton(gp, 1,1 ,solution,pass,flag);
        if(!flag)
            cout << "N" << endl;
    }
    return 0;
}
/*
4
1 2
2 3
2 4
3 4
3 1
0 0
output: 1 3 4 2 1
*/