#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

bool can_jump(vi& nums,vi& dp,int i,int n){
    if(i==n-1) return true;
    if(i>n-1 || (i<n-1 && nums[i]==0)) return false;
    if(dp[i]!=-1) return dp[i];
    bool can=false;
    for(int jump=1;jump<=nums[i];jump++){
        can|=(dp[i]=can_jump(nums,dp,i+jump,n));
    }
    return can;
}

int main(){
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vi dp(n+1,-1);
    cout<<(can_jump(nums,dp,0,n)?"Yes":"No")<<'\n';
}