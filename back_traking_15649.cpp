#include<iostream>

using namespace std;

//모든 경우를 보면서 이전 상황으로 돌아갈수 있어야함->백트레킹
int n,m;
int arr[10];
bool isused[10];

void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
            
        }
        cout<<'\n';
        return;
    }

    for(int i=1; i<=n; i++){ 

        if(!isused[i]){
            arr[k]=i;
            isused[i]=true;
            func(k+1);
            isused[i]=false;
            //다른것을 고른 상태로 넘어갔을때는 arr배열 값 위에 덮어지므로 따로 처리하지 않음
        }
       
    }
} 


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    func(0);
    return 0;
}