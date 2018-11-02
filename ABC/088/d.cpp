#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int > P;
int d[51][51];
int H, W;
char maze[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int INF = 3000;

int bfs(){
    queue<P > que;
    que.push(P(0, 0));
    d[0][0] = 0;
    while(que.size()){
        P p = que.front(); que.pop();  
        if(p.first==H || p.second==W){
            break;
        }
        for (int i=0; i<4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
               // cout << "next:"  << nx << ", " << ny << endl;;
            if(0<=nx && nx<=H-1 && 0<=ny && ny<=W-1 && maze[nx][ny]=='.' && d[nx][ny]==INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
            
        }
    }
    return d[H-1][W-1];
}
int main(){
    cin >> H >> W;
    int black_num = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> maze[i][j];
            if(maze[i][j]=='#'){
                black_num += 1;
            }
            d[i][j] = INF;
        }
    }
    int length = bfs();
    int ans;
    if (bfs()!=INF){
        ans = H*W;
        ans -= length;
        ans -= black_num;
        ans -= 1;
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    /*
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << d[i][j] << ", ";
        }
        cout << endl;
    }
    */
}
