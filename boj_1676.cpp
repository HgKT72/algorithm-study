/*
10!= 3,628,800 -> 팩토리얼의 값에서 0이 생길때는 10이 곱해졌을때임. 
따라서 5의 배수가 몇개 있는지 새기.(2의 배수는 많음으로)
*/
#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    int n;
    cin>>n;
    
    while(n>=5){
        ans=ans+n/5;
        n=n/5;
    }

    cout<<ans;

    return 0;
}