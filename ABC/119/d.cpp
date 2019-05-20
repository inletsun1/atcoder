#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


const ll INF = 3e10 + 1;
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

ll A, B, Q;
vector<ll > s, t, x;

bool isOK_s(ll index, ll key) {
    if (s[index] >= key) return true;
    else return false;
}
bool isOK_t(ll index, ll key) {
    if (t[index] >= key) return true;
    else return false;
}
ll bs_s(ll key) {
    ll ng = -1;
    ll ok = (ll)s.size(); 

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK_s(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}
ll bs_t(ll key) {
    ll ng = -1;
    ll ok = (ll)t.size(); 

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK_t(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> A >> B >> Q;
    ll tmp;
    LREP(i, 0, A){
        cin >> tmp;
        s.push_back(tmp);
    } 
    LREP(i, 0, B){
        cin >> tmp;
        t.push_back(tmp);
    } 
    LREP(i, 0, Q){
        cin >> tmp;
        x.push_back(tmp);
    } 
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());


    ll idx_s, idx_t;
    ll ans;
    LREP(i, 0, Q){
        ans = INF;
        idx_s = bs_s(x[i]);
        idx_t = bs_t(x[i]);
        if(idx_s < A && idx_t < B && s[idx_s] >= t[idx_t]) ans = s[idx_s] - x[i];
        else if(idx_s < A && idx_t < B && s[idx_s] < t[idx_t]) ans = t[idx_t];
        if(idx_s > 0 && idx_t < B){
            ans = min(ans, 2 * (x[i] - s[idx_s-1]) + t[idx_t] - x[i]);
            ans = min(ans, x[i] - s[idx_s-1] + 2 * (t[idx_t] - x[i]));
        }
        if(idx_t > 0 && idx_s < A){
            ans = min(ans, 2 * (s[idx_s] - x[i]) + x[i] - t[idx_t-1]);
            ans = min(ans, s[idx_s] - x[i] + 2 * (x[i] - t[idx_t-1]));
        }
        if(idx_s > 0 && idx_t > 0){
            if(s[idx_s-1] >= t[idx_t-1]) ans = min(ans, x[i] - t[idx_t-1]);
            else ans = min(ans, x[i] - s[idx_s-1]);
        }
        cout << ans << endl;
    }

}
