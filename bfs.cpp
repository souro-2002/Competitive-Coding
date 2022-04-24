#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
vector<int> graph[N];
vector<int> lev(N,INF),vis(N);
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    lev[source]=0;
    while(!q.empty()){
        int curr=q.front();
        cout<<curr<<' ';
        q.pop();
        for(int child:graph[curr]){
            if(vis[child]) continue;
            q.push(child);
            vis[child]=1;
            lev[child]=lev[curr]+1;
        }
    }
    cout<<endl;
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
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<lev[i]<<endl;
    }
}