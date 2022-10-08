#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    vector<vector<string>> dp(n+1,vector<string>(m+1,""));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+x[i-1];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<(dp[n][m]==""?"No common subseqeunce":dp[n][m])<<'\n';
}