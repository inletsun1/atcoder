#include<iostream>
using namespace std;

typedef long long ll;

#define BLACK false
#define WHITE true

ll N;
ll M;
bool mat[200000][200000], memo[200000];

bool BFS(int depth,  ll tmp){
    memo[tmp] = BLACK;
    if(depth==2){
        if(tmp==N-1){
            return true;
        }else{
            return false;
        }
    }
    for(ll i=0; i<N; i++){
        if(mat[tmp][i] && memo[i]){
            if(BFS(depth+1, i)) return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    ll a, b;
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            mat[i][j] = false;
            cout << "hoge" << endl;
        }
    }
    for(ll i=0; i<N; i++){
        memo[i] = WHITE;
    }
    memo[0] = BLACK;
    for(ll i=0; i<M; i++){
        cin >> a >> b;
        mat[a-1][b-1] = true;
        mat[b-1][a-1] = true;
    }
    
    if(BFS(0, 0)){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
