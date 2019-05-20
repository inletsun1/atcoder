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

int x[3];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 0, 3) cin >> x[i];
    sort(x, x + 3);
    if(x[0]%2 == x[1]%2 && x[1]%2 == x[2]%2){
        cout << (x[2] - x[0]) / 2 + (x[2] - x[1]) / 2 << endl;
    }else if(x[0]%2 == x[1]%2 && x[1]%2 != x[2]%2){
        cout << (x[2] - x[0]) / 2 + (x[2] - x[1]) / 2 + 1 << endl;
    }else{
        cout << (x[2] - x[0]) / 2 + (x[2] - x[1]) / 2 + 2 << endl;
    }

}
