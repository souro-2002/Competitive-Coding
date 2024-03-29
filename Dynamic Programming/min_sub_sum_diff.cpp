#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int sum=accumulate(nums.begin(),nums.end(),0);
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j]=false;
            if(j==0) dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]<=j)
                dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    int diff=INT_MAX;
    for(int i=0;i<=sum;i++){
        if(dp[n][i]){
            if(sum-(2*i)==0) continue;
            else diff=min(diff,abs(sum-(2*i)));
        }
    }
    cout<<diff<<'\n';
}