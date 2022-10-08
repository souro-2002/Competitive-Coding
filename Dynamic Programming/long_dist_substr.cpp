#include<bits/stdc++.h>
using namespace std;
int main(){
    string st;
    cin>>st;
    unordered_map<char,int> ch_ct;
    vector<string> substrs;
    string temp;
    for(char ch:st){
        if(ch_ct[ch]){
            substrs.push_back(temp);
            ch_ct.clear();
            temp="";
            temp.push_back(ch);
            ch_ct[ch]++;
        }
        else{
            temp.push_back(ch);
            ch_ct[ch]++;
        }
    }
    if(substrs.empty()) cout<<st;
    else{
        string max_substr;
        int max_len=substrs[0].size();
        for(string str:substrs){
            if(str.size()>=max_len){
                max_substr=str;
                max_len=str.size();
            }
        }
        cout<<max_substr<<endl;
    }
}