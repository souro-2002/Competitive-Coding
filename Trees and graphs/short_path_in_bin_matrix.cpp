#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int matrix[N][N];
int main(){
    int n,zero=0;
    cin>>n;
    vector<pair<pair<int,int>,int>> zero_pos;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==0){
                zero++;
                zero_pos.push_back({{i,j},zero});
            }
        }
    }
    vector<vector<int>> graph(zero,vector<int>(zero));
    for(auto &p:zero_pos){
        int x1=p.first.first;
        int y1=p.first.second;
        int ct1=p.second;
        for(auto &ele:zero_pos){
            if(ele==p) continue;
            int x2=ele.first.first;
            int y2=ele.first.second;
            int ct2=ele.second;
            if(abs(x2-x1)<2 && abs(y2-y1)<2){
                graph[ct1].push_back(ct2);
            }
        }
    }
    for(int i=1;i<=zero;i++){
        for(int child:graph[i]) cout<<i<<' '<<child<<endl;
    }
}