#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cookie(n+1);
        map<int,set<int>> cook_ct;
        for(int i=1;i<n+1;i++){
            cin>>cookie[i];
            int num;
            for(int _=0;_<cookie[i];_++){
                cin>>num;
                cook_ct[i].insert(num);
            }
        }
        vector<int> points(n+1),pts_copy(n+1);
        for(int i=1;i<n+1;i++){
            int len=cook_ct[i].size();
            int extra_pt=0;
            if(len==4) extra_pt=2;
            if(len==5) extra_pt=4;
            if(len==6) extra_pt=6;
            points[i]=cookie[i]+extra_pt;
        }
        pts_copy=points;
        sort(pts_copy.begin(),pts_copy.end());
        if(pts_copy[pts_copy.size()-1]==pts_copy[pts_copy.size()-2]) cout<<"tie"<<endl;
        else{
            for(int i=1;i<n+1;i++){
                if(points[i]==*max_element(points.begin(),points.end())){
                    if(i==1){
                        cout<<"chef"<<endl;
                        break;
                    }
                    else{
                        cout<<i<<endl;
                        break;
                    }
                }
            }
        }
    }
}