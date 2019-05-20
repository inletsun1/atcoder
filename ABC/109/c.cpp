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

int N, X;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X;

    int x[N];
    REP(i, 0, N) cin >> x[i];

    int D;
    if(N == 1){
        D = abs(x[0] - X);
    }else{
        D = gcd(abs(x[0] - X), abs(x[1] - X));
        REP(i, 2, N){
            D = gcd(D, abs(x[i] - X));
        }
    }

    cout << D << '\n';

}
