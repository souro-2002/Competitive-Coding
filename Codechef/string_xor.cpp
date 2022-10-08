#include<bits/stdc++.h>
using namespace std;
int count_ch(string& st,char ch){
    int ct=0;
    for(char c:st){
        if(c==ch) ct++;
    }
    return ct;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        if(a==b) cout<<"YES"<<endl;
        else{
            int ct_1=count_ch(a,'1');
            if(ct_1==0) cout<<"NO"<<endl;
            else{
                bool flag=false;
                for(int i=1;i<n;i++){
                    if(b[i]==b[i-1]){
                        flag=true;
                    }
                }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
}