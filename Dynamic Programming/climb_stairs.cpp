#include<bits/stdc++.h>
using namespace std;

int ways(int n,vector<int>& dp){
    if(n==1 || n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int way=0;
    way=ways(n-1,dp)+(n>=2?ways(n-2,dp):0);
    return dp[n]=way;
}

int number_of_ways(int n){
    vector<int> dp(n+1,-1);
    return ways(n,dp);
}
int main(){
    int n;
    cin>>n;
    cout<<number_of_ways(n)<<endl;
}
