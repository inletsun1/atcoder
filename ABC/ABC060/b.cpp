#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;

    int a_mod_b = a%b;

    int res;
    int i=1;
    while(true){
        res = (i*a_mod_b)%b;
        if(res==c){
            cout << "YES" << "\n";
            break;
        }
        if((res==a_mod_b)&(i>1)){
            cout << "NO" << "\n";
            break;
        }
        i += 1;
    }

}
