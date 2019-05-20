#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)


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
//---------------//

int H, W;
bool s[52][52];

bool isNeibor(int h, int j){
    if(s[h-1][j] || s[h+1][j] || s[h][j-1] || s[h][j+1]) return true;
    else return false;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    char tmp;
    REP(i, 0, H + 2){
        REP(j, 0, W + 1) s[i][j] = false;
    }
    REP(i, 1, H + 1){
        REP(j, 1, W + 1){
            cin >> tmp;
            if(tmp == '#') s[i][j] = true;
        }
    }

    bool flag = true;
    REP(i, 1, H + 1){
        if(!flag) break;
        REP(j, 1, W + 1){
            if(s[i][j] && !isNeibor(i, j)){
                flag = false; 
                break;
            } 
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
