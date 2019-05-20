#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define P pair<ll, ll >
#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)



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

ll N, M;
ll par[100001], ranks[100001], nums[100001];

void init(ll n){
    LREP(i, 0, n){
        par[i] = i;
        ranks[i] = 0;
        nums[i] = 1;
    }
}
ll find(ll x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

ll unite(ll x, ll y){
    //cout << x << ", " << y << endl;
    //cout << "num[" << x << "]:" << nums[x] << " num[" << y << "]" << nums[y] << endl;
    x = find(x);
    y = find(y);
    if(x == y){
        return nums[x];
    } 
    if(ranks[x] < ranks[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(ranks[x] == ranks[y]) ranks[x] ++;
    }
    nums[x] = nums[x] + nums[y];
    nums[y] = nums[x];
    return nums[x];
}

bool same(ll x, ll y){
    return find(x) == find(y);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector< P> A(M);
    ll a, b;
    for(ll i = 0; i < M; i++){
        cin >> a >> b;
        A[i].first = a - 1;
        A[i].second = b - 1;
    }

    ll ans[M];
    ans[M-1] = N * (N - 1) / 2;

    init(N);
    ll tmp; 
    for(ll i = M - 1; i >= 1; i--){
        tmp = unite(A[i].first, A[i].second);
        //cout << tmp << endl;
        if(tmp == N){
            ans[i-1] = 0;
        }else{
            ans[i-1] = ans[i] + (tmp - 1) * (tmp - 2) / 2 - tmp * (tmp - 1) / 2;
        }
    }

    LREP(i, 0, M) cout <<  ans[i] << endl;
}
