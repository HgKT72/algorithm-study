//https://www.acmicpc.net/problem/11659
#include<iostream>
using namespace std;

int d[100002];
int n,m;
int s[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++)cin>>s[i];


    //Prefix sum-시간복잡도 O(N)에 가능
    //이중for문 쓰면 O(N*M)인데 10^10이라 시간초과
    //c++의 경우 1초에 대략 10^8번이 최대
    d[1]=s[1];
    for(int i=2; i<=n; i++){
        d[i]=d[i-1]+s[i];
    }


    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cout<<d[b]-d[a-1]<<"\n";
    }

    return 0;
}