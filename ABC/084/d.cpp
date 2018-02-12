#include<iostream>
using namespace std;

typedef long long ll;

bool prime[1000000];
ll likenum[1000000];
ll Q;

void eratos(ll n){
    if(n==0 || n==1){
        prime[n] = false;
    }
    for(ll i=2; i<=n; i++){
        if(prime[i]){
            ll j= 2*i;
            while(j<=n){
                prime[j] = false;
                j += i;
            }
        }
        if(prime[(i+1)/2] && prime[i] && i>2){
                likenum[i] = likenum[i-1]+1;
            }else{
                likenum[i] = likenum[i-1];
            }
    }

}
int main(){
    cin >> Q;
    ll l[Q], r[Q];
    ll max_r;
    max_r = 0;
    for(ll i=0; i<Q; i++){
        cin >> l[i] >> r[i];
        max_r = max(max_r, r[i]);
    }
    for(ll i=0; i<=max_r; i++){
        prime[i] = true;
        likenum[i] = 0;
    }
    eratos(max_r);
    for(ll i=0; i<Q; i++){
        cout << likenum[r[i]] - likenum[l[i]-1] << endl;
    }
}
