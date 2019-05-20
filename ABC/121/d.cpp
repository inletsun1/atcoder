#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


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
    return firstElof.second < secondElof.second;
}
//---------------//

ll A, B;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> A >> B;
    ll max_len = 0;
    ll tmp = B;
    while(tmp > 1){
        max_len += 1;
        tmp /= 2;
    }

    ll ans = 0;
    ll a, b;
    ll div, mod;
    B += 1; 
    LREP(i, 0, max_len + 1){
        a = 0;
        b = 0;
        div = A / (1L << (i + 1));
        a = div * (1L << i);
        mod = A % (1L << (i + 1));
        if(mod > (1L << i)){
            a += mod - (1L << i);
        }
        div = B / (1L << (i + 1));
        b = div * (1L << i);
        mod = B % (1L << (i + 1));
        if(mod > (1L << i)){
            b += mod - (1L << i);
        }
        if((b - a) % 2 == 1){
            ans += (1L << i);
        }
    }
    cout << ans << endl;
}
