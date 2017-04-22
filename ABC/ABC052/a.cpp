#include<iostream>
using namespace std;
int main(void){
    int a, b, c, d;
    long long s1, s2;

    cin >> a >> b >> c >> d;
    s1 = a*b;
    s2 = c*d;

    if(s1>=s2) cout << s1 << endl;
    if(s1<s2) cout << s2 << endl;

    

}
