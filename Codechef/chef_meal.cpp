#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> present={
    {'c',1},{'o',1},{'d',1},{'e',1},{'h',1},{'f',1}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> ing(n);
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++) cin>>ing[i];
        for(auto &s:ing){
            for(int i=0;i<s.size();i++){
                if(present[s[i]]) freq[s[i]]++;
            }
        }
        int dish=INT_MAX;
        for(auto &p:freq){
            if(p.first=='e'||p.first=='c') dish=min(dish,p.second/2);
            else dish=min(dish,p.second);
        }
        cout<<dish<<endl;
    }
}