#include<bits/stdc++.h>
using namespace std;
int max_profit(int i,bool bought,int n,vector<int>& nums,map<pair<int,bool>,int>& dp){
        if(i>=n) return 0;
        if(dp.find({i,bought})!=dp.end()) return dp[{i,bought}];
        int buy=0,cooldown=0,sell=0;
        cooldown=max_profit(i+1,false,n,nums,dp);
        if(!bought){
            buy=max_profit(i+1,true,n,nums,dp)-nums[i];
            dp[{i,bought}]=max(buy,cooldown);
        }
        else{
            sell=max_profit(i+2,false,n,nums,dp)+nums[i];
            dp[{i,bought}]=max(sell,cooldown);
        }
        return dp[{i,bought}];
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    map<pair<int,bool>,int> dp;
    cout<<max_profit(0,true,n,nums,dp)<<'\n';
}