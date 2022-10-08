#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
void swap(vi& nums,int ind1,int ind2){
    int temp=nums[ind1];
    nums[ind1]=nums[ind2];
    nums[ind2]=temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int t=n;
        vi nums(n+1);
        for(int i=1;i<(n+1);i++){
            nums[i]=t;
            t--;
        }
        for(int i=2;i<(n+1);i++){
            if(nums[i]%i==0) swap(nums,i,i+1);
        }
        for(int i: nums){
            if(i==0) continue;
            cout<<i<<' ';
        }
        cout<<endl;
    }
}