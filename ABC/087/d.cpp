#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;

#define BLACK false
#define WHITE true 

const ll MAX = 1000000;
const ll INF = 1000000;
ll N, M;
vector<pair<ll, ll > > g[MAX];
bool color[MAX];
ll w[MAX];

bool dfs(ll tmp, ll pos){
    if(color[tmp]){
        color[tmp] = BLACK;
        w[tmp] = pos;
        vector<pair<ll, ll > >  next;
        next = g[tmp];
        for(ll i=0; i<next.size(); i++){
            pair<ll, ll > next_p = next[i];
            ll next_edge = next_p.first;
            ll next_d = next_p.second;
            if(!dfs(next_edge, next_d + pos)){
                return false;
            }
        }
    }else if(w[tmp]!=INF && w[tmp]!=pos){
        return false;
    }
    return true;
}
int main(){
    cin >> N >>  M;
    ll l, r, d;
    for(ll i=0; i<M; i++){
        cin >> l >> r >> d;
        l--; r--;
        g[l].push_back(make_pair(r, d));
        g[r].push_back(make_pair(l, -d));
    }
    for(ll i=0; i<N; i++){
        color[i] = WHITE;
        w[i] = INF;
    }

    bool flag;
    flag = true;
    for(ll i=0; i<N && flag; i++){
        if(color[i]){
            flag = dfs(i, 0);
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
