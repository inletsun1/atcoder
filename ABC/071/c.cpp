#include<iostream>
#include<map>

typedef long long ll;
using namespace std;

int N;

int main(){
    cin >> N;
    map<ll, ll > m;
    ll stick[2];
    stick[0] = 0;
    stick[1] = 0;
    ll a;
    for(ll i=0; i<N; i++){
        cin >> a;
        m[a] += 1;
        if((m[a]>=2) && (m[a]%2==0)){
            if(stick[1]<=a){
                stick[0] = stick[1];
                stick[1] = a;
            }else if(stick[1]>a && stick[0]<=a){
                stick[0] = a;
            }
        }
    }
    cout << stick[0]*stick[1] << endl;
}
