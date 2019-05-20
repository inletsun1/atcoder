#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define P pair<int, int >


const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;



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

int N, Q;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    string S;
    cin >> S;
    int l[Q], r[Q], mat[N];
    REP(i, 0, Q){
        cin >> l[i] >> r[i];
        l[i] -= 1;
        r[i] -= 1;
    }
    bool flag = false;
    if(S[0] == 'A') flag = true;
    mat[0] = 0;
    REP(i, 1, N){
        if(flag && S[i] == 'C'){
            mat[i] = mat[i-1] + 1;
            flag = false;
        }else if(S[i] == 'A'){
            flag = true;
            mat[i] = mat[i-1];
        }else{
            flag = false;
            mat[i] = mat[i-1];
        }
    }
    REP(i, 0, Q){
        cout << mat[r[i]] - mat[l[i]] << endl;
    }
}
