#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        int q=x/3;
        if(x%3==0) cout<<(x*y)+(z*(--q))<<endl;
        else cout<<(x*y)+(z*q)<<endl;
    }
}