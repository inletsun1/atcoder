#include<bits/stdc++.h>

#define REP(i, n, m) for(int i = n; i < m; i++)
#define REPR(i, n, m) for(int i = n; i >= m; i--)
#define LREP(i, n, m) for(ll i = n; i < m; i++)
#define LREPR(i, n, m) for(ll i = n; i >= m; i--)

#define INF 1e9 + 1;
#define MOD 1e9 + 7;

typedef long long ll;
//typedef pair<int, int > P;
//typedef pair<ll, ll > LP;

using namespace std;

int n;
int odd[100001], even[100001];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    int v[n];
    REP(i, 0, n){
        cin >> v[i];
    }  
    
    map<int, int > no, ne;
    REP(i, 0, 100001){
        odd[i] = 0;
        even[i] = 0;
    }
    REP(i, 0, n/2) even[v[i*2]] += 1;
    REP(i, 0, n/2) odd[v[i*2 + 1]] += 1;
    int omax = 0;
    int omax_idx = 0;
    int emax = 0;
    int emax_idx = 0;
    int ans = 0;
    REP(i, 0, n/2){
        if(omax < odd[v[i*2 + 1]]){
            omax = odd[v[i*2 + 1]];
            omax_idx = v[i*2 + 1];
        }
        if(emax < even[v[i*2]]){
            emax = even[v[i*2]];
            emax_idx = v[i*2];
        }
    }
    if(omax_idx == emax_idx){
        int omax_rm = omax;
        int emax_rm = emax;
        int omax_rm_idx = omax_idx;
        int emax_rm_idx = emax_idx;
        omax = 0;
        emax = 0;
        REP(i, 0, n/2){
            if(omax < odd[v[i*2 + 1]] && v[i*2+1] != omax_rm_idx){
                omax = odd[v[i*2 + 1]];
                omax_idx = v[i*2 + 1];
            }
            if(emax < even[v[i*2]] && v[i*2] != emax_rm_idx){
                emax = even[v[i*2]];
                emax_idx = v[i*2];
            }
        }
        if(omax_rm > emax_rm){
            omax =  omax_rm;
        }else if(emax_rm > omax_rm){
            emax = emax_rm;
        }else if(omax > emax){
            emax = emax_rm;
        }else{
            omax = omax_rm;
        }
    }

    cout << (n/2 - emax) + (n/2 - omax) << '\n';

}
