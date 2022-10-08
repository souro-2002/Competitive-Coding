#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vector<vi> all_subsets;
void generate(vi& subsets,int i,vi& nums){
    if(i==nums.size()){
        all_subsets.push_back(subsets);
        return;
    }
    generate(subsets,i+1,nums);
    subsets.push_back(nums[i]);
    generate(subsets,i+1,nums);
    subsets.pop_back();
}
int main(){
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vi subsets;
    generate(subsets,0,nums);
    for(auto &vec:all_subsets){
        if(!vec.size()){
            cout<<"[]"<<endl;
            continue;
        }
        for(auto &ele : vec) cout<<ele<<' ';
        cout<<endl;
    }
}