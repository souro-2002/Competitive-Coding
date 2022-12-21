#include<bits/stdc++.h>
using namespace std;
vector<string> perms;
void permu(string& s,string& ans){
    if(s.size()==0){
        perms.push_back(ans);
        return;
    }
    for(int i=0;i<s.size();i++){
        ans.push_back(s[i]);
        string rest=s.substr(0,i)+s.substr(i+1);
        permu(rest,ans);
        ans.pop_back();
    }
}
int main(){
    string s,ans="";
    cin>>s;
    permu(s,ans);
    for(auto st:perms){
        cout<<st<<'\n';
    }
}