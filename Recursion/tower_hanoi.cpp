#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char src,char helper,char dest){
    if(n==0) return;
    hanoi(n-1,src,dest,helper);
    cout<<"Move from "<<src<<" to "<<dest<<'\n';
    hanoi(n-1,helper,src,dest);
}
int main(){
    int n;
    cout<<"Enter the number of disks = ";
    cin>>n;
    hanoi(n,'A','B','C');
}