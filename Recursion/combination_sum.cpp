#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vector<vi> all_combs;
void sum_generate(int pos,int sum,vi& curr_combs,vi& main_arr){
    if(sum==0){
        all_combs.push_back(curr_combs);
    }
    if(sum<0) return;
    for(int i=pos;i<main_arr.size();i++){
        curr_combs.push_back(main_arr[i]);
        sum_generate(i,sum - curr_combs[curr_combs.size()-1],curr_combs,main_arr);
        curr_combs.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    vi main_arr(n);
    for(int i=0;i<n;i++) cin>>main_arr[i];
    sort(main_arr.begin(),main_arr.end());
    int sum;
    cin>>sum;
    vi combs;
    sum_generate(0,sum,combs,main_arr);
    for(auto &vec : all_combs){
        for(int ele: vec) cout<<ele<<' ';
        cout<<endl;
    }
}