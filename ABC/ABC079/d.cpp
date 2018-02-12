#include<iostream>
using namespace std;

static const int INFTY=1001;
static const int MAX = 10;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int H, W;
int c[10][10];
int d[MAX];
int color[MAX];

void dijkstra(){
    int minv;
    for (int i=0; i<MAX; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[1] = 0;
    color[0] = GRAY;
    while(true){
        minv = INFTY;
        int u = -1;
        for(int i=0; i<MAX; i++){
            if(minv>d[i] && color[i]!=BLACK){
                u = i;
                minv = d[i];
            }
        }
        if(u==-1) break;
        color[u] = BLACK;
        for(int v=0; v < MAX; v++){
            if(color[v]!=BLACK && c[u][v]!=INFTY){
                if(d[v]>d[u] + c[u][v]){
                    d[v] = d[u] + c[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
}
int main(){
    cin >> H;
    cin >> W;
    int A[H][W];
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            cin >> c[j][i];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    dijkstra();

    int ans_cost = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(A[i][j]>-1){
                ans_cost = ans_cost + d[A[i][j]];
            }
        }
    }
    cout << ans_cost << '\n';
}
