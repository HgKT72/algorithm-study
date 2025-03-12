#include<iostream>
#include<queue>
#include<tuple>
#include<utility>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

char board[1002][1002];
int dist[1002][1002][11][2];
int n,m,k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    dist[0][0][0][0]=1;
    queue<tuple<int,int,int,int>>Q;
    Q.push({0,0,0,0});

    while(!Q.empty()){
        int curX,curY,curW,day;
        tie(curX,curY,curW,day)=Q.front();
        if(curX==n-1&&curY==m-1){
            cout<<dist[curX][curY][curW][day];
            return 0;
        }

        Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx=curX+dx[dir];
            int ny=curY+dy[dir];
            int nw=curW;

            if(nx<0||nx>=n||ny<0||ny>=m)continue; //벗어나는지
            if(dist[nx][ny][nw][day]>0)continue;
            if(board[nx][ny]=='1')nw++;
            if(nw>k||dist[nx][ny][nw][1-day]>0)continue;

            if(board[nx][ny]=='1'){
                if(day==0){
                    dist[nx][ny][nw][1]=dist[curX][curY][curW][0]+1;
                    Q.push({nx,ny,nw,1});
                }
                else{
                    dist[curX][curY][curW][0]=dist[curX][curY][curW][1]+1;
                    Q.push({curX,curY,curW,0});
                }
            }
            else{
                dist[nx][ny][nw][1-day]=dist[curX][curY][curW][day]+1;
                Q.push({ nx,ny,nw,1 - day });
            }
        }
    }

    cout<<-1;

    return 0;
}
