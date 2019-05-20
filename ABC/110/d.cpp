#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;
ll M, N;
vector<ll > p;
vector<ll > factorial;

ll square(ll x){
    return (x * x) % mod;
}

ll pow(ll x, ll y){
    if(y == 0) return 1;
    if(y == 1) return x % mod;
    x %= mod;
    if(y % 2 == 1) return (pow(square(x), y/2) * x) % mod;
    else return pow(square(x), y/2) % mod;
}

ll nCr(ll n, ll r){
    ll rev_n = pow(factorial[r], mod - 2);
    ll rev_nr = pow(factorial[n-r], mod - 2);
    ll ans = (((factorial[n] * rev_n) % mod) * rev_nr) % mod;
    return ans;
}


int main(){
    cin >> N >> M;
    for(ll i = 2; i <= (ll) sqrt(M) + 2; i ++){
        bool flag = true;
        for(ll j = 2; j < i; i++){
            if(i % j == 0) flag = false; break;
        }
        if(flag) p.push_back(i);
    }
    vector<ll > ind;
    ll tmp_M = M;
    ll max_ind = 0;
    for(ll i = 0; i < p.size(); i++){
        ll tmp_ind = 0;
        ll tmp_p = p[i];
        while(tmp_M % tmp_p == 0){
            tmp_ind += 1;
            tmp_M /= tmp_p;
        }
        if(tmp_ind > 0){
            //cout << "p: " << tmp_p << ", index: " << tmp_ind << endl;
            if(tmp_ind > max_ind) max_ind = tmp_ind;
            ind.push_back(tmp_ind);
        }
    }
    if(tmp_M > 1) ind.push_back(1);

    factorial.push_back(1);
    for(int i = 1; i <= N + 2 * max_ind; i ++){
        ll next_fact = (factorial[i-1] * (i % mod)) % mod;
        factorial.push_back(next_fact);
    }


    ll ans;
    ans = 1;
    for(ll i = 0; i < ind.size(); i++){
        //cout << ind[i] + N - 1 << "C" << N - 1 << " = " << nCr(ind[i] + N - 1, N - 1) << endl;
        ans *= nCr(ind[i] + N - 1, N - 1);
        ans %= mod;
    }

    ans %= mod;

    cout << ans << endl;

}
