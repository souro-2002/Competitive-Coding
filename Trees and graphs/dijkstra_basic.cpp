#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>> graph[N];
vector<int> dist(N,INF),vis(N);

void reset(){
    for(int i=0;i<N;i++){
        dist[i]=INF;
        vis[i]=0;
    }
}

void dijkstra(int source){
    set<pair<int,int>> st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto src=*st.begin();
        int curr_dist=src.first;
        int v=src.second;
        vis[v]=1;
        st.erase(st.begin());
        for(auto child:graph[v]){
            int child_v=child.first;
            int wt=child.second;
            if(vis[child_v]) continue;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

void print(int n){
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
    }
    dijkstra(1);
    print(n);
    reset();
    cout<<endl;
}