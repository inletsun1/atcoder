#include<iostream>
using namespace std;

int N;
bool p[101];
int n[101];

int factorial(int i){
    if(i==0) return 1;
    else return i * factorial(i - 1);
}

int combination(int n, int i){
    return factorial(n) / (factorial(i) * factorial(n - i));
}

int main(){

    cin >> N;

    //search primary numbers
    for(int i = 2; i <= N; i++){
        p[i] = true;
        n[i] = 0;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 2; j < i; j++){
            if(i % j == 0) p[i] = false; continue;
        }
    }


    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= i; j++){
            int tmp = i;
            while(p[j] && (tmp % j == 0)){
                n[j] += 1;
                tmp /= j;
            }
        }
    }


    int m[76];
    int ind[5] = {3-1, 5-1, 15-1, 25-1, 75-1};
    for(int i = 0; i < 5; i++){
        m[ind[i]] = 0;
    }
    for(int i = 2; i<=N; i++){
        for(int j = 0; j < 5; j++){
            if(p[i] && n[i] >= ind[j]){
                m[ind[j]] += 1;
            }
        }
    }

    int ans;
    ans = m[75-1] + \
          m[25-1] * (m[3-1] - 1) + \
          m[15-1] * (m[5-1] - 1) + \
          m[5-1] * (m[5-1] - 1) / 2 * (m[3-1] - 2);

    cout << ans << endl;
}
