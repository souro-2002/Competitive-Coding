#include<bits/stdc++.h>
using namespace std;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int y=0,count=0;
        while(y<x){
            y+=(power(2,count));
            count++;
        }
        count++;
        y=x+(power(2,count));
        cout<<x<<' '<<0<<' '<<y<<endl;
    }
}