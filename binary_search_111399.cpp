
#include<iostream>

using namespace std;

using ll=long long;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    ll left=1; 
    ll right=n;
    ll ans=-1;
    //이진 탐색
    while(left<=right){
        ll mid=(left+right)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }else if(mid*mid<n){
            left=mid+1;
        }else{
            right=mid-1;
        }
       


    }

    cout<<ans;
    return 0;
}