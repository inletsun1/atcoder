#include<bits/stdc++.h>
using namespace std;

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define INF 1e9 + 1;
#define MOD 1e9 + 7;


//#define int long long;
//typedef long long ll;


//functions 
int gcd(int a, int b){
    if(a < b) swap(a, b);
    return b?gcd(b, a%b):a;
}

int s2i(string num){stringstream ss; ss << num << flush; int n; ss >> n; return n;}
string i2s(int n){stringstream ss; ss << n << flush; return ss.str();}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string S;

    cin >> S;
    int K;
    cin >> K;
    string ans = "1";
    REP(i, 0, S.size()){
        if(S[i] == '1'){
            K -= 1;
            if(K == 0) break;
        }else{
            ans = S[i];
            break;
        }
    }
    cout << ans << endl;
}
