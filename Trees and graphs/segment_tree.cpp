#include<bits/stdc++.h>
using namespace std;
int nearest_power_two(int n){
    int ct=0;
    while(n){
        n>>=1;
        ct++;
    }
    return (1<<ct);
}
int sum(int a,int b,vector<int>& tree,int n){
    a+=n;b+=n;
    int s=0;
    while(a<=b){
        if(a%2) s+=tree[a++];
        if(b%2==0) s+=tree[b--];
        a/=2;b/=2;
    }
    return s;
}
void update(int k,int x,int n,vector<int>& tree){
    k+=n;
    tree[k]+=x;
    for(k/=2;k>=1;k/=2){
        tree[k]=tree[2*k]+tree[2*k+1];
    }
}
int main(){
    int n;
    cin>>n;
    int temp=n;
    if(n&(n-1)) n=nearest_power_two(n);
    vector<int> tree(2*n);
    for(int i=n;i<n+temp;i++) cin>>tree[i];
    for(int i=n-1;i>=1;i--){
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    int i,j,k,x;
    cin>>i>>j;
    cout<<sum(i,j,tree,n)<<'\n';
    cin>>k>>x;
    update(k,x,n,tree);
    cout<<sum(i,j,tree,n)<<'\n';
}