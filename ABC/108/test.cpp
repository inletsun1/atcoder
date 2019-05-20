#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    m = 1 << n;
    int len;
    len = 0;
    while(n > 1){
        len += 1;
        n /= 2;
    }
    cout << "1 << n = " << m << endl;
    cout << "len = " << len << endl;
}
