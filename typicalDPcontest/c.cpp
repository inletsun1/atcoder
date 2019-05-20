#include<iostream>
using namespace std;
int K;
int R[1025];

int main(){
    cin >> K;
    for(int i=0; i<2**K; i++){
        cin >> R[i];
    }
    int dp[2**K+1][K+1];
    for(int i=0; i<(1<<K); i++){
        for(int j=1; j<=K; j++){
            for(int bit=(0|~(i<<K-1)); ;bit++)
        }
    }
}
