#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int N;

int main(){
    cin >> N;
    ll A[N], B[N];
    ll sumA, sumB;
    sumA = 0;
    sumB = 0;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        sumA += A[i];
    }
    for(ll i = 0; i < N; i++){
        cin >> B[i];
        sumB += B[i];
    }

    if(sumA < sumB){
        cout << -1 << endl;
        return 0;
    }

    ll C[N];
    bool isChanged[N];
    ll lenm, lenp;
    for(ll i = 0; i < N; i++){
        C[i] = A[i] - B[i];
        isChanged[i] = false;
    }
    sort(C, C + N);

    ll give_ind = N - 1;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(C[i] >= 0){
            break;
        }
        while(give_ind > 0){
            if(C[give_ind] + C[i] > 0){
                C[give_ind] = C[give_ind] + C[i];
                if(isChanged[give_ind]==false){
                    ans += 1;
                    isChanged[give_ind] = true;
                }
                break;
            }else{
                C[i] = C[give_ind] + C[i];
                if(isChanged[give_ind]==false){
                    ans += 1;
                    isChanged[give_ind] = true;
                }
                give_ind -= 1;
            }
        }
        if(isChanged[i] == false){
            ans += 1;
            isChanged[i] = true;
        }
    }
    cout << ans << endl;
    
}
