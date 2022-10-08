#include<bits/stdc++.h>
#define v vector 
#define vi v<int>
using namespace std;
int ways(vi& nums,vi& dp,int i,int n){
    if(i==n-1) return 1;
    if(i>n-1 ||(i<n-1 && nums[i]==0)) return 0;
    int way=INT_MAX;
    for(int j=1;j<=nums[i];j++){
        way=(dp[i]=min(way,1+ways(nums,dp,i+j,n)));
    }
    return way;
}
int main(){
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vi dp(n+1,-1);
    cout<<ways(nums,dp,0,n)-1<<'\n';
}