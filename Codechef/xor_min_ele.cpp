#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i:nums) p.push(i);
        while(y){
            int low=p.top();
            int temp=low^x;
            if(temp>low){
                p.pop();
                p.push(temp);
            }
            else break;
            y--;
        }
        if(y%2){
            int ele=p.top();
            int t=ele^x;
            p.pop();
            p.push(t);
        }
        while(!p.empty()){
            std::cout<<p.top()<<' ';
            p.pop();
        }
        std::cout<<'\n';
    }
}