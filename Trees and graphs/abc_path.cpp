#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=60;
const int INF=1e9+10;
vector<vector<char>> letters;
unordered_set<ll> paths;
int h,w;

vector<pair<int,int>> movements={
    {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}
};

void reset(){
    letters.clear();
    paths.clear();
    h=w=0;
}

bool isValid(int p_x,int p_y,int c_x,int c_y){
    return (c_x>=0 && c_y>=0 && c_x<w && c_y<h && (letters[c_x][c_y]-letters[p_x][p_y])==1);
}

void dfs(int x,int y,int p_x=-1,int p_y=-1,ll length=0){
    if(p_x!=-1 && p_y!=-1){
        if((x==p_x)&&(y==p_y)) return;
        if(!isValid(p_x,p_y,x,y)) return;
    }
    length++;
    paths.insert(length);
    for(auto& move:movements){
        int move_x=move.first;
        int move_y=move.second;
        dfs(x+move_x,y+move_y,x,y,length);
    }
}

int main(){
    reset();
    cin>>h>>w;
    vector<pair<int,int>> a_pos;
    for(int i=0;i<h;i++){
        vector<char> temp(w);
        for(int j=0;j<w;j++){
            cin>>temp[j];
            if(temp[j]=='A') a_pos.push_back({i,j});
        }
        letters.push_back(temp);
    }
    char ch1,ch2;
    cin>>ch1>>ch2;
    if(a_pos.empty()) cout<<"Case 1: "<<0<<endl;
    else{
        for(auto& p:a_pos){
            dfs(p.first,p.second);
        }
        ll max_len=*max_element(paths.begin(),paths.end());
        cout<<"Case #"<<1<<": "<<max_len<<endl;
    }
}