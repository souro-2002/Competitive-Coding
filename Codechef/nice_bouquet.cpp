#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll m[3],o[3],p[3];
        vi ele;
        ll sum_m=0,sum_o=0,sum_p=0;
        for(int i=0;i<3;i++){
            cin>>m[i];
            sum_m+=m[i];
        }
        ele.push_back(sum_m);
        for(int i=0;i<3;i++){
            cin>>o[i];
            sum_o+=o[i];
        }
        ele.push_back(sum_o);
        for(int i=0;i<3;i++){
            cin>>p[i];
            sum_p+=p[i];
        }
        ele.push_back(sum_p);
        ele.push_back(m[0]+o[0]+p[0]);
        ele.push_back(m[1]+o[1]+p[1]);
        ele.push_back(m[2]+o[2]+p[2]);
        sort(ele.begin(),ele.end());
        if(ele[5]%2) cout<<ele[5]<<endl;
        else if(ele[5]==0) cout<<0<<endl;
        else cout<<(ele[5]-1)<<endl;
    }
}