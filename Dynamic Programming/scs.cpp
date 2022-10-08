#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size(),n2=s2.size();
    int dp[n1+1][n2+1];
    for(int i=1;i<=n1;i++){ //Normal code for computing length of LCS
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n1,j=n2;
    string ans="";
    while(i && j){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;j--; //We include one instance only of the equal characters
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(s1[i-1]);
                i--;
                //We proceed in the direction of the maximum after including the current string 
            }
            else{
                ans.push_back(s2[j-1]);
                j--;
                //We proceed in the direct of maximum after including the current instance
            }
        }
    }
    while(i){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j){
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
}