#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> subtree_sum(N,0),even_ct(N,0);
vector<int> graph[N];
void dfs(int vertex,int parent=0){
    if(!(vertex&1)) even_ct[vertex]++;
    subtree_sum[vertex]=vertex;
    for(int child:graph[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    int node;
    cin>>node;
    cout<<"Subtree sum = "<<subtree_sum[node]<<endl;
    cout<<"Even count of node = "<<even_ct[node]<<endl;
}