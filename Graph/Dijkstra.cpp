/*SPA - Dijkstra*/
#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;
vector<vector<int> > weight;
vector<int> ancestor;
vector<int> dist;
void dijkstra(int start){
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0; i < weight[cur].size(); i++){
            if(dist[i] > dist[cur] + weight[cur][i] && weight[cur][i] != -1){
                dist[i] = dist[cur] + weight[cur][i];
                ancestor[i] = cur;
                pq.push(make_pair(dist[i],i));
            }
        }
    }
}
int main(){
    int node;
    cin>>node;
    int a,b,d;
    weight.resize(node,vector<int>(node,-1));
    while(cin>>a>>b>>d){ 
        /*input: source destination weight*/
        if(a == -1 && b == -1 && d == -1)
            break;
        weight[a][b] = d;
    }
    ancestor.resize(node,-1);
    dist.resize(node,inf);
    int start;
    cin>>start;
    dist[start] = 0;
    dijkstra(start);
    return 0;
}