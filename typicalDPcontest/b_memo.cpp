#include<iostream>
using namespace std;
int A, B;
int a[1001], b[1001];
int memo[1001][1001];

int dp(int n, int m){
    if(memo[n][m]>0) return memo[n][m];
    if((n+m)%2==1){
        if(n==0){
            memo[n][m] = dp(0, m-1) + b[m];
        }else if(m==0){
            memo[n][m] = dp(n-1, 0) + a[n];
        }else{
            memo[n][m] = max(dp(n-1, m)+a[n], dp(n, m-1)+b[m]);
        }
    }else{
        if(n==0 && m==0){
            return 0;
        }else if(n==0){
            memo[n][m] = dp(0, m-1);
        }else if(m==0){
            memo[n][m] = dp(n-1, 0);
        }else{
            memo[n][m] = min(dp(n-1, m), dp(n, m-1));
        }
    }
    return memo[n][m];
}
int main(){
    cin >> A >> B;
    a[0] = 0; b[0] = 0;
    for(int i=1; i<=A; i++){
        cin >> a[i];
    }
    for(int i=1; i<=B; i++){
        cin >> b[i];
    }
    for(int i=0; i<=A; i++){
        for(int j=0; j<=B; j++){
            memo[i][j] = 0;
        }
    }

    cout << dp(A, B) << endl;
    for(int n=0; n<=A; n++){
        for(int m=0; m<=B; m++){
            cout << memo[n][m] << " ";
        }
        cout << endl;
    }
}
