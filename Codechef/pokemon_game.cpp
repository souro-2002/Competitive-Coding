#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> ground(n),water(n);
	    vector<pii> gr_str,water_str;
	    for(int i=0;i<n;i++){
	        cin>>ground[i];
	        gr_str.push_back({ground[i],i});
	    }
	    for(int i=0;i<n;i++){
	        cin>>water[i];
	        water_str.push_back({water[i],i});
	    }
	    sort(gr_str.begin(),gr_str.end());
	    reverse(gr_str.begin(),gr_str.end());
	    sort(water_str.begin(),water_str.end());
	    reverse(water_str.begin(),water_str.end());
	    vector<bitset<100010>> t_g(n,bitset<100010>(0)),t_w(n,bitset<100010>(0)),t(n,bitset<100010>(0));
        pii maxi=gr_str[0];
        int ind=maxi.second;
        t_g[ind][ind]=1;
        t_g[ind]=(~t_g[ind]);
        auto b1=t_g[ind];
        for(int i=1;i<n;i++){
            pii p=gr_str[i];
            int index=p.second;
            b1[index]=0;
            t_g[index]=b1;
            b1=t_g[index];
        }
        pii _maxi=gr_str[0];
        int _ind=maxi.second;
        t_w[_ind][_ind]=1;
        t_w[_ind]=(~t_w[_ind]);
        auto _b=t_w[_ind];
        for(int i=1;i<n;i++){
            pii p=water_str[i];
            int index=p.second;
            _b[index]=0;
            t_g[index]=_b;
            _b=t_g[index];
        }
        for(int i=0;i<n;i++){
            t[i]=t_g[i]|t_w[i];
        }
        int max_bits=0;
        for(auto &b:t){
            int num=b.count();
            max_bits=max(max_bits,num);
        }
        int ans=0;
        for(auto& b:t){
            int num=b.count();
            if(num==max_bits) ans++;
        }
        cout<<ans<<'\n';
	}
	return 0;
}
