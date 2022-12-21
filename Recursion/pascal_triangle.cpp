#include<bits/stdc++.h>
using namespace std;
int term(int row,int ind,vector<vector<int>>& dp){
    if(ind==1 || ind==row) return 1;
    if(dp[row][ind]!=-1) return dp[row][ind];
    else return dp[row][ind]=term(row-1,ind-1,dp)+term(row-1,ind,dp);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> triangle(n+1),dp(32,vector<int>(32,-1));
    for(int i=1;i<=n;i++){
        vector<int> row;
        for(int j=1;j<=i;j++){
            row.push_back(term(i,j,dp));
        }
        triangle[i]=row;
    }
    triangle.erase(triangle.begin());
    for(auto &v:triangle){
        for(auto ele:v) cout<<ele<<' ';
        cout<<endl;
    }
}