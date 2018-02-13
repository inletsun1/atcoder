#include<iostream>
using namespace std;

int main(){
    bool a, b, c;
    a = true;
    b = false;
    c = a || b;
    if(c){
        cout << "c: true" << endl;
    }else{
        cout << "c: false" << endl;
    }

}
