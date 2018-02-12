#include<iostream>
using namespace std;

int main(){

    int N, M;
    cin >> N;
    cin >> M;

    int A, B, C[N][N];
    int color[N][N];
    int ans = 0;


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = 0;
            color[i][j] = 0;
        }
    }
    for(int i=0; i<M; i++){
        cin >> A;
        cin >> B;
        C[A-1][B-1] = 1;
        C[B-1][A-1] = 1;
    }

    for(int u=0; u<N; u++){
        for(int v1=0; v1<N; v1++){
            if (C[u][v1] == 1 && (u!=v1)){
                for(int v2=0; v2<N; v2++){
                    if(C[v1][v2] == 1 && (v1!=v2) && (u!=v2)){
                        for(int v3=0; v3<N; v3++){
                            if (color[u][v3]==0 && (C[v2][v3]==1) && (C[u][v3] == 0) && (u!=v3) && (v2!=v3) && (v1!=v3)){
                                C[u][v3] = 1;
                                C[v3][u] = 1;
                                color[u][v3] = 1; 
                                color[v3][u] = 1; 
                                ans += 1;
                            }
                        
                        }
                    }
                }
            }
        
        }
    }

    cout << ans << '\n';
}
