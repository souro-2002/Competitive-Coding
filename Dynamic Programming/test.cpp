#include<bits/stdc++.h>
using namespace std;
bool match(string& a,string& b){
    bool same=true;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]&&a[i]!='?'){
            same=false;
            break;
        }
    }
    return same;
}
bool full(string& a){
    bool flag=true;
    for(char ch:a){
        if(ch!='?'){
            flag=false;
            break;
        }
    }
    return flag;
}
int main(){
    string sta,tar;
    cin>>sta>>tar;
    int lim=tar.size()-sta.size();
    vector<int> ans;
    bool yes=true;
    while(yes){
        yes=false;
        for(int i=0;i<=lim;i++){
            string sub=tar.substr(i,sta.size());
            if(match(sub,sta)){
                yes=true;
                ans.push_back(i);
                for(int j=0;j<sta.size();j++) tar[i+j]='?';
            }
        }
        if(full(tar)) break;
    }
    if(ans.empty()) cout<<-1<<'\n';
    else{
        for(int ele:ans) cout<<ele<<' ';
        cout<<'\n';
    }
}