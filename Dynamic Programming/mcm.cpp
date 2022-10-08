#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<vector<int>> dp(N,vector<int>(N,-1));
int cost(int i,int j,vector<int>& nums){
    if(i>=j) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    int min_cost=INT_MIN;
    for(int k=i;k<j;k++){
        min_cost=min(min_cost,cost(i,k,nums)+cost(k+1,j,nums)+(nums[i-1]*nums[k]*nums[j]));
    }
    return dp[i][j]=min_cost;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<cost(1,n-1,nums)<<'\n';
}