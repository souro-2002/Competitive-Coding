#include<bits/stdc++.h>
#define vi string
using namespace std;
int dp[1010][1010];
int lcs(vi& x,vi& y,int n,int m){
    if(n==0||m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1]==y[m-1]) return dp[n][m] = (1+lcs(x,y,n-1,m-1));
    else
        return dp[n][m] = max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    string nums1,nums2;
    cin>>nums1>>nums2;
    cout<<lcs(nums1,nums2,nums1.size(),nums2.size())<<'\n';
}