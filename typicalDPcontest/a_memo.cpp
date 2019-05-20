#include<iostream>
using namespace std;
int memo[101][100001];
int p[101];
int N;

int dp(int i, int j){
    if(memo[i][j]>=0) return memo[i][j];
    if(i==1){
        if(j==0 || j==p[1]) return memo[i][j] = 1;
        else return memo[i][j] = 0;
    }
    else if(i > 1 && j>=p[i]){
        memo[i][j] = dp(i-1, j) + dp(i-1, j-p[i]);
    }else{
        memo[i][j] = dp(i-1, j);
    }
    return memo[i][j];
}

int main(){
    cin >> N;
    p[0] = 0;
    int sum_p = 0;
    for(int i=1; i<=N; i++){
        cin >> p[i];
        sum_p += p[i];
    }
    for(int i=0; i<=N; i++){
        for(int j=0; j<=sum_p; j++){
            memo[i][j] = -1;
        }
    }
    for(int j=0; j<=sum_p; j++){
        dp(N, j);
    }
    int ans = 0;
    for(int j=0; j<=sum_p; j++){
        for(int i=1; i<=N; i++){
            if(memo[i][j]>0) {
                //cout << "ans : " << j << endl;
                ans += 1; 
                break;
            }
        }
    }
    cout << ans << endl;
}
