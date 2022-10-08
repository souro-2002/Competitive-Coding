#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int L=1e5+1;
bool valid(vi arr,int num){
    int len=1,sum=num;
    for(int i=arr.size()-1;i>=0;i--){
        sum+=arr[i];
        len++;
        if(sum%len==0) return false;
    }
    return true;
}
int main(){
    vi nums(L);
    nums.clear();
    nums.push_back(0);
    for(int i=1;i<L;i++) nums.push_back(i);
    int t;
    cin>>t;
    while(t--){
        int n,ct=2;
        cin>>n;
        vi res;
        res.push_back(1);
        res.push_back(2);
        for(int i=2;i<n;i++){
            while (valid(res,nums[ct])==false)
            {
                ct++;
            }
            res.push_back(nums[ct]);
        }
        for(auto it=res.begin();it!=res.end();it++) cout<<*it<<' ';
        cout<<endl;
    }
}