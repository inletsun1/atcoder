#include<iostream>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main(){
    ll ans = 1;
    for(ll i = 1; i <= mod; i++){
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}
