#include<iostream>
#include<complex>
using namespace std;

typedef long long ll;
ll N;

ll log10(ll n){
    ll ans;
    ans = 1;
    while(n>9){
        ans += 1;
        n/=10;
    }
    return ans;
}
int main(){
    cin >> N;
    ll a, b;
    a = sqrt(N);
    b = N/a;
    ll ans, tmp;
    ans = 10000000001;
    for(ll i=b; i<=N; i++){
        tmp = log10(i);
        if(tmp>ans){
            break;
        }
        if(N%i==0){
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

}
