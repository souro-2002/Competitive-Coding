#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k>n){
            cout<<"NO"<<'\n';
            continue;
        }
        vector<int> pfs(k);
        for(int i=0;i<k;i++) cin>>pfs[i];
        bool flag1=true,flag2=true;
        if(k==1){
            cout<<"YES"<<'\n';
            continue;
        }
        int prev=pfs[k-1]-pfs[k-2];
        for(int i=k-2;i>0;i--){
            int curr=pfs[i]-pfs[i-1];
            if(curr>prev){
                flag1=false;
                break;
            }
            prev=curr;
        }
        int ele=pfs[1]-pfs[0];
        int sum=(n-k+1)*ele;
        if(pfs[0]>sum) flag2=false;
        if(flag1 && flag2) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n'; 
    }
}