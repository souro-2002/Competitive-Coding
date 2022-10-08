// This is a tested and verified awesome code by SOURO CHATTERJEE
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int count(vi nums,int num){
    int count_num=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==num) count_num++;
    }
    return count_num;
}
void remove(vi& nums,int num){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==num){
            nums.erase(nums.begin()+i);
            --i;
        } 
    }
}
int main(){
    int t;
    cin>>t;
    vi result,nums,ans;
    while(t--){
        int n,num;
        cin>>n;
        while(n--){
            cin>>num;
            nums.push_back(num);
        }
        for(int i=0;i<nums.size();i++){
            if(count(nums,nums[i])==nums.size() && nums[i]==0){
                ans.push_back(1);
                break;
            }
            else if(count(nums,nums[i])==nums.size()){
                ans.push_back(2);
                break;
            }
            else if(count(nums,nums[i])>1){
                ans.push_back(2);
                remove(nums,nums[i]);
                --i;
            }
            else{
                ans.push_back(1);
            }
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        result.push_back(sum);
        ans.clear();
        nums.clear();
    }
    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<endl;
    }
}