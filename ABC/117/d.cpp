#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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

ll N;
ll K;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    ll A[N];
    LREP(i, 0, N){
        cin >> A[i];
    }
    ll X = 0;
    ll f = 0;
    ll tmp;
    REPR(bit, 40, 0){
        tmp = 0;
        LREP(i, 0, N){
            if(A[i] & (1L << bit)) tmp += 1;
        }
        if(K >= X + (1L << bit) && tmp < N - tmp){
            X += (1L << bit);
            tmp = N - tmp;
        }
        f += (1L << bit) * tmp;
    }

    cout << f << endl;

}
