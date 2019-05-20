#include<iostream>
#include<iomanip>
using namespace std;

typedef long long ll;

int N;
ll D;
int x, y, z;

int main(){
    cin >> N >> D;
    ll hoge = D;
    x = 0; y = 0; z = 0;
    while(hoge % 2 == 0){
        hoge /= 2;
        x += 1;
    }
    while(hoge % 3 == 0){
        hoge /= 3;
        y += 1;
    }
    while(hoge % 5 == 0){
        hoge /= 5;
        z += 1;
    }

    cout << x << y << z << endl;

    double p[x+1][y+1][z+1];
    for(int i = 0; i < x + 1; i++){
        for(int j = 0; j < y + 1; j++){
            for(int k = 0; k < z + 1; k++){
                p[i][j][k] = 0;
            }
        }
    }
    p[0][0][0] = 1/6;
    p[1][0][0] = 1/6;
    p[0][1][0] = 1/6;
    p[2][0][0] = 1/6;
    p[0][0][1] = 1/6;
    p[1][1][0] = 1/6;

    double tmp;
    for(int l = 2; l <= N; l++){
        cout << "n = " << l << endl;
        for(int i = 0; i < x + 1; i++){
            for(int j = 0; j < y + 1; j++){
                for(int k = 0; k < z + 1; k++){
                    cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
                    tmp = p[i][j][k] * 1/6;
                    if(i >= 1) tmp += p[i-1][j][k] * 3/6;
                    if(j >= 1) tmp += p[i][j-1][k] * 2/6;
                    if(k >= 1) tmp += p[i][j][k-1] * 1/6;
                    if(i >= 2) tmp += p[i-2][j][k] * 1/6;
                    if((i >= 1) && (j >= 1)) tmp += p[i-1][j-1][k];
                    p[i][j][k] = tmp;
                }
            }
        }
    }
    for(int i = 0; i < x + 1; i++){
        for(int j = 0; j < y + 1; j++){
            for(int k = 0; k < z + 1; k++){
                cout << setprecision(7) << p[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    cout << setprecision(7) << p[x][y][z] << endl;
}
