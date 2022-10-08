#include<bits/stdc++.h>
using namespace std;
int main(){
    string st;
    cin>>st;
    string st_copy=st;
    int len=st.size();
    int dp[len+1][len+1];
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(st[i-1]==st_copy[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[len][len]<<endl;
}