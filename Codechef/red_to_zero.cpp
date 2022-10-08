#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==b) cout<<a<<endl;
        else if(a==0 || b==0) cout<<-1<<endl;
        else{
            int steps=0;
            if(a>b) swap(a,b);
            while(a<=b){
                a*=2;
                steps++;
            }
            steps--;
            if(a/2==b) cout<<b+steps<<endl;
            else cout<<b+steps+1<<endl;
        }
    }
}