#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
#define MAXA 100001
int main(){
    pair< ll, ll> A[MAXA];
    for(ll i=0; i<MAXA; i++){
        A[i].first = 0;
        A[i].second = 0;
    }
    ll H, W, D;
    cin >> H >> W >> D;
    ll x, y, tmp_A;
    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            cin >> tmp_A; 
            A[tmp_A].first = i;
            A[tmp_A].second = j;
        }
    }

    ll Q, tmp_L, tmp_R, n, ans, tmp_x, tmp_y, tmp_i, tmp_j;
    cin >> Q;
    for(ll q=0; q<Q; q++){
        cin >> tmp_L >> tmp_R; 
        ans = 0;
        tmp_x = A[tmp_L].first;
        tmp_y = A[tmp_L].second;
        n = (tmp_R-tmp_L)/D ;
        for(ll i=1; i<=n; i++){
           tmp_i = A[tmp_L+i*D].first;
           tmp_j = A[tmp_L+i*D].second;
           ans += abs(tmp_x-tmp_i) + abs(tmp_y-tmp_j);
           tmp_x = tmp_i;
           tmp_y = tmp_j;
        }
        cout << ans << endl;
    }

}
