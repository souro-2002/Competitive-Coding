#include <bits/stdc++.h>
using namespace std;
int first_one(string& st){
    for(int i=0;i<st.size();i++){
        if(st[i]=='1') return i;
    }
    return -1;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string st;
	    cin>>n>>st;
	    int first=first_one(st);
	    if(first==-1||first==n-1){
	        cout<<1<<'\n';
	        continue;
	    }
	    int ind=0;
	    for(int i=first;i<n;i++){
	        if(st[i]=='0' && i!=0){
	            break;
	        }
	        ind++;
	    }
	    if(ind==-1) cout<<n<<'\n';
	    else cout<<ind<<'\n';
	}
	return 0;
}
