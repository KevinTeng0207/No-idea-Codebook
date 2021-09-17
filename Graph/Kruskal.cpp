/*mst - Kruskal*/
#include<bits/stdc++.h>
using namespace std;
struct edges{
    int from;
    int to;
    int weight;
    friend bool operator < (edges a, edges b){
        return a.weight > b.weight;
    }
};
int find(int x,vector<int>& union_set){
    if(x != union_set[x])
        union_set[x] = find(union_set[x], union_set);
    return union_set[x];
}
void merge(int a,int b,vector<int>& union_set){
    int pa = find(a, union_set);
    int pb = find(b, union_set);
    if(pa != pb)
        union_set[pa] = pb;
}
void kruskal(priority_queue<edges> pq,int n){
    vector<int> union_set(n, 0);
    for (int i = 0; i < n; i++)
        union_set[i] = i;
    int edge = 0;
    int cost = 0; //evaluate cost of mst
    while(!pq.empty() && edge < n - 1){
        edges cur = pq.top();
        int from = find(cur.from, union_set);
        int to = find(cur.to, union_set);
        if(from != to){
            merge(from, to, union_set);
            edge += 1;
            cost += cur.weight;
        }
        pq.pop();
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
    priority_queue<edges> pq;
    while(cin>>a>>b>>d){
        if(a == -1 && b == -1 && d == -1)
            break;
        edges tmp;
        tmp.from = a;
        tmp.to = b;
        tmp.weight = d;
        pq.push(tmp);
    }
    kruskal(pq, n);
    return 0;
}