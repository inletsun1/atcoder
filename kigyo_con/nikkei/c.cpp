#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<ll, ll >


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;



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
    return firstElof.second > secondElof.second;
}
//---------------//

ll N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    ll ans = 0;
    ll C[N];
    ll A, B;
    LREP(i, 0, N){
        cin >> A >> B;
        ans += - B;
        C[i] = A + B;
    }
    sort(C, C + N, greater<ll >());
    for(ll i = 0; i < N; i += 2) ans += C[i];
    cout << ans << endl;
}
