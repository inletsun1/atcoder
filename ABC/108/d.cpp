#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

int L;
int N = 1;


void printPath(int start_edge, int goal_edge){
    cout << start_edge << " " << goal_edge << " " << 0 << endl;
    cout << start_edge << " " << goal_edge << " " << 1 << endl;
}

void f(int l, int tmp_edge){
    cout << "f(" << l << ", " << tmp_edge << ")" << endl;
    int len = 0;
    int tmp_l = l + 1;
    while(tmp_l > 1){
        len += 1;
        tmp_l /= 2;
    }
    cout << "len = " << len << endl;
    bool flag = false;
    if(tmp_edge == 1){
        cout << 1 << " " << 2 << " " << 0 << endl;
        cout << 1 << " " << 2 << " " << 1 << endl;
        flag = true;
        tmp_edge += 1;
        len -= 1;
    }
    if(l == (1 << len) - 1){
        cout << "hoge" << endl;
        for(int i = tmp_edge + 1; i <= tmp_edge + len; i++){
            cout << i - 1 << " " << i << " " << 0 << endl;
            cout << i - 1 << " " << i << " " << (1 << i - tmp_edge) << endl;
        }
    }else{
        f((1 << len) - 1, tmp_edge);
        if(flag) tmp_edge -= 1;
        cout << tmp_edge << " " << N << " " << 0 << endl;
        cout << tmp_edge + len << " " << tmp_edge + len + 1 << " " << 1 << endl;

        if(flag) tmp_edge += 1;
        f(l - ((1 << len)), tmp_edge + len + 1);
    }
}

int main(){
    cin >> L;
    int tmp_L = L - 1;
    while(tmp_L > 0){
        tmp_L /= 2;
        N += 1;
    }
    cout << N << " " << L << endl;
    //cout << "N = " << N << endl;
    f(L - 1, 1);
}
