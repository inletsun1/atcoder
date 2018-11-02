#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
#define MAXA 200001
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

    ll Q, tmp_L, tmp_R;
    cin >> Q;
    ll d[MAXA];
    for(ll i=1; i<=D; i++){
        d[i] = 0;
        ll E = (H*W+1)/D;
        for(ll j=1; j<=E; j++){
            d[i+j*D] = d[i+(j-1)*D] + abs(A[i+j*D].first-A[i+(j-1)*D].first) + abs(A[i+j*D].second - A[i+(j-1)*D].second);
        }
    }
    for(ll q=0; q<Q; q++){
        cin >> tmp_L >> tmp_R; 
        cout << d[tmp_R]-d[tmp_L] << endl;
    }

}
