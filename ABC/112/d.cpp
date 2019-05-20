#include<iostream>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;
    int gMAX = M / N;
    int ans;
    for(int i = gMAX; i >= 1; i--){
        if(M % i == 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
