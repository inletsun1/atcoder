#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;

typedef long long ll;


//---functions---//
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}
//---------------//

int divnum2(int n){
    int ans = 0;
    while(n % 2 == 0){
        ans += 1;
        n /= 2;
    }
    return ans;
}
ll N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int a[N];
    REP(i, 0, N) cin >> a[i];

    int ans = 0;
    REP(i, 0, N){
        ans += divnum2(a[i]);
    }
    cout << ans << endl;
}
