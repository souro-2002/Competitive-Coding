#include <bits/stdc++.h>
using namespace std;
int first_one(string& st){
    for(int i=0;i<st.size();i++){
        if(st[i]=='1'){
            return i;
            break;
        }
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
	    int ind=1;
	    for(int i=first+1;i<n;i++){
	        if(st[i]=='1') break;
	        ind++;
	    }
	    cout<<ind<<'\n';
	}
	return 0;
}
