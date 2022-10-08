#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movements={
    {0,1},{0,-1},{1,0},{-1,0}
};

bool isValid(int x,int y,vector<vector<int>>& matrix){
    return x>=0 && y>=0 && y<matrix[0].size() && x<matrix.size();
}

void dfs(int x,int y,vector<vector<int>>& matrix,set<int>& lp,vector<vector<int>>& vis,int ct=0,int p_x=-1,int p_y=-1){
    if(!isValid(x,y,matrix) || vis[x][y]){
        return;
    }
    vis[x][y]=1;
    if(p_x>=0 && p_y>=0){
        if(matrix[x][y]>matrix[p_x][p_y]){
            ct++;
            lp.insert(ct);
        }
        else return;
    }
    else ct++; lp.insert(ct);
    for(auto &p:movements){
        int new_x=x+p.first;
        int new_y=y+p.second;
        dfs(new_x,new_y,matrix,lp,vis,ct,x,y);
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>matrix[i][j];
    }
    set<int> longest_path;
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) dfs(i,j,matrix,longest_path,vis);
    }
    cout<<*(--longest_path.end())<<endl;
}