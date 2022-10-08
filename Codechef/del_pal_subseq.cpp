#include<bits/stdc++.h>
using namespace std;
vector<int> pal_index(int beg,int end,string& s,string& s_rev,vector<int>& index){
    if(end<beg) return index;
    if(s_rev[beg]==s[end]){
        index=pal_index(beg+1,end-1,s,s_rev,index);        
        index.push_back(end);index.push_back(beg);
        return index;
    }
    else{
        index=pal_index(beg+1,end-1,s,s_rev,index);
        return index;
    }
}
int main(){
    string s;
    cin>>s;    
    while(true){
        vector<int> index,check(s.size());
        index=pal_index(0,s.size()-1,s,s,index);
        if(index.empty()) break;
        string st;
        sort(index.begin(),index.end());
        for(int i:index) check[i]=1;
        for(int i=0;i<s.size();i++){
            if(!check[i]){
                st.push_back(s[i]);
            }
        }
        s=st;
    }
    cout<<s<<endl;
}