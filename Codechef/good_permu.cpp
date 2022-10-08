#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> five(6);
	for(int i=1;i<6;i++) five[i]=i;
	while(true){
		next_permutation(five.begin()+1,five.end());
		int res=0,flag=0;
		for(int i=1;i<=5;i++){
			if(five[i]==i){
				flag=1;
				break;
			}
			else{
				res=res^abs(five[i]-i);
			}
		}
		if(res==0 && flag==0) break;
	}
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n%2){
			if(n<5) cout<<-1<<endl;
			else{
				for(int i=1;i<=5;i++) cout<<five[i]<<' ';
				for(int i=7;i<=n;i++) cout<<i<<' '<<i-1<<' ';
				cout<<endl;
			}
		}
	    else{
	        for(int i=2;i<=n;i+=2){
	            cout<<i<<' '<<(i-1)<<' ';
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
