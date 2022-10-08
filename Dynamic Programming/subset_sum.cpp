#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j]=false;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0) dp[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]<=sum) dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<(dp[n][sum]?"Yes":"No")<<endl;
}