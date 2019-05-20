#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

//#define INF 1e9 + 1
//#define MOD 1e9 + 7


typedef long long ll;


//functions 
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}

int  N;
int ans[1001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int res, idx;
    idx = 0;
    do{
        res = abs(N) % 2;
        ans[idx] = res;
        N = (N - res) / (-2);
        idx += 1;
    }while(N != 0);

    REPR(i, idx - 1, 0) cout << ans[i];
    cout << endl;

}
