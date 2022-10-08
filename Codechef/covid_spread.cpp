#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long power(ll a,int b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a;
    }
    a=(a*1LL*a);
    b>>=1;
}
int days_less_10(int popu,int days){
    ll infected=1;
    if(days==0) return 1;
    while(days--){
        infected*=2;
    }
    if(infected>=popu) return popu;
    return infected;
}
int days_great_10(int popu,int days){
    ll infected=power(2,10);
    if(infected>=popu) return popu;
    days-=10;
    while(days--){
        infected*=3;
    }
    if(infected>=popu) return popu;
    return infected;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        ll infected;
        cin>>n>>d;
        if(d<=10){
            infected=days_less_10(n,d);
            cout<<infected<<endl;
        }
        else{
            infected=days_great_10(n,d);
            cout<<infected<<endl;
        }
    }
}