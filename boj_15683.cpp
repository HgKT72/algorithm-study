#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n,m;
int cameraCount;

pair<int,int> cam[9];
int board[10][10];
int mn=100;



void check(int x,int y,int dir){//위, 오른쪽, 아래, 왼쪽쪽
    
    int nx=x;
    int ny=y;

    while(1){
        switch(dir){
            case 0:
                nx--;
                break;
            case 1:
                ny++;
                break;
            case 2: 
                nx++;
                break;
            case 3:
                ny--;
                break;
        }

        if(nx<0||nx>=n||ny<0||ny>=m)break;
        if(board[nx][ny]==6)break;
        if(board[nx][ny]>0&&board[nx][ny]<6)continue;

        board[nx][ny]=-1;
    }
}

  //전체 반복횟수- 카메라의 개수만큼
void func(int camcnt){
    int before[10][10]={};
    if(camcnt==cameraCount){//재귀함수 종료조건
        int tmp=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0)tmp++;
            }
        }
        mn=min(mn,tmp);
        return;
    }

  
    int curX,curY;
    curX=cam[camcnt].first;
    curY=cam[camcnt].second;


    //copy(&board[0][0], &board[0][0]+100, &before[0][0]);

    switch(board[curX][curY]){      
        case 1:
            for(int dir=0; dir<4; dir++){
                copy(&board[0][0], &board[0][0]+100, &before[0][0]);
                check(curX,curY,dir);
                func(camcnt+1);
                copy(&before[0][0], &before[0][0] + 100, &board[0][0]);
                  
            }
            break;
        case 2:
 
            for(int dir=0; dir<2; dir++){
                copy(&board[0][0], &board[0][0]+100, &before[0][0]);
                check(curX,curY,dir);
                check(curX,curY,dir+2);
                func(camcnt+1);
                copy(&before[0][0], &before[0][0] + 100, &board[0][0]);
            }
            break;
        case 3:
               for(int dir=0; dir<4; dir++){
                   copy(&board[0][0], &board[0][0]+100, &before[0][0]);
                   check(curX,curY,dir);
                   check(curX,curY,(dir+1)%4);
                   func(camcnt+1);
                   copy(&before[0][0], &before[0][0] + 100, &board[0][0]);
               } 
               break;
        case 4:
                for(int dir=0; dir<4; dir++){
                    copy(&board[0][0], &board[0][0]+100, &before[0][0]);
                    for(int j=0; j<4; j++){
                        if(j!=dir)check(curX,curY,j);
                    }
                    func(camcnt+1);
                    copy(&before[0][0], &before[0][0] + 100, &board[0][0]);
                }
               break;
        case 5:
               for(int dir=0; dir<4; dir++){
                   check(curX,curY,dir);
                }
               func(camcnt+1);
               
               break;

           
    }




}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            cin>>board[i][j];
            if(board[i][j]>0&&board[i][j]<6){
                cam[cameraCount]={i,j};
                cameraCount++;
            
            }
        }
    }

    func(0);
    cout<<mn;

    


    return 0;
}