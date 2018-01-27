#include<iostream>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    ll a, odd, two, four;
    odd = 0;
    two = 0;
    four = 0;
    for(ll i=0; i<N; i++){
        cin >> a;
        if(a%4==0){
            four += 1;
        }else if(a%2==0){
            two += 1;
        }else{
            odd += 1;
        }
    }

    if(four>=odd){
        cout << "Yes" << endl;
    }else if(four==odd-1 && two==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
