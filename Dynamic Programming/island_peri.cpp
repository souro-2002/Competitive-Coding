#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& moves,vector<vector<int>>& cts){
        if(i>=row || j>=col || vis[i][j] || grid[i][j]==0) return;
        vis[i][j]=1;
        for(auto &p:moves){
            int x=i+p.first;
            int y=j+p.second;
            if(x>=row||y>=col){
                cts[i][j]+=1;
            }
            else{
                if(!grid[x][y]) cts[i][j]+=1;
            }
        }
        for(auto &p:moves){
            int x=i+p.first;
            int y=j+p.second;
            dfs(x,y,row,col,grid,vis,moves,cts);
        }
    }
void islandPerimeter(vector<vector<int>>& grid) {
    vector<pair<int,int>> moves={
        {0,1},{1,0},{-1,0},{0,-1}
    };
    int row=grid.size(),col=grid[0].size();
    vector<vector<int>> cts(row),vis(row);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cts[i].push_back(0);
            vis[i].push_back(0);
        }
    }
    for(int i=0;i<row;i++){
        cout<<"BAL"<<' ';
        for(int j=0;j<col;j++){
            dfs(i,j,row,col,grid,vis,moves,cts);
        }
    }
    int peri=0;
    for(int i=0;i<row;i++){
        cout<<"BAL"<<' ';
        for(int j=0;j<col;j++){
            cout<<cts[i][j]<<' ';
            if(cts[i][j]) peri+=(4-cts[i][j]);
        }
        cout<<'\n';
    }
    // return peri;
}
int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> grid(row,vector<int>(col,0));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }
    islandPerimeter(grid);
    // cout<<islandPerimeter(grid)<<'\n';
}