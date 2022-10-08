#include<bits/stdc++.h>
#define vs vector<string>
#define mis unordered_map<char,string>
using namespace std;
void generate(mis& mp,vs& combs,string& letters,string& digits,int pos){
    if(letters.size()==digits.size()){
        combs.push_back(letters);
        return;
    }
    string curr=mp[digits[pos]];
    for(int i=0;i<curr.size();i++){
        letters.push_back(curr[i]);
        generate(mp,combs,letters,digits,pos+1);
        letters.pop_back();
    }
}
vs phn_number_combs(string& digits,mis mp){
    vs all_combs;
    string letters="";
    generate(mp,all_combs,letters,digits,0);
    return all_combs;
}
int main(){
    mis keys={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    string digits;
    cin>>digits;
    vs all_combs=phn_number_combs(digits,keys);
    for(string comb:all_combs) cout<<comb<<' ';
}