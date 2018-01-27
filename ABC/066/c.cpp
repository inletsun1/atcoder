#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    cin >> N;
    ll a[N];
    for(ll i=0; i<N; i++){
        cin >> a[i];
    }
    if(N%2==1){
        for(ll i=N-1; i>=0; i-=2){
            cout << a[i] << " ";
        }
        for(ll i=1; i<=N-2; i+=2){
            cout << a[i] << " ";
        }
    }else{
        for(ll i=N-1; i>=1; i-=2){
            cout << a[i] << " ";
        }
        for(ll i=0; i<=N-2; i+=2){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
