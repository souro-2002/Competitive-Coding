#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e9+7;
const int N=1e5+7;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}
vector<int> ones(N),sz(N);
void precompute(){
    ones[0]=0;ones[1]=1;
    sz[0]=sz[1]=1;
    for(int i=2;i<N;i++){
        ones[i]=(ones[i-1]+ones[i-2])%M;
        sz[i]=(sz[i-1]+sz[i-2])%(M-1);
    }
}
int main(){
    int t;
    cin>>t;
    precompute();
    while(t--){
        int n;
        cin>>n;
        int ans=(ones[n]*1LL*power(2,(sz[n]-1)%(M-1)))%M;
        cout<<ans<<endl;
    }
}