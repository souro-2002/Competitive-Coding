#include <bits/stdc++.h>
#define ll long long
using namespace std;
int num_of_pairs(ll sum,unordered_map<ll,ll>& mp,vector<ll>& nums){
	ll ct=0;
	for(int i:nums){
		ct+=mp[sum-i];
		if((sum-i)==i) ct--;
	}
	return ct/2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		unordered_map<ll,ll> rep_ct;
		int n;
		cin>>n;
		vector<ll> weights(n);
		for(int i=0;i<n;i++){
			cin>>weights[i];
			rep_ct[weights[i]]++;
		}
		long long wt_sum=accumulate(weights.begin(),weights.end(),0);
		if((2*wt_sum)%n) cout<<0<<endl;
		else{
			ll sum=(2*wt_sum)/n;
			cout<<num_of_pairs(sum,rep_ct,weights)<<endl;
		}
	}
}