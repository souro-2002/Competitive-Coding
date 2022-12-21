#include<bits/stdc++.h>
using namespace std;
vector<string> par_combs;
void generate(int open,int close,string& brackets){
    if(open==0 && close==0){
        par_combs.push_back(brackets);
        return;
    }
    if(open){
        brackets.push_back('(');
        generate(open-1,close,brackets);
        brackets.pop_back();
    }
    if(close>open){
        brackets.push_back(')');
        generate(open,close-1,brackets);
        brackets.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string temp="";
    generate(n,n,temp);
    for(string &ele : par_combs){
        cout<<ele<<endl;
    }
}