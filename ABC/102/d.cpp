#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int L, N, M;
    cin >> L;
    int L_bitlen = 0;
    int i = L - 1;
    while(i > 0){
        i /= 2;
        L_bitlen += 1;
    }
    cout << bitset<8> (L - 1) << endl;
    N = L_bitlen + 1;
    cout << "N = " << N << endl;
}
