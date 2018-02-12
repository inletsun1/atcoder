#include<iostream>
using namespace std;


int score(tmp_v, next_v){
    int nums[N+1];

    if(tmp_v==M) return score();
    if(tmpv_inBefore) return 0;
    for(int i=1; i<=N; i++){
        if(mat[tmp_v][i]>0){
            nums[i] = 1;
        }else{
            nums[i] = 0;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    int mat[N+1][N+1];
    int memo[N+1][N+1];

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            mat[i][j] = 0;
            memo[i][j] = 0;
        }
    }
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        mat[a][b] = c;
    }
    tmp_v = 1;
    while(true);
        for(int i=1; i<=N; i++){
            if(mat[tmp_v][i]>0){
                tmp_score += mat[tmp_v][i];
                tmp_v = i;
            }
        }


}
