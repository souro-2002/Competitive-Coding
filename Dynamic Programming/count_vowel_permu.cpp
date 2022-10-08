#include<bits/stdc++.h>
using namespace std;
int permu(int i,int n,int M,string& temp,map<char,int>& vowels,vector<vector<int>>& dp,map<char,vector<char>>& pos){
    if(i==n) return 1;
    if(dp[i][vowels[temp[i-1]]]!=-1) return dp[i][vowels[temp[i-1]]];
    int ways=0;
    for(char ch:pos[temp[i-1]]){
        temp.push_back(ch);
        ways=(ways+(dp[i+1][vowels[ch]]=permu(i+1,n,M,temp,vowels,dp,pos))%M)%M;
        temp.pop_back();
    }
    return ways;
}
int main(){
    int n;
    cin>>n;
    string temp="";
    map<char,int> vowels={{'a',1},{'e',2},{'i',3},{'o',4},{'u',5}};
    vector<vector<int>> dp(n+1,vector<int>(6,-1));
    map<char,vector<char>> pos={
        {'a',{'e'}},{'e',{'a','i'}},{'i',{'a','e','o','u'}},
        {'o',{'i','u'}},{'u',{'a'}}
    };
    int ways=0,M=1e9+7;
    for(auto& p:vowels){
        temp.push_back(p.first);
        ways=(ways+permu(1,n,M,temp,vowels,dp,pos));
        temp.clear();
    }
    cout<<ways<<'\n';
}