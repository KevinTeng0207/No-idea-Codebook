/*SPA - Bellman-Ford*/
#include<bits/stdc++.h>
#define inf 99999 //define by you maximum edges weight
using namespace std;
vector<vector<int> > edges;
vector<int> dist;
vector<int> ancestor;
void BellmanFord(int start,int node){
    dist[start] = 0;
    for(int it = 0; it < node-1; it++){
        for(int i = 0; i < node; i++){
            for(int j = 0; j < node; j++){
                if(edges[i][j] != -1){
                    if(dist[i] + edges[i][j] < dist[j]){
                        dist[j] = dist[i] + edges[i][j];
                        ancestor[j] = i;
                    }
                }
            }
        }
    }

    for(int i = 0; i < node; i++)  //negative cycle detection
        for(int j = 0; j < node; j++)
            if(dist[i] + edges[i][j] < dist[j])
            {
                cout<<"Negative cycle!"<<endl;
                return;
            }
}
int main(){
    int node;
    cin>>node;
    edges.resize(node,vector<int>(node,inf));
    dist.resize(node,inf);
    ancestor.resize(node,-1);
    int a,b,d;
    while(cin>>a>>b>>d){
        /*input: source destination weight*/
        if(a == -1 && b == -1 && d == -1)
            break;
        edges[a][b] = d;
    }
    int start;
    cin>>start;
    BellmanFord(start,node);  
    return 0;
}