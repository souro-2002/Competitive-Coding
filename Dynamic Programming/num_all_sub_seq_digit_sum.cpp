#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int digit_sum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
vi digits(int n){
    vi digs;
    while(n){
        digs.push_back(n%10);
        n=n/10;
    }
    reverse(digs.begin(),digs.end());
    return digs;
}
vi all_subsets;
void sub_seq(int i,vi& digs,int num){
    if(i==digs.size()){
        if(num){
            all_subsets.push_back(num);
        }
        return;
    }
    sub_seq(i+1,digs,num);
    num=num*10+digs[i];
    sub_seq(i+1,digs,num);
    num=num/10;
}
int main(){
    int n;
    cin>>n;
    vi digs=digits(n);
    sub_seq(0,digs,0);
    for(int i:all_subsets) cout<<digit_sum(i)<<' ';
}