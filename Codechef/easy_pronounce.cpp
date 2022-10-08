#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    unordered_map<char,int> vowel={
        {'a',1},{'e',1},{'i',1},{'o',1},{'u',1}
    };
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int row=0,temp=0;
        for(char ch:s){
            if(!vowel[ch]) temp++;
            else{
                row=max(row,temp);
                temp=0;
            }
        }
        row=max(temp,row);
        if(row>=4) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}