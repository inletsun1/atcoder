#include<iostream>
#include<set>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

ll N;
int main(){
    cin >> N;
    set<ll > s;
    ll t;
    for(ll i=0; i<N; i++){
        cin >> t;
        s.insert(t);
    }

    set<ll >::reverse_iterator iter;
    ll a, b, ans;
    iter = s.rbegin();
    a = *iter;
    iter ++;
    b = *iter;
    ans = lcm(a, b);
    iter ++;
    for(iter; iter!=s.rend(); iter++){
        ans = lcm(ans, *iter);
    }

    cout << ans << endl;

}
