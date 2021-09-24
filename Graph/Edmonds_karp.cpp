/*Flow - Edmonds-karp*/
#include<bits/stdc++.h>
#define inf 1000000;
using namespace std;

int getMaxFlow(vector<vector<int>> &capacity, int s, int t, int n){
  int ans = 0;
  vector<vector<int>> residual(n+1, vector<int>(n+1, 0)); //residual network
  while(true){
    vector<int> bottleneck(n+1, 0);
    bottleneck[s] = inf;
    queue<int> q;
    q.push(s);
    vector<int> pre(n+1, 0);
    while(!q.empty() && bottleneck[t] == 0){
      int cur = q.front();
      q.pop();
      for(int i = 1; i <= n ; i++){
        if(bottleneck[i] == 0 && capacity[cur][i] > residual[cur][i]){
          q.push(i);
          pre[i] = cur;
          bottleneck[i] = min(bottleneck[cur], capacity[cur][i] - residual[cur][i]);
        }
      }
    }
    if(bottleneck[t] == 0) break;   
    for(int cur = t; cur != s; cur = pre[cur]){
        residual[pre[cur]][cur] += bottleneck[t];
        residual[cur][pre[cur]] -= bottleneck[t];
    }

    ans += bottleneck[t];
  }
  return ans;
}

int main(){
  int testcase = 1;
  int n;
  while(cin>>n){
    if(n == 0)
      break;
    vector<vector<int>> capacity(n+1, vector<int>(n+1, 0));
    int s, t, c;
    cin >> s >> t >> c;

    int a, b, bandwidth;
    for(int i = 0 ; i < c ; ++i){
      cin >> a >> b >> bandwidth;
      capacity[a][b] += bandwidth;
      capacity[b][a] += bandwidth;
    }
    cout << "Network " << testcase++ << endl;
    cout << "The bandwidth is " << getMaxFlow(capacity, s, t, n) << "." << endl;
    cout << endl;
  }

  return 0;
}