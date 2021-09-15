/*SPA - Floyd-Warshall*/
#include<bits/stdc++.h>
#define inf 99999
using namespace std;
void floyd_warshall(vector<vector<int>>& distance, vector<vector<int>>& ancestor,int n){
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    ancestor[i][j] = ancestor[k][j];
                }
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int a, b, d;
    vector<vector<int>> distance(n, vector<int>(n,99999));
    vector<vector<int>> ancestor(n, vector<int>(n,-1));
    while(cin>>a>>b>>d){
        if(a == -1 && b == -1 && d == -1)
            break;
        distance[a][b] = d;
        ancestor[a][b] = a;
    }
    for (int i = 0; i < n; i++)
        distance[i][i] = 0;
    floyd_warshall(distance, ancestor, n);
    /*Negative cycle detection*/
    for (int i = 0; i < n; i++){
        if(distance[i][i] < 0){
            cout << "Negative cycle!" << endl;
            break;
        }
    }

    return 0;
}