#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


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

bool firstCompare(const P& firstElof, const P& secondElof){
    return firstElof.first < secondElof.first;
}
bool secondCompare(const P& firstElof, const P& secondElof){
    return firstElof.second > secondElof.second;
}
//---------------//

int N, M;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<int > X(M);
    vector<P > dX(M-1);
    REP(i, 0, M) cin >> X[i];

    if(N >= M){
        cout << 0 << endl;
    }else{

        sort(X.begin(), X.end());

        REP(i, 0, M - 1) dX[i].second = X[i+1] - X[i], dX[i].first = i + 1;

        sort(dX.begin(), dX.end(), secondCompare);

        /*
        REP(i, 0, M) cout << X[i] << " ";
        cout << endl;

        REP(i, 0, M - 1) cout << dX[i].first << " ";
        cout << endl;
        */

        bool A[M];
        REP(i, 0, M) A[i] = true;
        A[0] = false;

        REP(i, 0, N - 1){
            A[dX[i].first] = false;
        }

        ll ans = 0;
        sort(dX.begin(), dX.end(), firstCompare);

        /*
        REP(i, 0, M){
            if(A[i]) cout << X[i] << " ";
            else cout << ". ";
        }
        cout << endl;
        */
        REP(i, 0, M - 1){
            if(A[i+1]) ans += dX[i].second;
        }

        cout << ans << endl;
    }
}
