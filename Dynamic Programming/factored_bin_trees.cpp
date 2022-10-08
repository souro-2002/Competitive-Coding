#include<bits/stdc++.h>
using namespace std;
int trees(int root,vector<int>& nums,unordered_map<int,int>& present){
    queue<int> q;
    int M=1e9+7;
    int ct=1;
    q.push(root);
    while(!q.empty()){
        int num=q.front();
        q.pop();
        for(int ele:nums){
            if(ele==num) continue;
            if(num%ele==0){
                int n=num/ele;
                if(present[n]){
                    ct++;
                    q.push(ele);q.push(n);
                }
            }
        }
    }
    return ct%M;
}
int main(){
    int n,M=1e9+7;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    unordered_map<int,int> present;
    for(int ele:nums) present[ele]++;
    int ways=0;
    for(int ele:nums){
        int way=trees(ele,nums,present);
        ways=(ways+way)%M;
        cout<<way<<endl;
    }
    cout<<ways<<'\n';
}