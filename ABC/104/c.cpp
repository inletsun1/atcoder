#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;

//#define int long long
typedef long long ll;


//functions 
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}

ll D, G;
signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> D >> G;
    ll p[D], c[D];
    ll ans = INF;
    ll tmp_ans;
    ll score;
    REP(i, 0, D) cin >> p[i] >> c[i];

    REP(i, 0, 1 << D){
        //cout << bitset<10>(i) << endl;
        score = 0;
        tmp_ans = 0;
        //cout << "完答問題:";
        REP(j, 0, D){
            if(i & 1<<j) {
                score += p[j] * (j + 1) * 100 + c[j];
                tmp_ans += p[j];
                //cout << j;
            }
        }
        //cout << endl;
        //cout << "score = " << score << endl;
        if(score >= G){
            //cout << "問題数" << tmp_ans << endl;
            ans = min(ans, tmp_ans);
        }else{
            ll num_added;
            REPR(j, D-1, 0){
                if(!(i & 1<<j)){
                    num_added = ((G-score)%2==0 ? (G-score)/((j +1)*100):(G-score)/((j + 1)*100) + 1);
                    if(p[j] > num_added && score + num_added * (j + 1) * 100 >= G){
                        tmp_ans += num_added;
                        ans = min(ans, tmp_ans);
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
