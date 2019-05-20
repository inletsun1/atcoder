#include<iostream>
using namespace std;
typedef long long ll;
#define MAX_N 200000

int main(){
    ll N, K;
    cin >> N >> K;
    ll m, n, ans, zero, ans_add;
    ans = 0;
    zero = 0;
    for(ll b=1; b<=N; b++){
        m = (N+1)/b;
        n = (N+1)%b;
        ans_add = max(zero, m*(b-K)) + max(zero, n-K); 
        ans_add = max(zero, ans_add);
        ans += ans_add;
        //cout << "b = " << b << " : " << ans_add << endl;
    }
    if(K==0){
        ans = ans - N;
    }
    cout << ans << endl;

}
