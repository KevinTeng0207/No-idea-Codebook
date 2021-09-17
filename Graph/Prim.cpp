/*mst - Prim*/
#include<bits/stdc++.h>
#define inf 99999
using namespace std;
struct edges{
    int from;
    int to;
    int weight;
    friend bool operator < (edges a, edges b){
        return a.weight > b.weight;
    }
};
void Prim(vector<vector<int>> gp,int n,int start){
    vector<bool> pass(n,false);
    int edge = 0;
    int cost = 0; //evaluate cost of mst
    priority_queue<edges> pq;
    for (int i = 0; i < n; i++){
        if(gp[start][i] != inf){
            edges tmp;
            tmp.from = start;
            tmp.to = i;
            tmp.weight = gp[start][i];
            pq.push(tmp);
        }
    }
    pass[start] = true;
    while(!pq.empty() && edge < n-1){
        edges cur = pq.top();
        pq.pop();
        if(!pass[cur.to]){
            for (int i = 0; i < n; i++){
                if(gp[cur.to][i] != inf){
                    edges tmp;
                    tmp.from = cur.to;
                    tmp.to = i;
                    tmp.weight = gp[cur.to][i];
                    pq.push(tmp);
                }
            }
            pass[cur.to] = true;
            edge += 1;
            cost += cur.weight;
        }
    }
    if(edge < n-1)
        cout << "No mst" << endl;
    else
        cout << cost << endl;
}
int main(){
    int n;
    cin >> n;
    int a, b, d;
    vector<vector<int>> gp(n,vector<int>(n,inf));
    while(cin>>a>>b>>d){
        if(a == -1 && b == -1 && d == -1)
            break;
        if(gp[a][b] > d)
            gp[a][b] = d;
    }
    Prim(gp,n,0);
    return 0;
}