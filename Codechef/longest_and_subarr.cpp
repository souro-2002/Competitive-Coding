#include <iostream>
#include <vector>
#define int long long
using namespace std;

void precompute(vector<int>& twos){
    for(int i=0;i<=40;i++){
        twos.push_back(1<<i);
    }
}

signed main() {
	vector<int> twos;precompute(twos);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==1 || n==2){
	        cout<<1<<endl;
	        continue;
	    }
	    int beg=0,end=twos.size()-1,mid=0;
		while(end-beg>1){
			mid=(beg+end)/2;
			if(twos[mid]>n) end=mid;
			else if(twos[mid]==n) break;
			else beg=mid;
		}
		if(twos[mid]==n) cout<<twos[mid]-twos[mid-1]<<endl;
		else{
			if(twos[beg]>n){
				cout<<max(abs(twos[beg-1]-n),twos[beg-1]-twos[beg-2])<<endl;
			}
			else{
				cout<<max(n-twos[beg],twos[beg]-twos[beg-1])<<endl;
			}
		}
	}
	return 0;
}
