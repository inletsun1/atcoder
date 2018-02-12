#include<iostream>
#include<cmath>

using namespace std;

#define ll long long int
ll X, Y;

ll num_divided(ll n){
    ll num = 0;
    ll iter;
    double nd;
    nd = n;
    iter = sqrt(nd+1e-9);
    for(ll i=2; i <= iter; i++){
        if (n%i == 0){
            num += 2;
        }
        
    }
    cout << "num = ";
    cout << num << endl;
    return num;
}
int main(){
    cin >> X >> Y;
    ll n;
    n = Y/X;
    ll ans;
    ans = 1;
    cout << "n = " << endl;
    cout << n << endl;
    
    for(ll i=n; i>=n-10; i--){
        ans = max(ans, num_divided(i)+1);
    }
    cout << ans << endl;
    
}

