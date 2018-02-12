#include<iostream>
using namespace std;

typedef long long ll;

ll H, W;

ll search(ll H, ll W){
    ll s1, s2, s3, s_max, s_min, tmp;
    tmp = H*W;
    for(ll i=1; i<=H; i++){
        s1 = i*W;
        s2 = (H-i)*(W/2);
        s3 = (H-i)*(W-(W/2));
        s_max = max(s1, s2);
        s_max = max(s_max, s3);
        s_min = min(s1, s2);
        s_min = min(s_min, s3);
        tmp = min(tmp, s_max-s_min);
    }
    return tmp;
}
int main(){
    cin >> H >> W;
    if(H%3==0 || W%3==0){
        cout << 0 << endl;
        return 0;
    }
    ll ans;
    ans = min(W, search(H, W));
    ll ans2;
    ans2 = min(H, search(W, H));
    ans = min(ans, ans2);
    cout << ans << endl;
}
