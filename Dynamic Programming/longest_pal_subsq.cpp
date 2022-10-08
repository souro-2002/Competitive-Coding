#include<bits/stdc++.h>
using namespace std;
int main(){
    string st;
    cin>>st;
    string st_copy=st;
    reverse(st_copy.begin(),st_copy.end());
    string dp[st.size()+1][st.size()+1];
    for(int i=0;i<=st.size();i++){
        for(int j=0;j<=st.size();j++){
            if(i==0 || j==0) dp[i][j]="";
        }
    }
    for(int i=1;i<=st.size();i++){
        for(int j=1;j<=st.size();j++){
            if(st[i-1]==st_copy[j-1])
                dp[i][j]=dp[i-1][j-1]+st[i-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[st.size()][st.size()];
}