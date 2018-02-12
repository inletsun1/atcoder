#include<iostream>

using namespace std;

struct Item{
    int v, w;
};


int main(){
    int N, W;
    
    cin >> N >> W;
    
    struct Item items[N+1];
    int c[N+1][W+1];

    for(int i=0; i<=N; i++){
        c[i][0] = 0;
    }
    for(int i=0; i<=W; i++){
        c[0][i] = 0;
    }

    items[0].w = 0;
    items[0].v = 0;
    for(int i=1; i<=N; i++){
        cin >> items[i].w >> items[i].v;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if(j<items[i].w){
                c[i][j] = c[i-1][j];
            }else{
                c[i][j] = max(c[i-1][j], c[i-1][j-items[i].w] + items[i].v);
            }
        }
    }
/*
    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    */
    cout << c[N][W] << "\n";
}
