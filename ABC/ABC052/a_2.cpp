#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int a,b,c,d;
    long long s1,s2;

    cin >> a >> b >> c >> d ;
    s1 = a*b;
    s2 = c*d;
    cout << max(s1, s2) << endl;

}
