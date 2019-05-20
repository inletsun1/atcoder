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
    return firstElof.second < secondElof.second;
}
//---------------//

ll N, M;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<P > v(N);
    ll a, b;
    LREP(i, 0, N){
        cin >> a >> b;
        v[i].first = a;
        v[i].second = b;
    }
    sort(v.begin(), v.end(), firstCompare);

    ll ans = 0;
    LREP(i, 0, N){
        if(v[i].second < M){
             M -= v[i].second;
             ans += v[i].second * v[i].first;
        }else{
            ans += M * v[i].first;
            break;
        }
    }
    cout << ans << endl;
}
