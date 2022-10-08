#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;    //N-----Hills and M---Valleys
    cin>>T;
    string st[T];
    int size_s[T];
    for(int i=0;i<T;i++){
        int N,M;
        cin>>N>>M;
        string s;
        if(N>M){
            N=N-M;
            while(M!=0){
                s+="01";
                M--;
            }
            while(N!=0){
                s+="010";
                N--;
            }
        }
        else if(N<M){
            M=M-N;
            while(N!=0){
                s+="10";
                N--;
            }
            while(M!=0){
                s+="101";
                M--;
            }
        }
        else{
            while(N+1!=0){
                s+="01";
                N--;
            }
        }
        st[i]=s;
        size_s[i]=s.size();
    }
    for(int i=0;i<T;i++){
        cout<<size_s[i]<<endl;
        cout<<st[i]<<endl;
    }
    return 0;
}