#include<iostream>
#include<cstdlib>

using namespace std;

typedef long long ll;
#define divide 1000000007

int main(){
    ll N, M;
    cin >> N >> M;
    if(N < M) swap(N, M);
    ll ans1, ans2;
    ans1 = 1;
    if(N-M>1){
        cout << 0 << endl;
        return 0;
    }
    for(ll i=1; i<=N; i++){
        ans1 = ans1*i%divide;
        if(i==N-1 && N!=M) ans2 = ans1;
        if(i==N && N==M) ans2 = 2*ans1%divide;
    }
    ans1 = ans1*ans2%divide;
    cout << ans1 << endl;
}
