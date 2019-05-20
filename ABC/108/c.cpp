#include<bits/stdc++.h>

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define INF 1e9 + 1;
#define MOD 1e9 + 7;

typedef long long ll;
//typedef pair<int, int > P;
//typedef pair<ll, ll > LP;

using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

ll N, K;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    ll ans;
    ll num;
    num = N / K;
    ans = num * num * num;
    if(K % 2 == 0){
        num = (N + K / 2) / K;
        ans = ans + num * num * num;
    }
    cout << ans << endl;

}
