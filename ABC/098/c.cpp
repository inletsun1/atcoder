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

int N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    char S[N];
    int e[N], w[N];
    REP(i, 0, N){
        cin >> S[i]; 
        e[i] = 0; 
        w[i] = 0;
    }
    if(S[0] == 'W') w[0] = 1;
    REP(i, 1, N){
        if(S[i] == 'W'){
            w[i] = w[i-1] + 1;
        }else{
            w[i] = w[i-1];
        }
    }
    if(S[N-1] == 'E') e[N-1] = 1;
    REPR(i, N - 2, 0){
        if(S[i] == 'E'){
            e[i] = e[i+1] + 1;
        }else{
            e[i] = e[i+1];
        }
    }
    /*
    cout << "w = ";
    REP(i, 0, N) cout << w[i];
    cout << endl;
    cout << "e = ";
    REP(i, 0, N) cout << e[i];
    cout << endl;
    */
    int ans = INF;
    REP(i, 0, N){
        if(i == 0){
            ans = min(ans, e[1]);
        }else if(i == N - 1){
            ans = min(ans, w[N-2]);
        }else{
            ans = min(ans, w[i-1] + e[i+1]);
        }
    }

    cout << ans << endl;
}
