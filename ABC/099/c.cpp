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
vector<int > v;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int ans = 0;
    int idx = N / 9;
    int num = 9;
    while(idx / 9 > 0){
        idx /= 9;
        num *= 9;
        v.push_back(num);
    }
    idx = N / 6;
    num = 6;
    while(idx / 6 > 0){
        idx /= 6;
        num *= 6;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    REP(i, 0, v.size()) cout << v[i] << " ";
    cout << endl;

    while(N > 0 && v.size() > 0){
        if(N >= v.back()){
            cout << v.back() << " ";
            ans += 1;
            N -= v.back();
        }else{
            v.pop_back();
        }
    }
    cout << N << endl;
    int ans2 = INF;
    REP(i, 0, 6){
        if((N - i) / 6 * 6 + (N - i) /9 * 9 == N - i){
            ans2 = min(ans2, (N - i) / 6 + (N - i) / 9);
        }
    }

    ans += ans2;

    cout << ans << endl;
}
