#include<bits/stdc++.h>
using namespace std;
void create_tree(vector<int>& tree,vector<int>& prefix_sum){
    for(int i=1;i<tree.size();i++){
        int pk=i&-i;
        tree[i]=prefix_sum[i]-prefix_sum[i-pk];
    }
}
int sum(vector<int>& tree,int i,int j){
    int sum=0;
    while(j>=i){
        sum+=tree[j];
        j-=(j&-j);
    }
    return sum;
}
void update(vector<int>& tree,int i,int x){
    while(i<tree.size()){
        tree[i]+=x;
        i+=(i&-i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++) cin>>nums[i];
    vector<int> prefix_sum(n+1),tree(n+1);
    prefix_sum[0]=0;
    for(int i=1;i<=n;i++){
        prefix_sum[i]=nums[i]+prefix_sum[i-1];
    }
    create_tree(tree,prefix_sum);
    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='A'){
            int i,x;
            cin>>i>>x;
            update(tree,i,x);
        }
        if(ch=='B'){
            int i,j;
            cin>>i>>j;
            cout<<sum(tree,i,j)<<'\n';
        }
    }
}