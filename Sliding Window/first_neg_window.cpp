#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    queue<int> q;
    for(int i=0;i<n;i++){
        if(nums[i]<0) q.push(i);
    }
    int lp=0,rp=k-1;
    while(rp<n){
        if(q.empty()||q.front()>rp){
            cout<<0<<' ';
        }
        else{
            int index=q.front();
            if(index==lp){
                cout<<nums[lp]<<' ';
                q.pop();
            }
            else cout<<nums[index]<<' ';
        }
        lp++;rp++;
    }
    cout<<'\n';
}