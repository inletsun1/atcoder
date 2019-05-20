#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;



//---functions---//
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}

bool firstCompare(const P& firstElof, const P& secondElof){
    return firstElof.first < secondElof.first;
}
bool secondCompare(const P& firstElof, const P& secondElof){
    return firstElof.second < secondElof.second;
}
//---------------//

ll N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    ll ans;
    if(N < 4){
        if(N == 0) ans = 1;
        else if(N == 1) ans = 4;
        else if(N == 2) ans = 16;
        else if(N == 3) ans = 61;
    }else{
        ll memo[N + 1];
        memo[0] = 1;
        memo[1] = 4;
        memo[2] = 16;
        memo[3] = 61;
        LREP(i, 4, N + 1){
            memo[i] = ((2 * memo[i-3]) % MOD + (6 * memo[i-4]) % MOD) % MOD; 
            memo[i] = ((4 * memo[i-1]) % MOD - memo[i]) % MOD;
            if(memo[i] < 0) memo[i] += MOD;
        }
        ans = memo[N];
    }
    cout << ans << endl;
}
