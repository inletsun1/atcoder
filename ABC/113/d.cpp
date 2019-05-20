#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;

typedef long long ll;


//---functions---//
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}

bool firstCompare(const P& firstElof, const P& secondElof){
    return firstElof.first < secondElof.first;
}
bool secondCompare(const P& firstElof, const P& secondElof){
    return firstElof.second < secondElof.second;
}
//---------------//

ll H, W, K;
ll a[102][10];

ll f(ll h, ll w){
    if(h == 0){
        if(w == 1) return 1;
        else return 0;
    }
    if((h < 0) || (h > H + 1) || (w < 1) || (w > W)) return 0;
    if(a[h][w] >= 0) return a[h][w];
    if(h == H + 1) return f(h-1, w)%MOD;
    ll X = 0;
    ll Y = 0;
    ll Z = 0;
    for(ll bit = 0; bit < (1<<(W-1)); bit++){
        bool isNotNeibour = true;
        for(ll l = 0; l < (W - 2); l++){
            if((bit & (1 << l)) && (bit & (1 << (l + 1)))){
                isNotNeibour = false;
                break;
            
            }
        }
        if(isNotNeibour){
            if(bit & (1 << (w-2))){
                Y += 1; 
            }else if(bit & (1 << (w-1))){
                Z += 1; 
            }else{
                X += 1; 
            }
        }
    }
    return a[h][w] = (X * f(h-1, w)) % MOD + (Y * f(h-1, w-1)) % MOD + (Z * f(h-1, w+1)) % MOD;
    
}
int main(){
    cin >> H >> W >> K;
    REP(i, 0, H + 2){
        REP(j, 0, W + 2){
            a[i][j] = -1;
        }
    }
    cout << f(H + 1, K) << endl;
}

