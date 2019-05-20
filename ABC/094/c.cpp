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
    return firstElof.second < secondElof.second;
}
//---------------//

int N;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    vector<P > X(N);
    REP(i, 0, N) cin >> X[i].second, X[i].first = i;

    sort(X.begin(), X.end(), secondCompare);

    vector<P > ans(N);
    REP(i, 0, N){
        if(i < N/2){
            ans[i].first = X[i].first;
            ans[i].second = X[N/2].second;
        }else{
            ans[i].first = X[i].first;
            ans[i].second = X[N/2-1].second;
        }
    }
    sort(ans.begin(), ans.end(), firstCompare);
    REP(i, 0, N) cout << ans[i].second << endl;
}
