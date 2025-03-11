#include<iostream>
#include<tuple>
#include<queue>
#include<string>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string board[1005];
int dist[1005][1005][11];
int n, m, k;


void bfs() {
    queue<tuple<int, int, int>>Q;

    dist[0][0][0] = 1;
    Q.push({ 0, 0, 0 });

    int broken = 0;


    while (!Q.empty()) {
        int curX, curY;
        tie(curX, curY, broken) = Q.front();


        if (curX == n - 1 && curY == m - 1) {
            cout << dist[curX][curY][broken];
            return;
        }
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + curX;
            int ny = dy[dir] + curY;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;

            if (board[nx][ny] == '0' && dist[nx][ny][broken] == 0) {//벽을 부수지 않아도 될때
                dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
                Q.push({ nx,ny,broken });
            }

            if (board[nx][ny] == '1' && broken < k && dist[nx][ny][broken] == 0) {// k번 미만으로 벽을 부순 상태에서 벽을 만났을때
                dist[nx][ny][broken + 1] = dist[curX][curY][broken] + 1;//벽을 부순 상태공간으로 이동 broken+1
                Q.push({ nx,ny,broken + 1 });
            }

        }

    }
    cout << -1;
    return;

}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    queue<tuple<int, int, int>>Q;
    Q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    //int broken;
    while (!Q.empty()) {
        int curX, curY, w;
        tie(curX, curY, w) = Q.front();


        if (curX == n - 1 && curY == m - 1) {
            cout << dist[curX][curY][w];
            return 0;
        }

        Q.pop();



        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + curX;
            int ny = dy[dir] + curY;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;


            int nw = w;
            if (board[nx][ny] == '1')nw++;
            if (nw > k || dist[nx][ny][nw] > 0)continue;//방문한 적 있는지 체크

            dist[nx][ny][nw] = dist[curX][curY][w] + 1;
            Q.push({ nx,ny,nw });

        }

    }

    cout << -1;


    return 0;
}