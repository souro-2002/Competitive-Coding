#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+6;
int rivers[N][N];
unordered_set<ll> river_sizes;
int n,m;
vector<pair<int,int>> movements={
    {0,1},{0,-1},{1,0},{-1,0}
};
bool isValid(int x,int y){
    return (x>=0 && y>=0 && x<m && y<n && rivers[x][y]!=0);
}
void dfs(int x,int y, ll size=0){
    if(!isValid(x,y)) return;
    size++;
    river_sizes.insert(size);
    rivers[x][y]=0;
    for(auto &move: movements){
        int move_x=move.first;
        int move_y=move.second;
        dfs(x+move_x,y+move_y,size);
    }
}
int main(){
    vector<pair<int,int>> one_ct;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>rivers[i][j];
            if(rivers[i][j]==1) one_ct.push_back({i,j});
        }
    }
    for(auto& cood:one_ct){
        dfs(cood.first,cood.second);
    }
    for(ll i:river_sizes) cout<<i<<' ';
    cout<<endl;
}