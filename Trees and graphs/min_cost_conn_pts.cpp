#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=1e9+10;
vector<int> parent(N),size(N);
int connected[N][N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v) return v;
    return (parent[v]=find(parent[v]));
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(size[a]<size[b]) swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
}

int weight(int x1,int y1,int x2,int y2){
    return (abs(x2-x1)+abs(y2-y1));
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> pts;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pts.push_back({x,y});
    }
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x1=pts[i][0];
            int y1=pts[i][1];
            int x2=pts[j][0];
            int y2=pts[j][1];
            if((i==j) || connected[i][j]) continue;
            edges.push_back({weight(x1,y1,x2,y2),{i,j}});
            connected[i][j]=connected[j][i]=1;
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++) make(i);
    int total_cost=0;
    for(auto &ele: edges){
        int wt=ele.first;
        int a=ele.second.first;
        int b=ele.second.second;
        if(find(a)==find(b)) continue;
        total_cost+=wt;
        Union(a,b);
    }
    cout<<total_cost<<endl;
}