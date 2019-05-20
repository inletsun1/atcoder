#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


typedef long long ll;
const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;



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

ll L;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> L;
    ll A[L];
    ll even[L], sums[L];
    LREP(i, 0, L){
        cin >> A[i];
        if(i == 0){
            if(A[i] % 2 == 0) even[i] = 1;
            else even[i] = 0;
        }else if(A[i] % 2 == 0){
            even[i] = even[i-1] + 1;
        }else if(A[i] % 2 == 1){
            even[i] = even[i-1];
        }
        if(i == 0) sums[i] = A[i];
        else sums[i] = min(sums[i-1] + A[i], INF);
    }
    ll ans = INF;
    ll tmp_ans;
    LREP(i, 0, L){
        LREPR(j, L - 1, i){
            if(even[j]-even[i] - 2 >= 0) tmp_ans = even[j] - even[i] - 2;
            else if(even[j]-even[i] == 1) tmp_ans = 0;
            else tmp_ans = 1;

            if(i > 0) tmp_ans += sums[i-1];
            if(j + 1 < L) tmp_ans += sums[L-1] - sums[j + 1];
            ans = min(ans, tmp_ans);
        }
    }

    cout << ans + 1L << endl;
}
