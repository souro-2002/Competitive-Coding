#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main(){
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int sum;
    cin>>sum;
    sort(nums.begin(),nums.end());
    int lp=0,rp=n-1,temp;
    while(lp<=rp){
        temp=nums[lp]+nums[rp];
        if(temp<sum) lp++;
        if(temp==sum){
            cout<<nums[lp]<<' '<<nums[rp]<<endl;
            return 0;
        }
        if(temp>sum) rp--;
    }
    cout<<-1<<endl;
}