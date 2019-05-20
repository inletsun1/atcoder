#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int p[N], sum[N];
    for(int i=0; i<N; i++){
        cin >> p[i];
        if(i==0){
            sum[0] = p[i];
        }
        else{
            sum[i] = sum[i-1] + p[i];
        }
    }
    int dp[N][sum[N-1]+1];
    for(int i=0; i<N; i++){
        for(int j=0; j<sum[N-1]+1; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    dp[0][p[0]] = 1;
    for(int i=1; i<N; i++){
        for(int j=0; j<=sum[i]; j++){
            if(j>=p[i]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-p[i]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = 0;
    for(int j=0; j<sum[N-1]+1; j++){
        for(int i=0; i<N; i++){
            if(dp[i][j]>0){
                //cout << "ans: " << j << endl;
                ans += 1;
                break;
            }
        }
    }

    cout << ans << endl;
}
