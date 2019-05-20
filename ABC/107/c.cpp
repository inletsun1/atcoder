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

int N, K;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    int x[N];
    int idx;

    REP(i, 0, N) cin >> x[i];

    REP(i, 0, N - 1){
        if(x[i] <= 0 && x[i+1] >= 0){
            idx = i;
        }
    }
    
    if(x[0] >= 0){
        cout << x[K-1] << endl;
    }else if(x[N-1] < 0){
        cout << - x[N-K] << endl;
    }else{
        int start = max(0, idx-K+1);
        int ans = INF;
        REP(i, start, N - K + 1){
            ans = min(ans, abs(x[i]) + 2 * abs(x[i+K-1]));
            ans = min(ans, 2 * abs(x[i]) + abs(x[i+K-1]));
        }
        cout << ans << endl;
    }
}
