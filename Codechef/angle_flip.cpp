#include<bits/stdc++.h>
#define int long long
#define isFind(M,num) (M.find(num)==M.end())
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> a(n,vector<int>(m,0)),b(n,vector<int>(m,0));
		bool flag=true;
		if(n==1||m==1){
			for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cin>>a[i][j];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cin>>b[i][j];
		}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(a[i][j]!=b[i][j]){
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
		else{
			int ele;
			map<int,int> a1,a2,b1,b2;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>ele;
					if((i+j)%2){
						if(isFind(a1,ele)){
							a1.insert({ele,1});
						}
						else a1.insert({ele,a1[ele]+1});
					}
					else{
						if(isFind(a2,ele)) a2.insert({ele,1});
						else a2.insert({ele,a2[ele]+1});
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>ele;
					if((i+j)%2){
						if(isFind(b1,ele)) b1.insert({ele,1});
						else b1.insert({ele,b1[ele]+1});
					}
					else{
						if(isFind(b2,ele)) b2.insert({ele,1});
						else b2.insert({ele,b2[ele]+1});
					}
				}
			}
			for(auto &p:a1){
				if(p.second!=b1[p.first]){
					flag=false;
					break;
				}
			}
			for(auto &p:a2){
				if(p.second!=b2[p.first]){
					flag=false;
					break;
				}
			}
			if(flag) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}
}