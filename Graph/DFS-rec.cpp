/*DFS - Recursive version*/
#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> edges;
vector<int> pass;
vector<int> route;
void DFS(int start){
    pass[start] = 1;
    map<pair<int,int>,int>::iterator iter;
    for(iter = edges.begin(); iter != edges.end(); iter++){
        if((*iter).first.first == start && (*iter).second == 0 && pass[(*iter).first.second] == 0){
            route.push_back((*iter).first.second);
            DFS((*iter).first.second);
        }
        else if((*iter).first.second == start && (*iter).second == 0 && pass[(*iter).first.first] == 0){
            route.push_back((*iter).first.first);
            DFS((*iter).first.first);
        }
    }
}
int main(){
    int node;
    cin>>node;
    pass.resize(node,0);
    int a,b;
    while(cin>>a>>b){
        if(a == -1 && b == -1)
            break;
        edges.insert(pair<pair<int,int>,int>(pair<int,int>(a,b),0));
    }
    int start;
    cin>>start;
    route.push_back(start);
    DFS(start);
    return 0;
}