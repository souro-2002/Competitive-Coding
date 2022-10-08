#include<bits/stdc++.h>
using namespace std;
int profit(int n,int w,vector<int>& wt,vector<int>& val){
    if(n==0 || w==0) return 0;
    if(wt[n-1]<=w) return max(val[n-1]+profit(n-1,w-wt[n-1],wt,val),profit(n-1,w,wt,val));
    else return profit(n-1,w,wt,val);
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    cout<<profit(n,w,wt,val)<<endl;
}