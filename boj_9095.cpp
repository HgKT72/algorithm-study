//https://www.acmicpc.net/problem/9095
#include<iostream>

using namespace std;
int n;
int d[15];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1]=1;
    d[2]=2;
    d[3]=4;

    for(int i=4; i<11; i++){
        d[i]=d[i-1]+d[i-2]+d[i-3];
    }

    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        cout<<d[a]<<'\n';
    }

    return 0;
}